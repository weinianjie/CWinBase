#include "include/CWinMain.h"
#include "include/CSubmitButton.h"
#include "include/resource.h"
#include "include/base/CWinButton.h"
#include <tchar.h>
#include <iostream>


int CWinMain::Create()
{
    TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = this->hInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = CWinBase::DefaultProc;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           this->parentHwnd,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           this->hInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);


//    CWinButton* button = new CWinButton();
//    button->Show(this->hInstance, this->hwnd);
//
    CSubmitButton* button2 = new CSubmitButton();
    button2->Show(this->hInstance, this->hwnd);

    return 2;
}

void CWinMain::OnLButtonDown()
{
    std::cout << "2";
}
