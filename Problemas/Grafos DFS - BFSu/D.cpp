#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Función para realizar BFS y determinar los nodos alcanzables desde un nodo inicial con un TTL dado
set<int> bfs_reachable(const map<int, vector<int>>& graph, int start, int ttl) {
    set<int> reachable;
    queue<pair<int, int>> q;  // (node, current TTL)
    q.push({start, ttl});

    while (!q.empty()) {
        auto [node, current_ttl] = q.front();
        q.pop();

        if (reachable.find(node) != reachable.end()) {
            continue;  // Si el nodo ya fue visitado, continuamos
        }

        reachable.insert(node);  // Marcamos el nodo como visitado

        if (current_ttl > 0) {  // Si el TTL es mayor que cero, podemos seguir explorando
            for (int neighbor : graph.at(node)) {
                if (reachable.find(neighbor) == reachable.end()) {
                    q.push({neighbor, current_ttl - 1});  // Decrementar el TTL y continuar la búsqueda
                }
            }
        }
    }

    return reachable;
}

int main() {
    int case_number = 1;  // Contador para los casos de prueba

    while (true) {
        int num_connections;
        cin >> num_connections;

        if (num_connections == 0) {
            break;  // Fin de la entrada
        }

        map<int, vector<int>> graph;  // Representación del grafo
        
        // Leer las conexiones para construir la red
        for (int i = 0; i < num_connections; i++) {
            int node1, node2;
            cin >> node1 >> node2;

            graph[node1].push_back(node2);  // Agregar conexión en ambas direcciones
            graph[node2].push_back(node1);
        }

        // Leer las consultas hasta que se encuentre la señal de terminación (0, 0)
        while (true) {
            int start, ttl;
            cin >> start >> ttl;

            if (start == 0 && ttl == 0) {
                break;  // Fin de las consultas para esta red
            }

            set<int> reachable = bfs_reachable(graph, start, ttl);  // Nodos alcanzables

            // Determinar el número total de nodos
            set<int> all_nodes;  // Conjunto de todos los nodos
            for (const auto& [node, _] : graph) {
                all_nodes.insert(node);
            }

            int not_reachable = all_nodes.size() - reachable.size();  // Nodos no alcanzables

            cout << "Case " << case_number << ": " << not_reachable 
                 << " nodes not reachable from node " << start 
                 << " with TTL = " << ttl << "." << endl;

            case_number++;  // Incrementar el número de caso para la siguiente consulta
        }
    }

    return 0;
}
