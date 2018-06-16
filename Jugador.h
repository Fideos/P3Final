#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador : public Pieza{

private:

    int vidaActual;

    int puntaje;

public:

    Jugador(int col, position initPos, int vidaMax){
        this->currentPos = initPos;
        this->color = col;
        this->vidaActual = vidaMax;
        this->puntaje = 0;
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
}

#endif // JUGADOR_H_INCLUDED
