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
        virtual void    OnCreate();
        virtual void    OnLButtonDown();
        virtual void    OnLButtonUp();
        virtual void    OnLButtonDbClick();
        virtual void    OnRButtonDown();
        virtual void    OnRButtonUp();
        virtual void    OnRButtonDbClick();
        virtual void    OnMButtonDown();
        virtual void    OnMButtonUp();
        virtual void    OnMButtonDbClick();
        virtual void    OnMouseWheel();
        virtual void    OnMouseMove();
        virtual void    OnMove();
        virtual void    OnSize();
        virtual void    OnSetFocus();
        virtual void    OnKillFocus();
        virtual void    OnHscroll();
        virtual void    OnVscroll();

    protected:
                WNDPROC OldMsgProc;
                static  LRESULT  CALLBACK   DefaultProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
    private:
                static  LRESULT  CALLBACK   EventDispatcher(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

};

#endif // CWINBASE_H_INCLUDED
