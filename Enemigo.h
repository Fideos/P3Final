#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED


class Enemigo{

private:

    int ID;

    int currentX;

    int currentY;

public:

    void SetPosition(int setX, int setY);

    int GetPositionX();

    int GetPositionY();

    int GetRandomNumber();

    void MovePosition();

};


void Enemigo::SetPosition(int setX, int setY){
    this -> currentX = setX;
    this -> currentY = setY;
}

int Enemigo::GetPositionX(){
    return this->currentX;
}

int Enemigo::GetPositionY(){
    return this->currentY;
}

int Enemigo::GetRandomNumber(){
    int num = rand()%2;
    if(num == 0){
        return -1;
    }else{
        return 1;
    }
}

void Enemigo::MovePosition(){

}

#endif // ENEMIGO_H_INCLUDED
