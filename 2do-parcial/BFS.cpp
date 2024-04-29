#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
// bfs.cpp

// Función para implementar BFS
void bfs(const map<int, vector<int>>& graph, int start) {
    queue<int> q;  // Cola para BFS
    unordered_set<int> visitado;  // Conjunto para nodos visitados

    q.push(start);  // Agregar nodo inicial a la cola
    visitado.insert(start);

    while (!q.empty()) {
        int current = q.front();  // Obtener el primer elemento de la cola
        q.pop();

        cout << "Visitando vértice: " << current << endl;  // Acción al visitar el vértice

        // Explorar todos los vecinos no visitados
        for (int neighbor : graph.at(current)) {
            if (visitado.find(neighbor) == visitado.end()) {
                visitado.insert(neighbor);
                q.push(neighbor);  // Agregar a la cola para BFS
            }
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

    cout << "BFS a partir del vértice 1:\n";
    bfs(grafo, 1);  // BFS comenzando desde el vértice 1

    return 0;
}
