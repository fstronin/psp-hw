#include "callback.c"

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>

#define VERSION 1
#define REVISION 0

PSP_MODULE_INFO("HelloWorld", PSP_MODULE_USER, VERSION, REVISION);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);

int main(int argc, char **argv)
{
    setup_cb_exit();
    pspDebugScreenInit();

    SceCtrlData ctrl_data;

    while (is_running())
    {
        sceDisplayWaitVblankStart();
        pspDebugScreenClear();

        pspDebugScreenSetXY(1, 1);
        pspDebugScreenPrintf("Hello World! Hey, try to press some button?\n");

        pspDebugScreenSetXY(1, 2);

        sceCtrlReadBufferPositive(&ctrl_data, 1);

        if (ctrl_data.Buttons & PSP_CTRL_CIRCLE) {
            pspDebugScreenPrintf("Circle pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_CROSS) {
            pspDebugScreenPrintf("Cross pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_SQUARE) {
            pspDebugScreenPrintf("Square pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_TRIANGLE) {
            pspDebugScreenPrintf("Triangle pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_RTRIGGER) {
            pspDebugScreenPrintf("Right Trigger pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_LTRIGGER) {
            pspDebugScreenPrintf("Left Trigger pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_HOME) {
            pspDebugScreenPrintf("Home pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_SELECT) {
            pspDebugScreenPrintf("Select pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_NOTE) {
            pspDebugScreenPrintf("Note pressed!\n");
        } else if (ctrl_data.Buttons & PSP_CTRL_START) {
            pspDebugScreenPrintf("Start pressed!\n");
        }
    }

    sceKernelExitGame();
    return 0;
}
