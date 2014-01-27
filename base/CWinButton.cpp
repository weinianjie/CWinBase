#include "../include/base/CWinButton.h"
#include "../include/resource.h"
#include <tchar.h>
#include <iostream>

int CWinButton::Create()
{
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           "BUTTON",         /* Classname */
           _T("Title"),       /* Title Text */
           WS_CHILD | WS_VISIBLE | WS_BORDER | WS_GROUP | WS_TABSTOP | ES_WANTRETURN, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           200,                 /* The programs width */
           200,                 /* and height in pixels */
           this->parentHwnd,        /* The window is a child-window to desktop */
           NULL,//(HMENU)IDC_BUTTON,//NULL,                /* No menu */
           this->hInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    ShowWindow (hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    return 0;
}

//在这里控制样式
void CWinButton::AfterShow()
{

}

void CWinButton::OnLButtonDown()
{
    std::cout << "1";
}


