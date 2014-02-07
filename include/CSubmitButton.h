#ifndef CSUBMITBUTTON_H_INCLUDED
#define CSUBMITBUTTON_H_INCLUDED

#include "base/CWinButton.h"

class CSubmitButton : public CWinButton
{
public :
    virtual void    OnLButtonDown();
    virtual void    OnCreate();
};

#endif // CSUBMITBUTTON_H_INCLUDED
