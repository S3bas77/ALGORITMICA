#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

pair<int, int> arista;
// ahora es una lista de pares ordenados
// el primer valor representa el peso y el 2do valor el nodo

// por ejemplo: ir del nodo 1 al nodo 2 con peso 5 se va a guardar:
// grafo[1].push_back(<5,2>)
vector< pair<int, int> > grafo [10];

int main( ) {
    input;
    int nroNodos, nroAristas;
    cin>>nroNodos>>nroAristas;
    for (int i =0; i < nroAristas; i++) {
        int nodoInicio, nodofinal, peso;
        cin>>nodoInicio>>nodofinal>>peso;
        //una opcion es esta
        pair<int,int> arista (peso, nodofinal);
        grafo[nodoInicio].push_back(arista);
        //tambien se podria con 
        //grafo[nodoInicio].push_back(make_pair(peso,nodofinal));
    }
    for(int i = 0; i < nroNodos; i++){
        cout<<"["<<i<<"]";
        for(int j = 0; j<grafo[i].size(); j++){
            cout<<"("<<grafo[i][j].first<<","<<grafo[i][j].second<<")";
        }
        cout<<endl;
    }
}