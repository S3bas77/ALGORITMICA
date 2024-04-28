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

bool Enterados[10000];
vector<int> grafo [10000];

void bfs(int pedro){
    queue<int> Llamadas;
    Llamadas.push(pedro);
    Enterados[pedro]=true;

    while (!Llamadas.empty()){
        int nodoActual = Llamadas.front();
        Llamadas.pop();
        for (int amigo:grafo[nodoActual]){
            if(!Enterados[amigo]){
                Llamadas.push(amigo);
                Enterados[amigo]=true;
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
    for (int i = 0; i<nodos; i++){
        if (Enterados[i]) {
            totalLlamadas++;
        }
    }
    cout<<totalLlamadas-1;
}
