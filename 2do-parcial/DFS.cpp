#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
// dfs.cpp

// Función para implementar DFS
void dfs(const map<int, vector<int>>& graph, int start, unordered_set<int>& visitado) {
    if (visitado.find(start) != visitado.end()) {
        return;  // Si ya fue visitado, retornamos
    }

    cout << "Visitando vértice: " << start << endl;  // Acción al visitar el vértice
    visitado.insert(start);  // Marcar como visitado

    // Explorar todos los vecinos no visitados
    for (int neighbor : graph.at(start)) {
        if (visitado.find(neighbor) == visitado.end()) {
            dfs(graph, neighbor, visitado);  // Llamada recursiva para DFS
        }
    }
}

// Ejemplo de uso
int main() {
    map<int, vector<int>> grafo;
    grafo[1] = {2, 3};  // Lista de adyacencia
    grafo[2] = {1, 4};
    grafo[3] = {1};
    grafo[4] = {2};

    unordered_set<int> visitado;  // Conjunto para nodos visitados

    cout << "DFS a partir del vértice 1:\n";
    dfs(grafo, 1, visitado);  // DFS comenzando desde el vértice 1

    return 0;
}
