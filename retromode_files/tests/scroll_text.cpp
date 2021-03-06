#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/layers.h>
#include <proto/retroMode.h>


#include "../libbase.h"

int scrolled_x;
int scroll_speed = 2;
int scroll_char = 0;

const char *scroll_text = "Small scroll text demo..... have fun playing with this thing..... ";

#define IDCMP_COMMON IDCMP_MOUSEBUTTONS | IDCMP_INACTIVEWINDOW | IDCMP_ACTIVEWINDOW  | \
	IDCMP_CHANGEWINDOW | IDCMP_MOUSEMOVE | IDCMP_REFRESHWINDOW | IDCMP_RAWKEY | \
	IDCMP_EXTENDEDMOUSE | IDCMP_CLOSEWINDOW | IDCMP_NEWSIZE | IDCMP_INTUITICKS

struct Window *My_Window = NULL;
struct retroVideo *video = NULL;
struct retroEngine *engine = NULL;

struct Library * IntuitionBase = NULL;
struct IntuitionIFace *IIntuition = NULL;

struct Library * GraphicsBase = NULL;
struct GraphicsIFace *IGraphics = NULL;

struct Library * RetroModeBase = NULL;
struct RetroModeIFace *IRetroMode = NULL;

struct Library * LayersBase = NULL;
struct LayersIFace *ILayers = NULL;


struct XYSTW_Vertex3D { 
float x, y; 
float s, t, w; 
}; 

typedef struct CompositeHookData_s {
	struct BitMap *srcBitMap; // The source bitmap
	int32 srcWidth, srcHeight; // The source dimensions
	int32 offsetX, offsetY; // The offsets to the destination area relative to the window's origin
	int32 scaleX, scaleY; // The scale factors
	uint32 retCode; // The return code from CompositeTags()
} CompositeHookData;

#ifdef amigaos4
void draw_comp_bitmap(struct BitMap *the_bitmap,struct BitMap *the_bitmap_dest, int width,int height, int wx,int wy,int ww, int wh)
{
	#define STEP(a,xx,yy,ss,tt,ww)   P[a].x= xx; P[a].y= yy; P[a].s= ss; P[a].t= tt; P[a].w= ww;  

	int error;
	struct XYSTW_Vertex3D P[6];

	STEP(0, wx, wy ,0 ,0 ,1);
	STEP(1, wx+ww,wy,width,0,1);
	STEP(2, wx+ww,wy+wh,width,height,1);

	STEP(3, wx,wy, 0,0,1);
	STEP(4, wx+ww,wy+wh,width,height,1);
	STEP(5, wx, wy+wh ,0 ,height ,1);

	if (the_bitmap)
	{

		error = CompositeTags(COMPOSITE_Src, 
			the_bitmap, the_bitmap_dest,

			COMPTAG_VertexArray, P, 
			COMPTAG_VertexFormat,COMPVF_STW0_Present,
		    	COMPTAG_NumTriangles,2,

			COMPTAG_SrcAlpha, (uint32) (0x0010000 ),
			COMPTAG_Flags, COMPFLAG_SrcAlphaOverride | COMPFLAG_HardwareOnly | COMPFLAG_SrcFilter ,
			TAG_DONE);
	}
}
#endif


static ULONG compositeHookFunc(struct Hook *hook, struct RastPort *rastPort, struct BackFillMessage *msg) {

	struct Window *the_win = engine -> window;	

#ifdef amigaos4

	draw_comp_bitmap(engine->rp.BitMap, the_win->RPort -> BitMap, video -> width, video -> height,
		the_win->BorderLeft ,
		the_win->BorderTop ,
		the_win->Width - the_win->BorderLeft - the_win->BorderRight,
		the_win->Height -  the_win->BorderTop - the_win->BorderBottom);

#endif

	return 0;
}

static CompositeHookData hookData;

static struct Rectangle rect;
static struct Hook hook;

static void set_target_hookData( void )
{
 	rect.MinX = My_Window->BorderLeft;
 	rect.MinY = My_Window->BorderTop;
 	rect.MaxX = My_Window->Width - My_Window->BorderRight - 1;
 	rect.MaxY = My_Window->Height - My_Window->BorderBottom - 1;

 	float destWidth = rect.MaxX - rect.MinX + 1;
 	float destHeight = rect.MaxY - rect.MinY + 1;
 	float scaleX = (destWidth + 0.5f) / (double) video -> width;
 	float scaleY = (destHeight + 0.5f) / (double) video -> height;

	hookData.srcWidth = video -> width;
	hookData.srcHeight = video -> height;
	hookData.offsetX = My_Window->BorderLeft;
	hookData.offsetY = My_Window->BorderTop;
	hookData.scaleX = COMP_FLOAT_TO_FIX(scaleX);
	hookData.scaleY = COMP_FLOAT_TO_FIX(scaleY);
	hookData.retCode = COMPERR_Success;

	hook.h_Entry = (HOOKFUNC)compositeHookFunc;
	hook.h_Data = &hookData;
}

static void BackFill_Func(struct RastPort *ArgRP, struct BackFillArgs *MyArgs)
{
	set_target_hookData();

//	LockLayer(0,video -> window -> RPort -> Layer);
	DoHookClipRects(&hook, My_Window -> RPort, &rect);
//	UnlockLayer(video -> window -> RPort -> Layer);
}


BOOL open_lib( const char *name, int ver , const char *iname, int iver, struct Library **base, struct Interface **interface)
{
	*interface = NULL;
	*base = OpenLibrary( name , ver);
	if (*base)
	{
		 *interface = GetInterface( *base,  iname , iver, TAG_END );
		if (!*interface) printf("Unable to getInterface %s for %s %ld!\n",iname,name,ver);
	}
	else
	{
	   	printf("Unable to open the %s %ld!\n",name,ver);
	}
	return (*interface) ? TRUE : FALSE;
}



bool open_window( int window_width, int window_height )
{
		My_Window = OpenWindowTags( NULL,

#ifdef __amigaos4__
					WA_Title,         "retroVideo window mode",
#endif
			WA_InnerWidth,      window_width,
			WA_InnerHeight,     window_height,

			WA_SimpleRefresh,		TRUE,
			WA_CloseGadget,     TRUE,
			WA_DepthGadget,     TRUE,

			WA_DragBar,         TRUE,
			WA_Borderless,      FALSE,
			WA_SizeGadget,      TRUE,
			WA_SizeBBottom,	TRUE,

			WA_IDCMP,           IDCMP_COMMON,
			WA_Flags,           WFLG_REPORTMOUSE,
			TAG_DONE);

	return (My_Window != NULL) ;
}


bool init()
{
	if ( ! open_lib( "intuition.library", 51L , "main", 1, &IntuitionBase, (struct Interface **) &IIntuition  ) ) return FALSE;
	if ( ! open_lib( "graphics.library", 54L , "main", 1, &GraphicsBase, (struct Interface **) &IGraphics  ) ) return FALSE;
	if ( ! open_lib( "layers.library", 54L , "main", 1, &LayersBase, (struct Interface **) &ILayers  ) ) return FALSE;
	if ( ! open_lib( "retromode.library", 1L , "main", 1, &RetroModeBase, (struct Interface **) &IRetroMode  ) ) return FALSE;

	if ( ! open_window(640,480) ) return false;

	if ( (video = retroAllocVideo( 640,480 )) == NULL ) return false;
	if ( (engine = retroAllocEngine(My_Window, video)) == NULL ) return false;

	return TRUE;
}

void closedown()
{
	if (engine) retroFreeEngine(engine); engine = NULL;
	if (My_Window) CloseWindow(My_Window);

	if (IntuitionBase) CloseLibrary(IntuitionBase); IntuitionBase = 0;
	if (IIntuition) DropInterface((struct Interface*) IIntuition); IIntuition = 0;

	if (LayersBase) CloseLibrary(LayersBase); LayersBase = 0;
	if (ILayers) DropInterface((struct Interface*) ILayers); ILayers = 0;

	if (GraphicsBase) CloseLibrary(GraphicsBase); GraphicsBase = 0;
	if (IGraphics) DropInterface((struct Interface*) IGraphics); IGraphics = 0;

	if (RetroModeBase) CloseLibrary(RetroModeBase); RetroModeBase = 0;
	if (IRetroMode) DropInterface((struct Interface*) IRetroMode); IRetroMode = 0;
}


int main()
{
	struct retroScreen *screen = NULL;
	struct retroScreen *screen2 = NULL;
	struct retroScreen *screen3 = NULL;
	struct RastPort scroll_rp;

	struct IntuiMessage *msg;
	bool running = true;

	retroRGB color;
	double p = 0;
	APTR lock;
	ULONG BitMapBytesPerRow;
	unsigned char *BitMapMemory;


	if (init())		// libs open her.
	{


		InitRastPort(&scroll_rp);
		scroll_rp.BitMap = AllocBitMapTags( 320, 200, 256, 
				BMATags_PixelFormat, PIXF_CLUT, 
				BMATags_Clear, true,
				BMATags_Displayable, false,
				TAG_END);

		scroll_rp.Font =  My_Window -> RPort -> Font;
		SetBPen( &scroll_rp, 0 );

		retroClearVideo(video, 0x000000 );
		
		retroSetRainbow( video, 0, 0, 400 );
		retroRainbow( video, 0, 0, 120, 150 );

		retroRainbowColorRange( video, 0, 	0 , 255, 0, 0, 100, 0, 0, 255 );
		retroRainbowColorRange( video, 0, 100 , 0, 0, 255,200, 255, 0, 0 );
		retroRainbowColorRange( video, 0, 200 , 255, 0, 0, 300, 0, 255, 0 );
		retroRainbowColorRange( video, 0, 300 , 0, 255, 0, 400, 255, 0, 0 );

		screen = retroOpenScreen(640,200,retroLowres);
		screen2 = retroScreenClone(screen, retroHires);
		screen3 = retroScreenClone(screen, retroHires | retroInterlaced);


		if (screen)
		{
			int x;

			retroScreenColor( screen, 0, 255, 100, 50 );
			retroScreenColor( screen, 1, 255, 0, 0 );
			retroScreenColor( screen, 2, 0, 0, 255 );

			for (x=0;x<10;x++)
			{
				retroBAR( screen,0, 10 + (x*100),10,50+ (x*100), 50, 1 );
				retroBAR( screen,0,30 + (x*100),20,70+ (x*100), 60, 2 );
			}
		}

		if (screen2)
		{
			int x;

			retroScreenColor( screen2, 0, 0, 0, 100 );
			retroScreenColor( screen2, 1, 255, 0, 0 );
			retroScreenColor( screen2, 2, 0, 0, 255 );

			retroScreenColor( screen2, 4, 255, 255, 255 );
			retroScreenColor( screen2, 5, 100, 0, 0 );
			retroScreenColor( screen2, 6, 0, 0, 100 );

			for (x=0;x<10;x++)
			{
				retroBAR( screen2,0, 10 +(x*100), 10, 50+(x*100), 50, 1 );
				retroBAR( screen2,0, 40 +(x*100), 20, 80+(x*100), 60, 2 );
			}
		}

		if (screen3)
		{
			retroScreenColor( screen3, 0, 0, 0, 100 );
			retroScreenColor( screen3, 1, 255, 0, 0 );
			retroScreenColor( screen3, 2, 0, 0, 255 );

			retroBAR( screen3,0, 10,10,50, 50, 1 );
			retroBAR( screen3,0, 20,20,60, 60, 2 );
		}

		if (screen)	retroApplyScreen( screen, video, 0, 0,320,200 );
		if (screen2)	retroApplyScreen( screen2, video, 0, 150,640,200 );
		if (screen3)	retroApplyScreen( screen3, video, 0, 300,320,200 );

		while (running)
		{
			while (msg = (IntuiMessage *) GetMsg( My_Window -> UserPort) )
			{
				if (msg -> Class == IDCMP_CLOSEWINDOW) running = false;
				ReplyMsg( (Message*) msg );
			}

			video -> rainbow[0].offset ++;

			scrolled_x+=scroll_speed;			
			
			if (scrolled_x>15)
			{
				SetAPen( &scroll_rp, 4 );
				Move( &scroll_rp, 300,10 );
				Text( &scroll_rp, scroll_text+scroll_char,1 );

				scroll_char = (scroll_char + 1) % strlen(scroll_text) ;	// next char

				scrolled_x = 0;
			}

			ScrollRaster( &scroll_rp, scroll_speed, 0, 0, 0, 320, 200);

			retroAndClear( screen,0, 0,0,screen->realWidth,screen->realHeight, ~4 );

			p = 0;

			retroOrBitmapBlit( scroll_rp.BitMap, 0,0,320,15, screen, 0, 0 , 0);


/*
			lock = LockBitMapTags( scroll_rp.BitMap, LBM_BytesPerRow, &BitMapBytesPerRow,	LBM_BaseAddress, &BitMapMemory,	TAG_END);
			if (lock)
			{
				int x,y;

				for (x=0;x<320;x++)
				{
//					y = sin(p)*10.0f+20.0f;

y= 20;
					_retromode_retroOrBlit( (struct RetroModeIFace* ) IRetroMode, BitMapMemory, BitMapBytesPerRow, scroll_rp.BitMap, x,0,15, screen2, x , y);

					p+=0.05f;
				}

				UnlockBitMap( lock );
			 }
*/

			retroClearVideo( video, 0x000000 );
			retroDrawVideo( video );
			retroDmaVideo(video,engine);

			WaitTOF();
			BackFill_Func(NULL, NULL );

		}

		retroCloseScreen(&screen2);
		retroCloseScreen(&screen3);
		retroCloseScreen(&screen);

		if (scroll_rp.BitMap) FreeBitMap(scroll_rp.BitMap);

		retroFreeVideo(video);
	}


#ifdef amigaos4
	closedown();
#endif

	return 0;
}

