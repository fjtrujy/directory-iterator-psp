#include <stdio.h>
#include <filesystem>

#ifdef __PSP__
#include <pspkernel.h>
PSP_MODULE_INFO("filesystem-test", 0, 1, 0);

#include <pspdebug.h>
#define printf	pspDebugScreenPrintf

#include <pspctrl.h>
#endif

int main(void)
{
    #ifdef __PSP__
        pspDebugScreenInit();
        sceCtrlSetSamplingCycle(0);
	    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
    #endif
    std::filesystem::directory_iterator dir_scanner("./");
    for (auto &entry : dir_scanner) {
        printf("%s\n", entry.path().string().c_str());
    }
    #ifdef __PSP__
        printf("Press X to exit\n");
        SceCtrlData pad;
        int done = 0;
        while(!done) {
            sceCtrlReadBufferPositive(&pad, 1);
            if (pad.Buttons != 0){
                if (pad.Buttons & PSP_CTRL_CROSS){
                    pspDebugScreenPrintf("Done \n");
                } 
            }
        }

    #endif
    return 0;
}