#ifndef CWINBUTTON_H_INCLUDED
#define CWINBUTTON_H_INCLUDED

#include "CWinBase.h"

class CWinButton : public CWinBase
{
public :
    virtual void    AfterShow();
    virtual void    OnLButtonDown();

private :
    virtual int    Create();
};

#endif // CWINBUTTON_H_INCLUDED
