#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

struct mapa{ //El tablero tiene 2 capas. Para cargar los valores hay que usar "Tablero[x][x].valores = ...".
    int valores;
    int colores;
    bool recorrido;
};

class Tablero{

private:

    mapa tablero[9][9];

public:

    void CargarTableroHardCode(int values[9][9]);

    void CargarTablero();

    void ImprimirTablero();

    bool CheckSpace(int x, int y);

    void ReiniciarColores(int color);

    void ColorearPosicion(position pos, int color);

    position GetPosicionesIniciales(int index);

    int GivePositionScore(position pos);

    bool CheckIfRecorrido();

    void MarcarRecorrido(position pos);

};

void Tablero::CargarTableroHardCode(int values[9][9]){ //Una funcion para cargar el tablero a mano.
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            tablero[i][j].valores = values[i][j];
            tablero[i][j].recorrido = false;
            ReiniciarColores(15);
        }
    }
}

void Tablero::CargarTablero(){ // Aca deberia ir una funcion que cargue el tablero desde un archivo txt. Llamar desde "Initialize" en Juego.h.

    FILE *fp;
    fp = fopen("Tablero.txt", "r");
    if (fp != NULL){
        char linea1[10]; //Usar Substring para separar los valores.
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
        for (int j = 0; j < 9; j++){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tablero[i][j].colores);
            std::cout << tablero[i][j].valores;
        }
        std::cout << "\n";
    }
}

bool Tablero::CheckSpace(int x, int y){ //Debe verificarse que la pieza no se mueva a dimensiones negativas del array.
    if(this->tablero[x][y].valores == 0){
        return false;
    }else{
        return true;
    }
}

void Tablero::ReiniciarColores(int color){ //Recolorea el tablero. Llamar en cada buffer.
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            tablero[i][j].colores = color;
            if(tablero[i][j].recorrido == true){
                position pos;
                pos.x = i;
                pos.y = j;
                ColorearPosicion(pos, 8);
            }
            if(tablero[i][j].valores == 0){
                position pos;
                pos.x = i;
                pos.y = j;
                ColorearPosicion(pos, 2);
                MarcarRecorrido(pos);
            }
        }
    }
}

void Tablero::ColorearPosicion(position pos, int color){
    tablero[pos.x][pos.y].colores = color;
}

position Tablero::GetPosicionesIniciales(int index){
    position pos;
    switch(index){ // Implementar función que devuelva las posiciones desde el archivo txt.
        case 1 :
            pos.x = 5;
            pos.y = 5;
            break;
        case 2 :
            pos.x = 5;
            pos.y = 2;
            break;
        case 3:
            pos.x = 3;
            pos.y = 6;
            break;
        case 4:
            pos.x = 2;
            pos.y = 3;
            break;
        default:
            pos.x = 5;
            pos.y = 5;
            break;
    }
    return pos;
}

int Tablero::GivePositionScore(position pos){
    return this->tablero[pos.x][pos.y].valores;
}

bool Tablero::CheckIfRecorrido(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tablero[i][j].recorrido == false){
                return false;
                break;
            }
        }
    }
    return true;
}

void Tablero::MarcarRecorrido(position pos){
    tablero[pos.x][pos.y].recorrido = true;
}

#endif // TABLERO_H_INCLUDED
