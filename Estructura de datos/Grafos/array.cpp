#include<bits/stdc++.h>

#include<iostream>

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

using namespace std;
int main() {
    input;
    output;
    int Nodos;
    cin >> Nodos;
    // Crear una matriz de adyacencia para representar el grafo.
    int grafo[Nodos][Nodos];
    memset(grafo, 0, sizeof(grafo));
    // Solicitar al usuario el número de aristas en el grafo.
    int Aristas;
    cin >> Aristas;
    // Leer las aristas y actualizar la matriz de adyacencia.
    for (int i = 0; i < Aristas; i++) {
        int nodoOrigen, nodoDestino;
        cin >> nodoOrigen >> nodoDestino;
        // Establecer a 1 para indicar una arista dirigida del nodo origen al nodo destino.
        grafo[nodoOrigen][nodoDestino] = 1;
    }
    // Imprimir la matriz de adyacencia para visualizar el grafo.
    for (int i = 0; i < Nodos; i++) {
        for (int j = 0; j < Nodos; j++) {
            cout << "[" << grafo[i][j] << "]";
        }
        cout << endl;
    }
    return 0; 
}