#ifndef CWINBASE_H_INCLUDED
#define CWINBASE_H_INCLUDED

#include <windows.h>

class CWinBase
{
    public:
        HWND    hwnd;
        HWND parentHwnd;
        HINSTANCE hInstance;

        virtual int     Create() = 0;
                void    Show(HINSTANCE hInstance, HWND parentHwnd);
        virtual void    AfterShow();
        virtual void    OnLButtonDown();

    protected:
                static  LRESULT  CALLBACK   EventDispatcher(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

};

#endif // CWINBASE_H_INCLUDED
