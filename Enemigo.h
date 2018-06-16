#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED

#include "Pieza.h"

class Enemigo : public Pieza{

private:



public:

    Enemigo(int col, position initPos){
        this->currentPos = initPos;
        this->color = col;
    }

};


#endif // ENEMIGO_H_INCLUDED
