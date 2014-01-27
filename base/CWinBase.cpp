#include "../include/base/CWinBase.h"
#include <windows.h>
#include <iostream>

void CWinBase::Show(HINSTANCE hInstance, HWND parentHwnd)
{
    this->hInstance = hInstance;
    this->parentHwnd = parentHwnd;

    //��������
    Create();

    //�滻�¼�������
    //Store the pointer in the window
    SetWindowLong(hwnd, GWL_USERDATA, (DWORD)this);
    //Get the previous window procedure
//    m_pPreProcEdWord = (WNDPROC)GetWindowLong(m_hEdWord,GWL_WNDPROC);
    //Set the new window procedure
    SetWindowLong(hwnd,GWL_WNDPROC,(DWORD)EventDispatcher);
}

void CWinBase::OnLButtonDown()
{

}

void CWinBase::AfterShow()
{

}

//�ַ������¼�
LRESULT CALLBACK CWinBase::EventDispatcher(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	int wmId, wmEvent;

    wmId    = LOWORD(wParam);
    wmEvent = HIWORD(wParam);

    CWinBase* pInstance = (CWinBase *)GetWindowLong(hwnd,GWL_USERDATA);

        //��ǰ���ڴ������¼�
//    if(hwnd == pInstance->hwnd){

        switch (message)                  /* handle the messages */
        {
            case WM_LBUTTONUP :
                if(hwnd == pInstance->hwnd){
                    pInstance->OnLButtonDown();
                }

                break;

            //return CallWindowProc(pObject->m_pPreProcEdWord,hWnd,wMsg,wParam,lParam);
            case WM_DESTROY:
                PostQuitMessage (0);      /* send a WM_QUIT to the message queue */
                break;
            default:                      /* for messages that we don't deal with */
                return DefWindowProc (hwnd, message, wParam, lParam);
        }

//    }
if(message == WM_DESTROY){
    PostQuitMessage (0);
    return 0;
}else{
    return DefWindowProc (hwnd, message, wParam, lParam);
}
    return 0;
}
