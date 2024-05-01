#include <bits/stdc++.h>
using namespace std;

#define input freopen("in.txt", "r", stdin)

// Función para calcular la distancia entre dos puntos
inline double distancia(pair<int, int> a, pair<int, int> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

// Función de BFS para verificar si todas las estaciones son alcanzables
bool alance(int primerNodo, const vector<vector<int>>& graph, int totalEstaciones) {
    vector<bool> visitado(totalEstaciones, false);
    queue<int> q;
    q.push(primerNodo);
    visitado[primerNodo] = true;
    int alcanzados = 1;

    while (!q.empty() && alcanzados < totalEstaciones) {
        int nodo = q.front(); q.pop();
        for (int vecino : graph[nodo]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                q.push(vecino);
                alcanzados++;
            }
        }
    }

    return alcanzados == totalEstaciones;
}

// Construir el grafo conectando las dos estaciones más cercanas
vector<vector<int>> grafo(const vector<pair<int, int>>& estaciones) {
    int n = estaciones.size();
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        vector<pair<double, int>> distancias;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                distancias.push_back({distancia(estaciones[i], estaciones[j]), j});
            }
        }

        sort(distancias.begin(), distancias.end());

        graph[i].push_back(distancias[0].second);
        graph[i].push_back(distancias[1].second);
    }

    return graph;
}

int main() {
    input;
    int n;
    while (cin >> n && n) {
        vector<pair<int, int>> estaciones(n);
        for (auto &est : estaciones) {
            cin >> est.first >> est.second;
        }

        auto graph = grafo(estaciones);
        cout << (alance(0, graph, n) ? "All stations can be reached." : "There are stations that are unreachable.") << endl;
    }
}
