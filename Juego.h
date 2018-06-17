#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "Enemigo.h"
#include "Jugador.h"
#include "Tablero.h"

/*
Enemigo 1 = Index 1.
Enemigo 2 = Index 2.
Jugador 1 = Index 3.
Jugador 2 = Index 4.
*/


class Juego{ //Esto es un asco. Pero funciona.

private:

    Tablero miTablero;

    Enemigo* enem;

    Enemigo* enem2;

    Jugador* player;

    Jugador* player2;

    float movimientos;

public:

    void Initialize();

    void Print(); //Placeholder

    void MovePiece(int index);

private:

    void CheckCurrentPositions();

    void PrintCurrentPos(int index); //Imprime las coordenadas actuales de la pieza.

    int GetRandomNumber();

    position GetInitialPositions(int index);

};

/* PUBLIC */

void Juego::Initialize(){
    enem = new Enemigo(1, GetInitialPositions(1));
    enem2 = new Enemigo(1, GetInitialPositions(2));
    player = new Jugador(2, GetInitialPositions(3), 3);
    this -> movimientos = 0;
}

void Juego::Print(){
    CheckCurrentPositions();
    PrintCurrentPos(1);
    PrintCurrentPos(2);
    PrintCurrentPos(3);
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
        case 3:
            selectedPiece = player;
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

void Juego::CheckCurrentPositions(){
    if(enem->GetPosition().x == player->GetPosition().x && enem->GetPosition().y == player->GetPosition().y){
        player->PerderVida();
        std::cout << "Jugador 1 pierde una vida. Le quedan: " << player->GetVida() << std::endl << std::endl;
    }
    if(enem->GetPosition().x == player2->GetPosition().x && enem->GetPosition().y == player2->GetPosition().y){
        player2->PerderVida();
        std::cout << "Jugador 2 pierde una vida. Le quedan: " << player2->GetVida() << std::endl << std::endl;
    }
    if(enem2->GetPosition().x == player->GetPosition().x && enem2->GetPosition().y == player->GetPosition().y){
        player->PerderVida();
        std::cout << "Jugador 1 pierde una vida. Le quedan: " << player->GetVida() << std::endl << std::endl;
    }
    if(enem2->GetPosition().x == player2->GetPosition().x && enem2->GetPosition().y == player2->GetPosition().y){
        player2->PerderVida();
        std::cout << "Jugador 2 pierde una vida. Le quedan: " << player2->GetVida() << std::endl << std::endl;
    }
}

void Juego::PrintCurrentPos(int index){
    Pieza* selectedPiece;
    switch(index){
        case 1 :
            selectedPiece = enem;
            break;
        case 2 :
            selectedPiece = enem2;
            break;
        case 3:
            selectedPiece = player;
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
        case 3:
            pos.x = 3;
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
