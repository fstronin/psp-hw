#include <pspkernel.h>

static int exit_requested = 0;

int is_running()
{
    return !exit_requested;
}

int cb_exit(int arg1, int arg2, void *common)
{
    exit_requested = 1;
    return 0;
}

int cb_thread(SceSize args, void *argp)
{
    int cb_id;
    cb_id = sceKernelCreateCallback("Exit Callback", cb_exit, NULL);
    sceKernelRegisterExitCallback(cb_id);

    sceKernelSleepThreadCB();

    return 0;
}

int setup_cb_exit()
{
    int thread_id;
    thread_id = sceKernelCreateThread("Callback Update Thread", cb_thread, 0x11, 0xFA0, THREAD_ATTR_USER, 0);

    if (thread_id >= 0) {
        sceKernelStartThread(thread_id, 0, 0);
    }

    return thread_id;
}
