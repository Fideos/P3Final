#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "Enemigo.h"
#include "Tablero.h"


class Juego{

private:

    Tablero miTablero;

    Enemigo enem;

    float movimientos;

public:

    void Initialize(); //Placeholder

    void PrintCurrentPos();

    void MovePiece();

};

void Juego::Initialize(){
    enem.SetPosition(5, 5);
    this -> movimientos = 0;
}

void Juego::PrintCurrentPos(){
    std::cout << "Pieza 1 en posicion: X:" << enem.GetPositionX() << ", Y:" << enem.GetPositionY() << std::endl;
    std::cout << "Movimientos: " << movimientos << std::endl;
}

void Juego::MovePiece(){
    int num = rand()%2;
    if(num == 0){
        enem.SetPosition(enem.GetPositionX()+enem.GetRandomNumber(), enem.GetPositionY());
    }else{
        enem.SetPosition(enem.GetPositionX(), enem.GetPositionY()+enem.GetRandomNumber());
    }
    this -> movimientos++;
}

#endif // JUEGO_H_INCLUDED
