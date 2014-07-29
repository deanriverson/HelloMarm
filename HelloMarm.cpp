#include "s3e.h"
#include "IwDebug.h"
#include "IwGx.h"
#include "Paddle.h"

int16 processKeyboard(int32 speed) {
    int32 aKey = s3eKeyboardGetState(s3eKeyA);
    int32 dKey = s3eKeyboardGetState(s3eKeyD);
    
    if (aKey & S3E_KEY_STATE_DOWN) {
        return -speed;
    } else if (dKey & S3E_KEY_STATE_DOWN) {
        return speed;
    } else {
        return 0;
    }

}

// Main entry point for the application
int main()
{
    //Initialise graphics system(s)
    IwGxInit();
    IwGxLightingOff();
    IwGxSetColClear(0xa0, 0xc0, 0xff, 0xff);
    
    int32 paddlePos = 100, speed = 3;
    int16 screenWidth = IwGxGetScreenWidth();
    
    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        //Update the input systems
        s3eKeyboardUpdate();
        s3ePointerUpdate();

        // Clear the surface
        IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
        
        // Your rendering/app code goes here.
        paddlePos += processKeyboard(speed);
        drawPaddle(paddlePos % screenWidth);
        
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
