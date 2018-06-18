#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

struct mapa{ //El tablero tiene 2 capas. Para cargar los valores hay que usar "Tablero[x][x].valores = ...".
    int valores;
    int colores;
};

class Tablero{

private:

    mapa tablero[10][9];

public:

    void CargarTableroHardCode(int values[10][9]);

    void CargarTablero();

    void ImprimirTablero();

    bool CheckSpace(int x, int y);

    void ReiniciarColores(int color);

    void ColorearPosicion(position pos, int color);

};

void Tablero::CargarTableroHardCode(int values[10][9]){ //Una funcion para cargar el tablero a mano.
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 8; j++){
            tablero[i][j].valores = values[i][j];
            ReiniciarColores(15);
        }
    }
}

void Tablero::CargarTablero(){ // Aca deberia ir una funcion que cargue el tablero desde un archivo txt. Llamar desde "Initialize" en Juego.h.

    FILE *fp;
    fp = fopen("Tablero.txt", "r");
    if (fp != NULL){
        char linea1[10];
        while(fgets(linea1, 9, fp) != NULL){
            for(int i = 0; i < 9; i++){
            //tablero[0][i] = linea1[i];
            }
        }
    }
    fclose(fp);
}

void Tablero::ImprimirTablero(){

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 8; j++){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tablero[i][j].colores);
            std::cout << tablero[i][j].valores;
        }
        std::cout << "\n";
    }
}

bool Tablero::CheckSpace(int x, int y){
    if(this->tablero[x][y].valores == 0){
        return false;
    }else{
        return true;
    }
}

void Tablero::ReiniciarColores(int color){ //Recolorea el tablero. Llamar en cada buffer.
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 8; j++){
            tablero[i][j].colores = color;
            if(tablero[i][j].valores == 0){
                position pos;
                pos.x = i;
                pos.y = j;
                ColorearPosicion(pos, 0);
            }
        }
    }
}

void Tablero::ColorearPosicion(position pos, int color){
    tablero[pos.x][pos.y].colores = color;
}

#endif // TABLERO_H_INCLUDED
