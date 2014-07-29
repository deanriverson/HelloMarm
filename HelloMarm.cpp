#include "s3e.h"
#include "IwDebug.h"
#include "IwGx.h"

void drawPaddle(int16 pos) {
    CIwMaterial* pMat = IW_GX_ALLOC_MATERIAL();
    
    // Set this as the active material
    IwGxSetMaterial(pMat);
    
    // Set up screenspace vertex coords
    int16 y1 = (int16)IwGxGetScreenHeight() * 7 / 8;
    
    static CIwSVec2 xy4[4];
    xy4[0].x = pos,     xy4[0].y = y1;
    xy4[1].x = pos,     xy4[1].y = y1+20;
    xy4[2].x = pos+100, xy4[2].y = y1+20;
    xy4[3].x = pos+100, xy4[3].y = y1;
    
    IwGxSetVertStreamScreenSpace(xy4, 4);
    
    // Set up vertex colours
    static CIwColour cols[4] =
    {
        {0x40, 0x60, 0xff},
        {0x30, 0x50, 0xc0},
        {0x30, 0x50, 0xc0},
        {0x40, 0x60, 0xff}
    };
    
    IwGxSetColStream(cols, 4);
    
    // Draw single triangle
    IwGxDrawPrims(IW_GX_QUAD_LIST, NULL, 4);
}

// Main entry point for the application
int main()
{
    //Initialise graphics system(s)
    IwGxInit();
    IwGxLightingOff();
    IwGxSetColClear(0xa0, 0xc0, 0xff, 0xff);
    
    int32 count = 0, speed = 3;
    
    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        //Update the input systems
        s3eKeyboardUpdate();
        s3ePointerUpdate();

        // Clear the surface
        IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
        
        // Your rendering/app code goes here.
        drawPaddle((++count*speed) % 200);
        
        // Standard EGL-style flush of drawing to the surface
        IwGxFlush();
        
        // Standard EGL-style flipping of double-buffers
        IwGxSwapBuffers();

        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(0);
    }

    //Terminate modules being used
    IwGxTerminate();
    
    // Return
    return 0;
}
