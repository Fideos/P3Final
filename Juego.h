#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "Enemigo.h"
#include "Jugador.h"
#include "Tablero.h"


class Juego{ //Esto es un asco. Pero funciona.

private:

    Tablero miTablero;

    Enemigo* enem;

    Enemigo* enem2;

    float movimientos;

public:

    void Initialize();

    void Print(); //Placeholder

    void MovePiece(int index);

private:

    void PrintCurrentPos(int index); //Imprime las coordenadas actuales de la pieza.

    int GetRandomNumber();

    position GetInitialPositions(int index);

};

/* PUBLIC */

void Juego::Initialize(){
    enem = new Enemigo(5, GetInitialPositions(1));
    enem2 = new Enemigo(5, GetInitialPositions(2));
    this -> movimientos = 0;
}

void Juego::Print(){
    PrintCurrentPos(1);
    PrintCurrentPos(2);
}

void Juego::MovePiece(int index){ // La verdad que no tengo ni idea de por que carajos esto funciona.
    Pieza* selectedPiece;
    switch(index){
        case 1 :
            selectedPiece = enem;
            break;
        case 2 :
            selectedPiece = enem2;
            break;
    }
    int num = rand()%2;
    if(num == 0){
        selectedPiece->SetPosition(selectedPiece->GetPosition().x + GetRandomNumber(), selectedPiece->GetPosition().y);
    }else{
        selectedPiece->SetPosition(selectedPiece->GetPosition().x, selectedPiece->GetPosition().y+ GetRandomNumber());
    }
    this -> movimientos++;
}

/* PRIVATE */

void Juego::PrintCurrentPos(int index){
    Pieza* selectedPiece;
    switch(index){
        case 1 :
            selectedPiece = enem;
            break;
        case 2 :
            selectedPiece = enem2;
            break;
    }
    std::cout << "Pieza " << index << " en posicion: X:" << selectedPiece->GetPosition().x << ", Y:" << selectedPiece->GetPosition().y << std::endl << std::endl;
}

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
