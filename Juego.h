#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "Enemigo.h"
#include "Jugador.h"
#include "Tablero.h"


class Juego{

private:

    Tablero miTablero;

    Enemigo* enem;

    Enemigo* enem2;

    float movimientos;

public:

    void Initialize(); //Placeholder

    void PrintCurrentPos();

    void MovePiece();

private:

    int GetRandomNumber();

    position GetInitialPositions(int index);

};

/* PUBLIC */

void Juego::Initialize(){
    //enem->SetPosition(5, 5);
    //enem2->SetPosition(5, 6);
    enem = new Enemigo(5, GetInitialPositions(1));
    enem2 = new Enemigo(5, GetInitialPositions(2));
    this -> movimientos = 0;
}

void Juego::PrintCurrentPos(){ //Modificar para que reciba y imprima determinada pieza.
    std::cout << "Pieza 1 en posicion: X:" << enem->GetPosition().x << ", Y:" << enem->GetPosition().y << std::endl;
    std::cout << "Pieza 2 en posicion: X:" << enem2->GetPosition().x << ", Y:" << enem2->GetPosition().y << std::endl;
    std::cout << "Movimientos: " << movimientos << std::endl;
}

void Juego::MovePiece(){ //Modificar para que reciba y mueva dererminada pieza.
    int num = rand()%2;
    if(num == 0){
        enem->SetPosition(enem->GetPosition().x + GetRandomNumber(), enem->GetPosition().y);
    }else{
        enem->SetPosition(enem->GetPosition().x, enem->GetPosition().y+ GetRandomNumber());
    }
    this -> movimientos++;
}

/* PRIVATE */

int Juego::GetRandomNumber(){
    int num = rand()%2;
    if(num == 0){
        return -1;
    }else{
        return 1;
    }
}

position Juego::GetInitialPositions(int index){
    position pos;
    switch(index){ // Implementar función que devuelva las posiciones desde el archivo del tablero.
        case 1 :
            pos.x = 5;
            pos.y = 5;
            break;
        case 2 :
            pos.x = 5;
            pos.y = 6;
            break;
        default:
            pos.x = 5;
            pos.y = 5;
            break;
    }
    return pos;
}

#endif // JUEGO_H_INCLUDED
