#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "Pieza.h"

class Jugador : public Pieza{

private:

    int vidaActual;

    int puntaje;

    position resetPos;

public:

    Jugador(int col, position initPos, int vidaMax){
        this->currentPos = initPos;
        this->color = col;
        this->vidaActual = vidaMax;
        this->puntaje = 0;
        this->resetPos = initPos;
    }

    int GetVida();

    int GetPuntaje();

    void AumentarPuntaje(int puntos);

    void PerderVida();
};

int Jugador::GetVida(){
    return this->vidaActual;
}

int Jugador::GetPuntaje(){
    return this->puntaje;
}

void Jugador::AumentarPuntaje(int puntos){
    this->puntaje += puntos;
}

void Jugador::PerderVida(){
    vidaActual--;
    currentPos = resetPos;
}

#endif // JUGADOR_H_INCLUDED
