#ifndef INLINE4_RETROMODE_H
#define INLINE4_RETROMODE_H

/*
** This file was auto generated by idltool 53.6.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
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
#include <interfaces/retromode.h>

/* Inline macros for Interface "main" */
#define retroAllocEngine(window, video) IRetroMode->retroAllocEngine((window), (video)) 
#define retroAllocVideo(width, height) IRetroMode->retroAllocVideo((width), (height)) 
#define retroFreeVideo(video) IRetroMode->retroFreeVideo((video)) 
#define retroFreeEngine(engine) IRetroMode->retroFreeEngine((engine)) 
#define retroClearVideo(video, color) IRetroMode->retroClearVideo((video), (color)) 
#define retroDrawVideo(video) IRetroMode->retroDrawVideo((video)) 
#define retroDmaVideo(video, engine) IRetroMode->retroDmaVideo((video), (engine)) 
#define retroOpenScreen(width, height, videomode) IRetroMode->retroOpenScreen((width), (height), (videomode)) 
#define retroCloseScreen(screen) IRetroMode->retroCloseScreen((screen)) 
#define retroApplyScreen(screen, video, scanlinex, scanliney, displayWidth, displayHeight) IRetroMode->retroApplyScreen((screen), (video), (scanlinex), (scanliney), (displayWidth), (displayHeight)) 
#define retroPixel(screen, memory, x, y, color) IRetroMode->retroPixel((screen), (memory), (x), (y), (color)) 
#define retroPoint(screen, x, y) IRetroMode->retroPoint((screen), (x), (y)) 
#define retroFlash(screen, color, data) IRetroMode->retroFlash((screen), (color), (data)) 
#define retroCycleColorsUp(screen, delay, from_color, to_color, flags) IRetroMode->retroCycleColorsUp((screen), (delay), (from_color), (to_color), (flags)) 
#define retroCycleColorsDown(screen, delay, from_color, to_color, flags) IRetroMode->retroCycleColorsDown((screen), (delay), (from_color), (to_color), (flags)) 
#define retroBAR(screen, buffer, x0, y0, x1, y1, color) IRetroMode->retroBAR((screen), (buffer), (x0), (y0), (x1), (y1), (color)) 
#define retroOrBAR(screen, buffer, x0, y0, x1, y1, or_mask) IRetroMode->retroOrBAR((screen), (buffer), (x0), (y0), (x1), (y1), (or_mask)) 
#define retroXorBAR(screen, buffer, x0, y0, x1, y1, xor_mask) IRetroMode->retroXorBAR((screen), (buffer), (x0), (y0), (x1), (y1), (xor_mask)) 
#define retroBarPattern(screen, buffer, x0, y0, x1, y1, sprite, image, ink0, ink1) IRetroMode->retroBarPattern((screen), (buffer), (x0), (y0), (x1), (y1), (sprite), (image), (ink0), (ink1)) 
#define retroBox(screen, buffer, x0, y0, x1, y1, color) IRetroMode->retroBox((screen), (buffer), (x0), (y0), (x1), (y1), (color)) 
#define retroOrBox(screen, buffer, x0, y0, x1, y1, or_mask) IRetroMode->retroOrBox((screen), (buffer), (x0), (y0), (x1), (y1), (or_mask)) 
#define retroXorBox(screen, buffer, x0, y0, x1, y1, xor_mask) IRetroMode->retroXorBox((screen), (buffer), (x0), (y0), (x1), (y1), (xor_mask)) 
#define retroShift(screen, buffer, x0, y0, x1, y1, bits) IRetroMode->retroShift((screen), (buffer), (x0), (y0), (x1), (y1), (bits)) 
#define retroCircleFilled(screen, buffer, cx, cy, r, color) IRetroMode->retroCircleFilled((screen), (buffer), (cx), (cy), (r), (color)) 
#define retroEllipse(screen, buffer, cx, cy, r1, r2, angel, color) IRetroMode->retroEllipse((screen), (buffer), (cx), (cy), (r1), (r2), (angel), (color)) 
#define retroOrCircleFilled(screen, buffer, cx, cy, r, or_mask) IRetroMode->retroOrCircleFilled((screen), (buffer), (cx), (cy), (r), (or_mask)) 
#define retroXorCircleFilled(screen, buffer, cx, cy, r, xor_mask) IRetroMode->retroXorCircleFilled((screen), (buffer), (cx), (cy), (r), (xor_mask)) 
#define retroScreenColor(screen, color, r, g, b) IRetroMode->retroScreenColor((screen), (color), (r), (g), (b)) 
#define retroScreenBlit(SourceScreen, fromBuffer, fromX, fromY, width, height, screen, toBuffer, toX, toY) IRetroMode->retroScreenBlit((SourceScreen), (fromBuffer), (fromX), (fromY), (width), (height), (screen), (toBuffer), (toX), (toY)) 
#define retroOrScreenBlit(SourceScreen, fromMode, fromX, fromY, width, height, screen, toMode, toX, toY) IRetroMode->retroOrScreenBlit((SourceScreen), (fromMode), (fromX), (fromY), (width), (height), (screen), (toMode), (toX), (toY)) 
#define retroXorScreenBlit(SourceScreen, fromMode, fromX, fromY, width, height, screen, toMode, toX, toY) IRetroMode->retroXorScreenBlit((SourceScreen), (fromMode), (fromX), (fromY), (width), (height), (screen), (toMode), (toX), (toY)) 
#define retroBitmapBlit(bitmap, fromX, fromY, width, height, screen, buffer, toX, toY) IRetroMode->retroBitmapBlit((bitmap), (fromX), (fromY), (width), (height), (screen), (buffer), (toX), (toY)) 
#define retroOrBitmapBlit(bitmap, fromX, fromY, width, height, screen, buffer, toX, toY) IRetroMode->retroOrBitmapBlit((bitmap), (fromX), (fromY), (width), (height), (screen), (buffer), (toX), (toY)) 
#define retroXorBitmapBlit(bitmap, fromX, fromY, width, height, screen, buffer, toX, toY) IRetroMode->retroXorBitmapBlit((bitmap), (fromX), (fromY), (width), (height), (screen), (buffer), (toX), (toY)) 
#define retroAndClear(screen, buffer, x0, y0, x1, y1, and_mask) IRetroMode->retroAndClear((screen), (buffer), (x0), (y0), (x1), (y1), (and_mask)) 
#define retroModeBadVideoSync(video, sync_offset, incRad, r) IRetroMode->retroModeBadVideoSync((video), (sync_offset), (incRad), (r)) 
#define AfterEffectScanline(video) IRetroMode->AfterEffectScanline((video)) 
#define AfterEffectAdjustRGB(video, red_shift, green_shift, blue_shift) IRetroMode->AfterEffectAdjustRGB((video), (red_shift), (green_shift), (blue_shift)) 
#define retroTriangle(screen, x1, y1, x2, y2, x3, y3, color) IRetroMode->retroTriangle((screen), (x1), (y1), (x2), (y2), (x3), (y3), (color)) 
#define retroOrTriangle(screen, x1, y1, x2, y2, x3, y3, or_color) IRetroMode->retroOrTriangle((screen), (x1), (y1), (x2), (y2), (x3), (y3), (or_color)) 
#define retroXorTriangle(screen, x1, y1, x2, y2, x3, y3, xor_color) IRetroMode->retroXorTriangle((screen), (x1), (y1), (x2), (y2), (x3), (y3), (xor_color)) 
#define retroLine(screen, buffer, x1, y1, x2, y2, color) IRetroMode->retroLine((screen), (buffer), (x1), (y1), (x2), (y2), (color)) 
#define retroOrLine(screen, buffer, x1, y1, x2, y2, color) IRetroMode->retroOrLine((screen), (buffer), (x1), (y1), (x2), (y2), (color)) 
#define retroXorLine(screen, buffer, x1, y1, x2, y2, color) IRetroMode->retroXorLine((screen), (buffer), (x1), (y1), (x2), (y2), (color)) 
#define retroAllocFrame(screen, buffer, x1, y1, x2, y2, hotspotX, hotspotY) IRetroMode->retroAllocFrame((screen), (buffer), (x1), (y1), (x2), (y2), (hotspotX), (hotspotY)) 
#define retroFreeFrame(frame) IRetroMode->retroFreeFrame((frame)) 
#define retroDrawFrame(frame, screen, X, Y) IRetroMode->retroDrawFrame((frame), (screen), (X), (Y)) 
#define retroDeleteFlash(screen, color) IRetroMode->retroDeleteFlash((screen), (color)) 
#define retroScreenOffset(screen, offsetx, offsety) IRetroMode->retroScreenOffset((screen), (offsetx), (offsety)) 
#define retroScreenDetach(screen) IRetroMode->retroScreenDetach((screen)) 
#define retroScreenToFront(screen) IRetroMode->retroScreenToFront((screen)) 
#define retroScreenToBack(screen) IRetroMode->retroScreenToBack((screen)) 
#define retroStar(screen, buffer, x, y, n, r0, r1, g, color) IRetroMode->retroStar((screen), (buffer), (x), (y), (n), (r0), (r1), (g), (color)) 
#define retroOrStar(screen, buffer, x, y, n, r0, r1, g, color) IRetroMode->retroOrStar((screen), (buffer), (x), (y), (n), (r0), (r1), (g), (color)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define retroPolyLine(screen, ...) IRetroMode->retroPolyLine((screen), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define retroPolyLine(screen, vargs...) IRetroMode->retroPolyLine(screen, ## vargs) 
#endif
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define retroPolyGon(screen, ...) IRetroMode->retroPolyGon((screen), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define retroPolyGon(screen, vargs...) IRetroMode->retroPolyGon(screen, ## vargs) 
#endif
#define retroBoing(screen, buffer, x, y, r0, r1, color0, color1) IRetroMode->retroBoing((screen), (buffer), (x), (y), (r0), (r1), (color0), (color1)) 
#define retroLoadABKSprite(filename) IRetroMode->retroLoadABKSprite((filename)) 
#define retroFreeSprite(sprite) IRetroMode->retroFreeSprite((sprite)) 
#define retroPasteSprite(screen, buffer, sprite, x, y, image, flags, mask) IRetroMode->retroPasteSprite((screen), (buffer), (sprite), (x), (y), (image), (flags), (mask)) 
#define retroFill(screen, buffer, x, y, color) IRetroMode->retroFill((screen), (buffer), (x), (y), (color)) 
#define retroOrFill(screen, buffer, x, y, and_mask, or_color) IRetroMode->retroOrFill((screen), (buffer), (x), (y), (and_mask), (or_color)) 
#define retroBarRounded(screen, buffer, x0, y0, x1, y1, r, color) IRetroMode->retroBarRounded((screen), (buffer), (x0), (y0), (x1), (y1), (r), (color)) 
#define retroOrBarRounded(screen, buffer, x0, y0, x1, y1, r, color) IRetroMode->retroOrBarRounded((screen), (buffer), (x0), (y0), (x1), (y1), (r), (color)) 
#define retroXorBarRounded(screen, buffer, x0, y0, x1, y1, r, color) IRetroMode->retroXorBarRounded((screen), (buffer), (x0), (y0), (x1), (y1), (r), (color)) 
#define retroThickLine(screen, buffer, x0, y0, x1, y1, thickness, color) IRetroMode->retroThickLine((screen), (buffer), (x0), (y0), (x1), (y1), (thickness), (color)) 
#define retroZoom(fromScreen, x0, y0, x1, y1, toScreen, x2, y2, x3, y3) IRetroMode->retroZoom((fromScreen), (x0), (y0), (x1), (y1), (toScreen), (x2), (y2), (x3), (y3)) 
#define retroBobble(fromScreen, fromX, fromY, fromR, toScreen, toX, toY, toR) IRetroMode->retroBobble((fromScreen), (fromX), (fromY), (fromR), (toScreen), (toX), (toY), (toR)) 
#define retroRainbowColorRange(video, rainbowNumber, fromLine, fromR, fromG, fromB, toLine, toR, toG, toB) IRetroMode->retroRainbowColorRange((video), (rainbowNumber), (fromLine), (fromR), (fromG), (fromB), (toLine), (toR), (toG), (toB)) 
#define retroRain(video, rainbowNumber, line, r, g, b) IRetroMode->retroRain((video), (rainbowNumber), (line), (r), (g), (b)) 
#define retroScreenClone(SourceScreen, videomode) IRetroMode->retroScreenClone((SourceScreen), (videomode)) 
#define retroSetRainbow(video, rainbowNumber, color, tableSize) IRetroMode->retroSetRainbow((video), (rainbowNumber), (color), (tableSize)) 
#define retroRainbow(video, rainbowNumber, offset, verticalOffset, height) IRetroMode->retroRainbow((video), (rainbowNumber), (offset), (verticalOffset), (height)) 
#define retroAllocSpriteObjects(video, numberOfSprites) IRetroMode->retroAllocSpriteObjects((video), (numberOfSprites)) 
#define retroFreeSpriteObjects(video) IRetroMode->retroFreeSpriteObjects((video)) 
#define AfterEffectDrawSrpites(video) IRetroMode->AfterEffectDrawSrpites((video)) 
#define retroSprite(video, number, x, y, image) IRetroMode->retroSprite((video), (number), (x), (y), (image)) 
#define retroColorRange(screen, fromColor, fromR, fromG, fromB, toColor, toR, toG, toB) IRetroMode->retroColorRange((screen), (fromColor), (fromR), (fromG), (fromB), (toColor), (toR), (toG), (toB)) 
#define retroPolyGonArray(screen, buffer, color, count, array) IRetroMode->retroPolyGonArray((screen), (buffer), (color), (count), (array)) 
#define retroCycleOff(screen) IRetroMode->retroCycleOff((screen)) 
#define retroFadeScreen(screen) IRetroMode->retroFadeScreen((screen)) 
#define retroCircle(screen, buffer, cx, cy, r, color) IRetroMode->retroCircle((screen), (buffer), (cx), (cy), (r), (color)) 
#define retroAllocDoubleBuffer(screen) IRetroMode->retroAllocDoubleBuffer((screen)) 
#define retroLoadSprite(fd, cust_fread) IRetroMode->retroLoadSprite((fd), (cust_fread)) 
#define retroGetSprite(screen, sprite, image, x0, y0, x1, y1) IRetroMode->retroGetSprite((screen), (sprite), (image), (x0), (y0), (x1), (y1)) 
#define retroFreeSpriteObject(spriteObject, onlyData) IRetroMode->retroFreeSpriteObject((spriteObject), (onlyData)) 
#define retroScreenToBitmap(screen, fromX, fromY, width, height, bitmap, toX, toY) IRetroMode->retroScreenToBitmap((screen), (fromX), (fromY), (width), (height), (bitmap), (toX), (toY)) 
#define retroAllocBlock(width, height) IRetroMode->retroAllocBlock((width), (height)) 
#define retroFreeBlock(block) IRetroMode->retroFreeBlock((block)) 
#define retroGetBlock(screen, buffer, block, x, y) IRetroMode->retroGetBlock((screen), (buffer), (block), (x), (y)) 
#define retroPutBlock(screen, buffer, block, x, y, bitmask) IRetroMode->retroPutBlock((screen), (buffer), (block), (x), (y), (bitmask)) 
#define retroPasteIcon(screen, buffer, sprite, x, y, image) IRetroMode->retroPasteIcon((screen), (buffer), (sprite), (x), (y), (image)) 
#define retroMakeMask(frame) IRetroMode->retroMakeMask((frame)) 
#define retroFreeMask(frame) IRetroMode->retroFreeMask((frame)) 

#endif /* INLINE4_RETROMODE_H */
