//                                     PROBLEMA HECHO EN CLASE

//Pedrito se hizo una prueba de COVID y lastimosamente dio positivo, 
//asi que llamo a todos los amigos con los que tuvo contacto, y sus amigos, 
//luego de enterarse lo de Pedrito, hicieron lo mismo. 

//Se desea saber cuantas llamadas se hicieron en total, 
//sabiendo que si mas de una persona llama a "x" solo se 
//debe contar como una llamada. Pedrito es el vertice 0.

//INPUT                     OUTPUT
//0 1                       7
//0 2
//0 3
//1 4 
//2 4
//2 5
//3 6
//4 7
//5 7
//6 7
//8 10
//10 8
//11 10
//10 11
//8 9
//9 11

#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

bool Visitado[10000];
vector<int> grafo [10000];

void bfs(int pedro){//parametro
    queue<int> Llamadas;
    Llamadas.push(pedro);//Se agrega el nodo inicial a la cola para comenzar el BFS.
    Visitado[pedro]=true;//Se marca el nodo inicial como visitado.

    while (!Llamadas.empty()){ //mientras haya nodos en la cola por explorar
        int nodoActual = Llamadas.front();
        Llamadas.pop();
        for (int amigo:grafo[nodoActual]){//Este bucle recorre todos los nodos conectados al nodoActual 
            if(!Visitado[amigo]){
                Llamadas.push(amigo);//Se añade el vecino no visitado a la cola para procesarlo más tarde.
                Visitado[amigo]=true;
            }
        }
    }
}

int main(){
    input;
    output;
    int nodos, aristas;
    cin>>nodos>>aristas;
    for(int i = 0 ; i < aristas; i++){
        int emisor, receptor;
        cin>>emisor>>receptor;
        grafo[emisor].push_back(receptor);
        grafo[receptor].push_back(emisor);
    }
    bfs(0);
    int totalLlamadas=0;
    for (int i = 1; i<nodos; i++){
        if (Visitado[i]) {
            totalLlamadas++;
        }
    }
    cout<<totalLlamadas;
}
