#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "include/resource.h"
#include "include/CWinMain.h"
#include <iostream>

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    //全局变量赋值
    Global::G_Instance = hThisInstance;

    //创建顶级窗口
    CWinMain* mainWind = new CWinMain();
    mainWind->Show(hThisInstance, HWND_DESKTOP);

    //开始消息循环
    MSG messages;
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}
