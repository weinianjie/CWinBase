#include "../include/base/CWinBase.h"
#include <windows.h>
#include <iostream>

void CWinBase::Show(HINSTANCE hInstance, HWND parentHwnd)
{
    this->hInstance = hInstance;
    this->parentHwnd = parentHwnd;

    //创建窗口
    Create();

    //替换事件处理函数
    SetWindowLong(hwnd, GWL_USERDATA, (DWORD)this);
//    m_pPreProcEdWord = (WNDPROC)GetWindowLong(m_hEdWord,GWL_WNDPROC);
    this->OldMsgProc = (WNDPROC)SetWindowLong(hwnd,GWL_WNDPROC,(DWORD)EventDispatcher);
}

void CWinBase::OnCreate(){}
void CWinBase::OnLButtonDown(){}
void CWinBase::OnLButtonUp(){}
void CWinBase::OnLButtonDbClick(){}
void CWinBase::OnRButtonDown(){}
void CWinBase::OnRButtonUp(){}
void CWinBase::OnRButtonDbClick(){}
void CWinBase::OnMButtonDown(){}
void CWinBase::OnMButtonUp(){}
void CWinBase::OnMButtonDbClick(){}
void CWinBase::OnMouseWheel(){}
void CWinBase::OnMouseMove(){}
void CWinBase::OnMove(){}
void CWinBase::OnSize(){}
void CWinBase::OnSetFocus(){}
void CWinBase::OnKillFocus(){}
void CWinBase::OnHscroll(){}
void CWinBase::OnVscroll(){}


//默认处理函数
LRESULT  CALLBACK   CWinBase::DefaultProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            std::cout << "...";
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

//分发各种事件
LRESULT CALLBACK CWinBase::EventDispatcher(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	int wmId, wmEvent;

    wmId    = LOWORD(wParam);
    wmEvent = HIWORD(wParam);

    CWinBase* pInstance = (CWinBase *)GetWindowLong(hwnd,GWL_USERDATA);
std::cout << (hwnd == pInstance->hwnd);
    if(hwnd == pInstance->hwnd){
        switch (message)                  /* handle the messages */
        {
            case WM_CREATE:
                std::cout << "456";
                pInstance->OnCreate();
                break;

            case WM_LBUTTONDOWN:
                pInstance->OnLButtonDown();
                break;

            case WM_LBUTTONUP:
                pInstance->OnLButtonUp();
                break;

            case WM_LBUTTONDBLCLK:
                pInstance->OnLButtonDbClick();
                break;

            case WM_RBUTTONDOWN:
                pInstance->OnRButtonDown();
                break;

            case WM_RBUTTONUP:
                pInstance->OnRButtonUp();
                break;

            case WM_RBUTTONDBLCLK:
                pInstance->OnRButtonDbClick();
                break;

            case WM_MBUTTONDOWN:
                pInstance->OnMButtonDown();
                break;

            case WM_MBUTTONUP:
                pInstance->OnMButtonUp();
                break;

            case WM_MBUTTONDBLCLK:
                pInstance->OnMButtonDbClick();
                break;

            case WM_MOUSEWHEEL:
                pInstance->OnMouseWheel();
                break;

            case WM_MOUSEMOVE:
                pInstance->OnMouseMove();
                break;

            case WM_MOVE:
                pInstance->OnMove();
                break;

            case WM_SIZE:
                pInstance->OnSize();
                break;

            case WM_SETFOCUS:
                pInstance->OnSetFocus();
                break;

            case WM_KILLFOCUS:
                pInstance->OnKillFocus();
                break;

            case WM_HSCROLL:
                pInstance->OnHscroll();
                break;

            case WM_VSCROLL:
                pInstance->OnVscroll();
                break;
        }

        return CallWindowProc(pInstance->OldMsgProc,hwnd,message,wParam,lParam);
    }
    return 0;
}
