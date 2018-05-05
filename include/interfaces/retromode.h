#ifndef RETROMODE_INTERFACE_DEF_H
#define RETROMODE_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef LIBRARIES_RETROMODE_H
#include <libraries/retromode.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct RetroModeIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RetroModeIFace *Self);
	ULONG APICALL (*Release)(struct RetroModeIFace *Self);
	void APICALL (*Expunge)(struct RetroModeIFace *Self);
	struct Interface * APICALL (*Clone)(struct RetroModeIFace *Self);
	struct retroVideo * APICALL (*retroAllocVideo)(struct RetroModeIFace *Self, struct Window * window);
	void APICALL (*retroFreeVideo)(struct RetroModeIFace *Self, struct retroVideo * video);
	void APICALL (*retroClearVideo)(struct RetroModeIFace *Self, struct retroVideo * video);
	void APICALL (*retroDrawVideo)(struct RetroModeIFace *Self, struct retroVideo * video);
	void APICALL (*retroDmaVideo)(struct RetroModeIFace *Self, struct retroVideo * video);
	struct retroScreen * APICALL (*retroOpenScreen)(struct RetroModeIFace *Self, int width, int height, int videomode);
	void APICALL (*retroCloseScreen)(struct RetroModeIFace *Self, struct retroScreen ** screen);
	void APICALL (*retroApplyScreen)(struct RetroModeIFace *Self, struct retroScreen * screen, struct retroVideo * video, int scanlinex, int scanliney, int displayWidth, int displayHeight);
	void APICALL (*retroPixel)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, unsigned char color);
	unsigned char APICALL (*retroPoint)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y);
	void APICALL (*retroFlash)(struct RetroModeIFace *Self, struct retroScreen * screen, unsigned char color, char * data);
	void APICALL (*retroCycleColorsUp)(struct RetroModeIFace *Self, struct retroScreen * screen, int delay, unsigned char from_color, unsigned char to_color, unsigned char flags);
	void APICALL (*retroCycleColorsDown)(struct RetroModeIFace *Self, struct retroScreen * screen, int delay, unsigned char from_color, unsigned char to_color, unsigned char flags);
	void APICALL (*retroBAR)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char color);
	void APICALL (*retroOrBAR)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char or_mask);
	void APICALL (*retroXorBAR)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char xor_mask);
	void APICALL (*retroBox)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char color);
	void APICALL (*retroOrBox)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char or_mask);
	void APICALL (*retroXorBox)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char xor_mask);
	void APICALL (*retroShift)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, int bits);
	void APICALL (*retroCircle)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int r, unsigned char color);
	void APICALL (*retroEllipse)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int r1, int r2, double angel, unsigned char color);
	void APICALL (*retroOrCircle)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int r, unsigned char or_mask);
	void APICALL (*retroXorCircle)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int r, unsigned char xor_mask);
	void APICALL (*retroScreenColor)(struct RetroModeIFace *Self, struct retroScreen * screen, int color, unsigned char r, unsigned char g, unsigned char b);
	void APICALL (*retroScreenBlit)(struct RetroModeIFace *Self, struct retroScreen * SourceScreen, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void APICALL (*retroOrScreenBlit)(struct RetroModeIFace *Self, struct retroScreen * SourceScreen, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void APICALL (*retroXorScreenBlit)(struct RetroModeIFace *Self, struct retroScreen * SourceScreen, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void APICALL (*retroBitmapBlit)(struct RetroModeIFace *Self, struct BitMap * bitmap, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void APICALL (*retroOrBitmapBlit)(struct RetroModeIFace *Self, struct BitMap * bitmap, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void APICALL (*retroXorBitmapBlit)(struct RetroModeIFace *Self, struct BitMap * bitmap, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void APICALL (*retroAndClear)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char and_mask);
	void APICALL (*retroModeBadVideoSync)(struct RetroModeIFace *Self, struct retroVideo * video, double sync_offset, double incRad, double r);
	void APICALL (*AfterEffectScanline)(struct RetroModeIFace *Self, struct retroVideo * video);
	void APICALL (*AfterEffectAdjustRGB)(struct RetroModeIFace *Self, struct retroVideo * video, unsigned int red_shift, unsigned int green_shift, unsigned int blue_shift);
	void APICALL (*retroTriangle)(struct RetroModeIFace *Self, struct retroScreen * screen, int x1, int y1, int x2, int y2, int x3, int y3, unsigned char color);
	void APICALL (*retroOrTriangle)(struct RetroModeIFace *Self, struct retroScreen * screen, int x1, int y1, int x2, int y2, int x3, int y3, unsigned char or_color);
	void APICALL (*retroXorTriangle)(struct RetroModeIFace *Self, struct retroScreen * screen, int x1, int y1, int x2, int y2, int x3, int y3, unsigned char xor_color);
	void APICALL (*retroLine)(struct RetroModeIFace *Self, struct retroScreen * screen, int x1, int y1, int x2, int y2, unsigned char color);
	void APICALL (*retroOrLine)(struct RetroModeIFace *Self, struct retroScreen * screen, int x1, int y1, int x2, int y2, unsigned char color);
	void APICALL (*retroXorLine)(struct RetroModeIFace *Self, struct retroScreen * screen, int x1, int y1, int x2, int y2, unsigned char color);
	struct retroFrame * APICALL (*retroAllocFrame)(struct RetroModeIFace *Self, struct retroScreen * screen, int x1, int y1, int x2, int y2, int hotspotX, int hotspotY);
	void APICALL (*retroFreeFrame)(struct RetroModeIFace *Self, struct retroFrame * frame);
	void APICALL (*retroDrawFrame)(struct RetroModeIFace *Self, struct retroFrame * frame, struct retroScreen * screen, int X, int Y);
	int APICALL (*retroDeleteFlash)(struct RetroModeIFace *Self, struct retroScreen * screen, unsigned char color);
	void APICALL (*retroScreenOffset)(struct RetroModeIFace *Self, struct retroScreen * screen, int offsetx, int offsety);
	void APICALL (*retroScreenDetach)(struct RetroModeIFace *Self, struct retroScreen * screen);
	void APICALL (*retroScreenToFront)(struct RetroModeIFace *Self, struct retroScreen * screen);
	void APICALL (*retroScreenToBack)(struct RetroModeIFace *Self, struct retroScreen * screen);
	void APICALL (*retroStar)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int n, int r0, int r1, double g, unsigned char color);
	void APICALL (*retroOrStar)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int n, int r0, int r1, double g, unsigned char color);
	void APICALL (*retroPolyLine)(struct RetroModeIFace *Self, struct retroScreen * screen, unsigned char color, ...);
	void APICALL (*retroPolyGon)(struct RetroModeIFace *Self, struct retroScreen * screen, unsigned char color, ...);
	void APICALL (*retroBoing)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int r0, int r1, unsigned char color0, unsigned char color1);
	struct retroSprite * APICALL (*retroLoadABKSprite)(struct RetroModeIFace *Self, char * filename);
	void APICALL (*retroFreeSprite)(struct RetroModeIFace *Self, struct retroSprite * sprite);
	void APICALL (*retroPasteSprite)(struct RetroModeIFace *Self, struct retroScreen * screen, struct retroSprite * sprite, int x, int y, int image);
	void APICALL (*retroFill)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, unsigned char color);
	void APICALL (*retroOrFill)(struct RetroModeIFace *Self, struct retroScreen * screen, int x, int y, int and_mask, unsigned char or_color);
	void APICALL (*retroBarRounded)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, int r, unsigned char color);
	void APICALL (*retroOrBarRounded)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, int r, unsigned char color);
	void APICALL (*retroXorBarRounded)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, int r, unsigned char color);
	void APICALL (*retroThickLine)(struct RetroModeIFace *Self, struct retroScreen * screen, int x0, int y0, int x1, int y1, int thickness, unsigned char color);
	void APICALL (*retroZoom)(struct RetroModeIFace *Self, struct retroScreen * fromScreen, int x0, int y0, int x1, int y1, struct retroScreen * toScreen, int x2, int y2, int x3, int y3);
	void APICALL (*retroBobble)(struct RetroModeIFace *Self, struct retroScreen * fromScreen, int fromX, int fromY, int fromR, struct retroScreen * toScreen, int toX, int toY, int toR);
	void APICALL (*retroRainbowColorRange)(struct RetroModeIFace *Self, struct retroVideo * video, int rainbowNumber, int fromLine, int fromR, int fromG, int fromB, int toLine, int toR, int toG, int toB);
	void APICALL (*retroRain)(struct RetroModeIFace *Self, struct retroVideo * video, int rainbowNumber, int line, int r, int g, int b);
	struct retroScreen * APICALL (*retroScreenClone)(struct RetroModeIFace *Self, struct retroScreen * SourceScreen, int videomode);
	struct retroScreen * APICALL (*retroSetRainbow)(struct RetroModeIFace *Self, struct retroVideo * video, int rainbowNumber, unsigned char color, int tableSize);
	struct retroScreen * APICALL (*retroRainbow)(struct RetroModeIFace *Self, struct retroVideo * video, int rainbowNumber, int verticalOffset, int height);
	void APICALL (*retroAllocSpriteObjects)(struct RetroModeIFace *Self, struct retroVideo * video, int numberOfSprites);
	void APICALL (*retroFreeSpriteObjects)(struct RetroModeIFace *Self, struct retroVideo * video);
	void APICALL (*AfterEffectDrawSrpites)(struct RetroModeIFace *Self, struct retroVideo * video);
	void APICALL (*retroSprite)(struct RetroModeIFace *Self, struct retroVideo * video, int number, int x, int y, int image);
	void APICALL (*retroColorRange)(struct RetroModeIFace *Self, struct retroScreen * screen, int fromColor, int fromR, int fromG, int fromB, int toColor, int toR, int toG, int toB);
	void APICALL (*retroPolyGonArray)(struct RetroModeIFace *Self, struct retroScreen * screen, unsigned char color, int count, int * array);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* RETROMODE_INTERFACE_DEF_H */
