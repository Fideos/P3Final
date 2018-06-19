#include <iostream>
#include <thread>
#include <stdlib.h>
#include <windows.h>

#include "Partida.h"

using namespace std;

int main()
{
    Partida miPartida;
    miPartida.Run();
    system("PAUSE");
    return 0;
}
