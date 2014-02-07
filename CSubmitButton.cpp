#include "include/CSubmitButton.h"
#include "include/resource.h"
#include "include/base/CWinButton.h"
#include <tchar.h>
#include <iostream>


void CSubmitButton::OnCreate()
{
    std::cout << "123";
}

void CSubmitButton::OnLButtonDown()
{
    std::cout << "sheep";
}
