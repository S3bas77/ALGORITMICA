#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// con esto calculamos la distancia entre dos estaciones
double distancia(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
// Función para realizar BFS y verificar si se pueden alcanzar todas las estaciones
bool alance(int primerNodo, const vector<vector<int>>& graph, int ToEstaciones) {
    vector<bool> vis(ToEstaciones, false);
    queue<int> q;
    q.push(primerNodo);
    vis[primerNodo] = true;
    int contador = 1;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbor : graph[current]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
                contador++;
            }
        }
    }
    // Si alcanzamos todas las estaciones, entonces podemos llegar a todas
    return contador == ToEstaciones;
}

// Función para encontrar las dos estaciones más cercanas
vector<vector<int>> grafo(const vector<pair<int, int>>& estaciones) {
    int n = estaciones.size();
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        vector<pair<double, int>> distancias;

        // Calcular distancias a todas las demás estaciones
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dist = distancia(estaciones[i].first, estaciones[i].second, estaciones[j].first, estaciones[j].second);
                distancias.push_back({dist, j});
            }
        }

        // Ordenar las distancias, usando criterios de desempate
        sort(distancias.begin(), distancias.end(), [&](const pair<double, int>& a, const pair<double, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } else if (estaciones[a.second].first != estaciones[b.second].first) {
                return estaciones[a.second].first < estaciones[b.second].first;
            } else {
                return estaciones[a.second].second < estaciones[b.second].second;
            }
        });

        // Conectar la estación a sus dos más cercanas
        graph[i].push_back(distancias[0].second);
        graph[i].push_back(distancias[1].second);
    }

    return graph;
}

int main() {
    input;
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> estaciones(n);
        // Leer coordenadas de las estaciones
        for (int i = 0; i < n; i++) {
            cin >> estaciones[i].first
                >> estaciones[i].second;
        }
        // Construir el grafo conectando las dos estaciones más cercanas
        vector<vector<int>> graph = grafo
    (estaciones);
        // Verificar si se pueden alcanzar todas las estaciones desde la primera (nodo 0)
        bool isReachable = alance(0, graph, n);
        if (isReachable) {
            cout << "All stations can be reached." << endl;
        } else {
            cout << "There are stations that are unreachable." << endl;
        }
    }
    return 0;
}
