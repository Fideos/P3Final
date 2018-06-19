#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED

#include <thread>
#include <pthread.h>
#include <mutex>

#include "Juego.h"

std::mutex mtx;

class Partida{ //Maneja los Threads y las condiciones de victoria y derrota.

private:

    Juego miJuego;

    bool lost;

    bool won;

public:

    void Run();

private:

    void ImprimirTablero();

    void MoverEnemigo1();

    void MoverEnemigo2();

    void MoverJugador1();

    void MoverJugador2();

};

void Partida::Run(){

    miJuego.Initialize();
    miJuego.Print();
    system("PAUSE");
    system("CLS");
    bool lost = false;
    bool won = false;
    /*
    std::thread imprimirTh(ImprimirTablero);
    std::thread enem1Th(MoverEnemigo1);
    std::thread enem2Th(MoverEnemigo2);
    std::thread juga1Th(MoverJugador1);
    std::thread juga2Th(MoverJugador2);
    */
    while(!lost && !won){
            /*
        enem1Th.join();
        system("CLS");
        imprimirTh.join();
        enem2Th.join();
        system("CLS");
        imprimirTh.join();
        juga1Th.join();
        system("CLS");
        imprimirTh.join();
        juga2Th.join();
        system("CLS");
            */
        MoverEnemigo1();
        system("CLS");
        ImprimirTablero();
        MoverEnemigo2();
        system("CLS");
        ImprimirTablero();
        MoverJugador1();
        system("CLS");
        ImprimirTablero();
        MoverJugador2();
        system("CLS");
        ImprimirTablero();
        if(miJuego.GetGameStats().vidasP1 <= 0 && miJuego.GetGameStats().vidasP2 <= 0){
            lost = true;
        }
    }
    system("CLS");
    if(lost){
        std::cout << "Ambos se murieron.\nFin del juego." << std::endl;
    }
}

//Private

void Partida::ImprimirTablero(){
    mtx.lock();
    miJuego.Print();
    Sleep(300);
    mtx.unlock();
}

void Partida::MoverEnemigo1(){
    mtx.lock();
    miJuego.MovePiece(1);
    mtx.unlock();
}

void Partida::MoverEnemigo2(){
    mtx.lock();
    miJuego.MovePiece(2);
    mtx.unlock();
}

void Partida::MoverJugador1(){
    mtx.lock();
    miJuego.MovePiece(3);
    mtx.unlock();
}

void Partida::MoverJugador2(){
    mtx.lock();
    miJuego.MovePiece(4);
    mtx.unlock();
}
#endif // PARTIDA_H_INCLUDED
