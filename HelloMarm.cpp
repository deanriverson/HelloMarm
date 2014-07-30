#include "s3e.h"
#include "IwDebug.h"
#include "IwGx.h"
#include "Paddle.h"

static const uint8 ROWS = 8;
static const uint8 COLS = 6;

int16 screenWidth;
int16 screenHeight;

int16 blockWidth;
int16 blockHeight;

void drawBlocks() {
    static Block blocks[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            blocks[i][j].draw(j * blockWidth + 2, i * blockHeight+2, blockWidth-4, blockHeight-4);
        }
    }
}

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
    
    screenWidth = IwGxGetScreenWidth();
    screenHeight = IwGxGetScreenHeight();
    
    blockWidth = screenWidth / COLS;
    blockHeight = screenHeight / (ROWS * 3);
    
    Paddle paddle;
    
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
        paddle.draw(paddlePos % screenWidth);
        drawBlocks();
        
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
