#include<bits/stdc++.h>
using namespace std;
#define input freopen("in.txt","r",stdin)
#define input freopen("out.txt","r",stdout)

vector<string> grafo;
int vx[]={-1, -1, -1, 0, 1, 1, 1, 0};
int vy[]={-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int fila, int columna) {
    //solo va a entrar al dfs si la celda 
    //tiene color negro, es decir numeral #
    grafo[fila][columna]='.';
    //visitamos las 8 direcciones
    for (int i = 0; i < 8; i++) {
        int nuevaFila=fila+vx[i];
        int nuevaColumna=columna+vy[i];
        if(nuevaFila>=0 && nuevaColumna>=0 &&
        nuevaFila<fila && nuevaColumna<columna && 
        grafo[nuevaFila][nuevaColumna] == '#') {
            dfs(nuevaFila,nuevaColumna);
        }
    }
}
int main(){
    input;
    int amebas=0;
    int filas, columnas;
    cin>>filas>>columnas;
    for (int i=0;i<filas;i++){
        string fila;
        cin>>fila;
        grafo.push_back(fila);
    }
    for(int i =0; i<filas;i++) {
        for (int j = 0; i < columnas; j++) {
            if (grafo[i][j]=='#') {
                dfs(i,j);
                amebas++;
            }
        }
        
    }
    cout<<amebas;
}