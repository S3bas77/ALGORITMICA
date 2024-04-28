#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// con esto calculamos la distancia entre dos estaciones
double distance(int x1, int y1, int x2, int y2) {
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
vector<vector<int>> buildGraph(const vector<pair<int, int>>& stations) {
    int n = stations.size();
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        vector<pair<double, int>> distances;

        // Calcular distancias a todas las demás estaciones
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dist = distance(stations[i].first, stations[i].second, stations[j].first, stations[j].second);
                distances.push_back({dist, j});
            }
        }

        // Ordenar las distancias, usando criterios de desempate
        sort(distances.begin(), distances.end(), [&](const pair<double, int>& a, const pair<double, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } else if (stations[a.second].first != stations[b.second].first) {
                return stations[a.second].first < stations[b.second].first;
            } else {
                return stations[a.second].second < stations[b.second].second;
            }
        });

        // Conectar la estación a sus dos más cercanas
        graph[i].push_back(distances[0].second);
        graph[i].push_back(distances[1].second);
    }

    return graph;
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<pair<int, int>> stations(n);

        // Leer coordenadas de las estaciones
        for (int i = 0; i < n; i++) {
            cin >> stations[i].first
                >> stations[i].second;
        }

        // Construir el grafo conectando las dos estaciones más cercanas
        vector<vector<int>> graph = buildGraph(stations);

        // Verificar si se pueden alcanzar todas las estaciones desde la primera (nodo 0)
        bool allReachable = alance(0, graph, n);

        if (allReachable) {
            cout << "All stations can be reached." << endl;
        } else {
            cout << "Not all stations can be reached." << endl;
        }
    }

    return 0;
}
