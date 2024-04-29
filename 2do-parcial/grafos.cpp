#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
// Clase para implementar un grafo
class Graph {
private:
    map<int, vector<int>> adjacency_list;  // Lista de adyacencia para almacenar aristas

public:
    // Agregar vértice al grafo
    void add_vertex(int v) {
        if (adjacency_list.find(v) == adjacency_list.end()) {
            adjacency_list[v] = vector<int>();
        }
    }

    // Agregar arista al grafo (para grafos no dirigidos)
    void add_edge(int v1, int v2) {
        adjacency_list[v1].push_back(v2);
        adjacency_list[v2].push_back(v1);
    }

    // Mostrar el grafo
    void print_graph() {
        for (const auto& [vertex, neighbors] : adjacency_list) {
            cout << vertex << ": ";
            for (int neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// Ejemplo de uso
int main() {
    Graph grafo;
    grafo.add_vertex(1);
    grafo.add_vertex(2);
    grafo.add_vertex(3);
    grafo.add_edge(1, 2);
    grafo.add_edge(2, 3);
    grafo.add_edge(1, 3);

    cout << "Grafo:\n";
    grafo.print_graph();  // Imprimir la lista de adyacencia

    return 0;
}
