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

struct estadisticas{
    int vidasP1;
    int scoreP1;
    int vidasP2;
    int scoreP2;
};


class Juego{

private:

    Tablero miTablero;

    Enemigo* enem;

    Enemigo* enem2;

    Jugador* player;

    Jugador* player2;

    estadisticas statsActuales;

    float movimientos;

public:

    void Initialize();

    void Print(); //Placeholder

    void MovePiece(int index);

    estadisticas GetGameStats();

    bool CheckIfWon();

private:

    void CheckCurrentPositions();

    void PrintCurrentPos(int index); //Imprime las coordenadas actuales de la pieza.

    int GetRandomNumber();

    position GetInitialPositions(int index);

    position CheckPositionsToMove(position currentPos);

    void GiveScore(int index);

    void UpdateStats();

};

/* PUBLIC */

void Juego::Initialize(){ //Cambiar por Inicializar tablero leyendo archivo
    int values[9][9] = {
        0,0,0,0,0,0,0,0,0,
        0,2,3,6,5,4,1,1,0,
        0,2,0,2,0,7,0,1,0,
        0,1,8,2,9,1,4,2,0,
        0,7,0,7,0,2,0,5,0, //Recorté los bordes con 0 para que las piezas no se escapen de las dimensiones del array.
        0,6,5,2,9,7,7,1,0,
        0,1,0,2,0,3,0,1,0,
        0,1,1,1,9,1,1,5,0,
        0,0,0,0,0,0,0,0,0};
    miTablero.CargarTableroHardCode(values);
    enem = new Enemigo(12, GetInitialPositions(1));
    enem2 = new Enemigo(12, GetInitialPositions(2));
    player = new Jugador(9, GetInitialPositions(3), 3);
    player2 = new Jugador(9, GetInitialPositions(4), 3);
    UpdateStats();
    this -> movimientos = 0;
}

void Juego::Print(){ //Función que se llama para imprimir y colorear el tablero.
    CheckCurrentPositions();
    UpdateStats();
    miTablero.ReiniciarColores(15);
    miTablero.ColorearPosicion(enem->GetPosition(), enem->GetColor());
    miTablero.ColorearPosicion(enem2->GetPosition(), enem2->GetColor());
    if(player->GetVida() > 0){
        miTablero.ColorearPosicion(player->GetPosition(), player->GetColor());
    }
    if(player2->GetVida() > 0){
        miTablero.ColorearPosicion(player2->GetPosition(), player2->GetColor());
    }
    miTablero.ImprimirTablero();
    PrintCurrentPos(1);
    PrintCurrentPos(2);
    if(player->GetVida() > 0){
        PrintCurrentPos(3);
    }
    if(player2->GetVida() > 0){
        PrintCurrentPos(4);
    }
}

void Juego::MovePiece(int index){
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
        case 4:
            selectedPiece = player2;
            break;
    }
    position posToMove = CheckPositionsToMove(selectedPiece->GetPosition());
    selectedPiece->SetPosition(posToMove.x, posToMove.y);
    GiveScore(index);
    this -> movimientos++;
}

estadisticas Juego::GetGameStats(){
    return this->statsActuales;
}

/* PRIVATE */

void Juego::CheckCurrentPositions(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetConsoleCP(437);
    std::cout << "Jugador 1 \n" << (char)3 << player->GetVida() << "\nScore: " << player->GetPuntaje() << std::endl << std::endl;
    std::cout << "Jugador 2 \n" << (char)3 << player2->GetVida() << "\nScore: " << player2->GetPuntaje() << std::endl << std::endl;
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
        case 4:
            selectedPiece = player2;
            break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << "Pieza " << index << " en posicion: X:" << selectedPiece->GetPosition().x << ", Y:" << selectedPiece->GetPosition().y << std::endl;
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
    return miTablero.GetPosicionesIniciales(index);
}

position Juego::CheckPositionsToMove(position currentPos){
    position posToMove;
    bool canMove = false;
    int num = 0;
    int dir = 0;
    while(!canMove){ // Debe reformularse en una funcion recursiva.
        num = rand()%2;
        dir = GetRandomNumber();
        if(num == 0){ //BUG: Las piezas de un mismo tipo se mueven para un mismo lado, hasta el punto de empujarse hacia posiciones negativas del array.
                if(miTablero.CheckSpace(currentPos.x + dir, currentPos.y)){
                    posToMove.x = currentPos.x + dir;
                    posToMove.y = currentPos.y;
                    canMove = true;
                }else{
                if(miTablero.CheckSpace(currentPos.x, currentPos.y + dir)){
                    posToMove.x = currentPos.x;
                    posToMove.y = currentPos.y + dir;
                    canMove = true;
                }
            }
        }
    }
    return posToMove;
}

void Juego::GiveScore(int index){
    bool isEnemy = false;
    Jugador* selectedPlayer;
    switch(index){
        case 3 :
            selectedPlayer = player;
            break;
        case 4 :
            selectedPlayer = player2;
            break;
        default:
            isEnemy = true;
            break;

    }
    if(!isEnemy){
        selectedPlayer->AumentarPuntaje(miTablero.GivePositionScore(selectedPlayer->GetPosition()));
        this->miTablero.MarcarRecorrido(selectedPlayer->GetPosition());
    }
}

bool Juego::CheckIfWon(){
    return miTablero.CheckIfRecorrido();
}

void Juego::UpdateStats(){
    this->statsActuales.vidasP1 = this->player->GetVida();
    this->statsActuales.vidasP2 = this->player2->GetVida();
    this->statsActuales.scoreP1 = this->player->GetPuntaje();
    this->statsActuales.scoreP2 = this->player2->GetPuntaje();
}

#endif // JUEGO_H_INCLUDED
