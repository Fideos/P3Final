#ifndef PIEZA_H_INCLUDED
#define PIEZA_H_INCLUDED

struct position{
int x;
int y;
};

class Pieza{

protected:

    int color;

    position currentPos;

public:

    void SetColor(int color);

    int GetColor();

    void SetPosition(int setX, int setY);

    position GetPosition();

};

void Pieza::SetColor(int colorID){
    this->color == colorID;
}

int Pieza::GetColor(){
    return this->color;
}

void Pieza::SetPosition(int setX, int setY){
    currentPos.x = setX;
    currentPos.y = setY;
}

position Pieza::GetPosition(){
    return this->currentPos;
}

#endif // PIEZA_H_INCLUDED
