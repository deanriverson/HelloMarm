#include "s3e.h"
#include "IwDebug.h"
#include "IwGx.h"


// Main entry point for the application
int main()
{
    //Initialise graphics system(s)
    IwGxInit();

    IwGxSetColClear(0xa0, 0xc0, 0xff, 0xff);
    

    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        //Update the input systems
        s3eKeyboardUpdate();
        s3ePointerUpdate();

        // Clear the surface
        IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
        
        // Your rendering/app code goes here.
        IwGxPrintString(20, 200, "Matt and Dean Rock!!!!");

        // Standard EGL-style flush of drawing to the surface
        IwGxFlush();
        // Standard EGL-style flipping of double-buffers
        IwGxSwapBuffers();
		int32 inputType = s3ePointerGetInt(S3E_POINTER_TYPE);
		int32 key = s3eKeyboardGetState(s3eKeyA);
		if (inputType == S3E_POINTER_TYPE_MOUSE) {
			IwGxPrintString(20, 190, "mouse input detected");
		}
		else if (inputType == S3E_POINTER_TYPE_STYLUS) {
			IwGxPrintString(20, 190, "touch input detected");
		}
		else {
			IwGxPrintString(20, 190, "no input detected");
		}
		if (key & S3E_KEY_STATE_PRESSED)
		{
			// A key has just been pressed
			IwGxPrintString(20, 180, "A key pressed");
		}
		else if (key & S3E_KEY_STATE_RELEASED)
		{
			// Back key has just been released
			IwGxPrintString(20, 180, "A key released");
		}

		if (key & S3E_KEY_STATE_DOWN)
		{
			// Back key is currently held down
			IwGxPrintString(20, 180, "A key held");
		}
        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(0);
    }

    //Terminate modules being used
    IwGxTerminate();
    
    // Return
    return 0;
}
