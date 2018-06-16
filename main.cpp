#include <iostream>
#include <thread>
#include "Juego.h"

using namespace std;

int main()
{
    /*
    Tablero miTablero;
    int values[10][9] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
    miTablero.CargarTableroAlt(values);
    //miTablero.CargarTablero();
    miTablero.ImprimirTablero();
    system("PAUSE");
    */
    Juego miJuego;

    miJuego.Initialize();
    miJuego.Print();
    /*
    miJuego.Initialize(enem2, 6, 4);
    miJuego.PrintCurrentPos(enem2);
    */
    for (int i = 0; i < 5; i++){
        miJuego.MovePiece(1);
        miJuego.MovePiece(2);
        miJuego.Print();
    }

    system("PAUSE");
    return 0;
}
