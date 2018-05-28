#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

class Tablero{

private:

    int tablero[10][9];

public:

void CargarTableroAlt(int values[10][9]);

void CargarTablero();

void ImprimirTablero();

bool CheckSpace(int x, int y);

};

void Tablero::CargarTableroAlt(int values[10][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 8; j++){
            tablero[i][j] = values[i][j];
        }
    }
}

void Tablero::CargarTablero(){

    FILE *fp;
    fp = fopen("Tablero.txt", "r");
    if (fp != NULL){
        char linea1[10];
        while(fgets(linea1, 9, fp) != NULL){
            for(int i = 0; i < 9; i++){
            tablero[0][i] = linea1[i];
            }
        }
    }
    fclose(fp);
}

void Tablero::ImprimirTablero(){

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 8; j++){
            std::cout << tablero[i][j];
        }
        std::cout << "\n";
    }

}

bool Tablero::CheckSpace(int x, int y){
    if(this->tablero[x][y] == 0){
        return false;
    }else{
        return true;
    }
}

#endif // TABLERO_H_INCLUDED
