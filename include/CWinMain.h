#ifndef CWINMAIN_H_INCLUDED
#define CWINMAIN_H_INCLUDED

#include "base/CWinBase.h"

class CWinMain : public CWinBase
{
public :
    virtual void    OnLButtonDown();
private :
    virtual int    Create();
};

#endif // CWINMAIN_H_INCLUDED
