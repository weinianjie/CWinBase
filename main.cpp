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
    //ȫ�ֱ�����ֵ
    Global::G_Instance = hThisInstance;

    //������������
    CWinMain* mainWind = new CWinMain();
    mainWind->Show(hThisInstance, HWND_DESKTOP);

    //��ʼ��Ϣѭ��
    MSG messages;
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}
