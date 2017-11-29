#include "keypressthread.h"
#include "windows.h"
#include "QDebug"


KeyPressThread::KeyPressThread() : QThread() {

}

void KeyPressThread::run() {
    if (RegisterHotKey(NULL, 1, MOD_ALT | 0x4000, 0x58)) {
        // qDebug() << "Hotkey 'ALT+x' registered, using MOD_NOREPEAT flag";
    }

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) != 0) {
        if (msg.message == WM_HOTKEY) {
            // qDebug() << "WM_HOTKEY received";
            emit notify();
        }
    }
}
