#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Definición de las 8 direcciones para las adyacencias (horizontal, vertical y diagonal)
const vector<pair<int, int>> DIRECTIONS = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

// Función para verificar si una posición está dentro de los límites de la cuadrícula
bool dentro_de_limites(int r, int c, int filas, int columnas) {
    return r >= 0 && r < filas && c >= 0 && c < columnas;
}

// Función para contar el número de vecinos negros ('#') de un píxel
int contar_vecinos(const vector<vector<char>>& grid, int r, int c) {
    int vecinos = 0;
    for (const auto& dir : DIRECTIONS) {
        int new_r = r + dir.first;
        int new_c = c + dir.second;
        if (dentro_de_limites(new_r, new_c, grid.size(), grid[0].size()) && grid[new_r][new_c] == '#') {
            vecinos++;
        }
    }
    return vecinos;
}

// Función para usar DFS y explorar un conjunto de píxeles
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visitado, int r, int c) {
    visitado[r][c] = true;
    
    for (const auto& dir : DIRECTIONS) {
        int new_r = r + dir.first;
        int new_c = c + dir.second;
        
        if (dentro_de_limites(new_r, new_c, grid.size(), grid[0].size()) && !visitado[new_r][new_c] && grid[new_r][new_c] == '#') {
            dfs(grid, visitado, new_r, new_c);  // Continúa explorando
        }
    }
}

// Función para contar bucles cerrados en la cuadrícula
int contar_bucles(vector<vector<char>>& grid) {
    int filas = grid.size();
    int columnas = grid[0].size();
    
    vector<vector<bool>> visitado(filas, vector<bool>(columnas, false));
    int contador_bucles = 0;

    for (int r = 0; r < filas; r++) {
        for (int c = 0; c < columnas; c++) {
            if (grid[r][c] == '#' && !visitado[r][c]) {
                if (contar_vecinos(grid, r, c) == 2) {  // Verificar si es un bucle
                    contador_bucles++;  // Nuevo bucle encontrado
                    dfs(grid, visitado, r, c);  // Explorar y marcar como visitado
                }
            }
        }
    }
    return contador_bucles;  // Retorna el número total de bucles
}

int main() {
    int filas, columnas;

    while (cin >> filas >> columnas) {  // Leer el número de filas y columnas
        if (filas == 0 && columnas == 0) {
            break;  // Fin de la entrada
        }
        
        vector<vector<char>> grid(filas, vector<char>(columnas));
        
        for (int r = 0; r < filas; r++) {
            for (int c = 0; c < columnas; c++) {
                cin >> grid[r][c];
            }
        }

        int total_bucles = contar_bucles(grid);  // Contar los bucles cerrados en la cuadrícula
        cout << total_bucles << endl;  // Imprimir el resultado
    }
    
    return 0;
}
