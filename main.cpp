
#include <iostream>
#include <windows.h>

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

