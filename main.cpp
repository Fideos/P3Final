#include <iostream>
#include <thread>
#include <stdlib.h>

#include <windows.h>

#include "Juego.h"

using namespace std;

int main()
{
    Juego miJuego;

    miJuego.Initialize();
    miJuego.Print();
    system("PAUSE");
    system("CLS");

    for (int i = 0; i < 5; i++){ //Crear Threads.
        miJuego.MovePiece(1);
        miJuego.MovePiece(2);
        miJuego.MovePiece(3);
        miJuego.Print();
        system("PAUSE");
        system("CLS");
    }

    system("PAUSE");
    return 0;
}
