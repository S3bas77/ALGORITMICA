#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Definición de las 8 direcciones posibles (adyacencias)
const vector<pair<int, int>> direcciones = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

// Función para verificar si una posición está dentro de los límites de la cuadrícula
bool is_within_bounds(int r, int c, int max_filas, int max_columnas) {
    return r >= 0 && r < max_filas && c >= 0 && c < max_columnas;
}

// Función para verificar si una celda es una estrella
bool is_star(const vector<vector<char>>& grid, int r, int c, int max_filas, int max_columnas) {
    if (grid[r][c] != '*') {
        return false;  // No es una estrella
    }
    
    // Verificar las adyacencias para asegurarse de que no tiene otros '*' adyacentes
    for (const auto& dir : direcciones) {
        int new_r = r + dir.first;
        int new_c = c + dir.second;
        
        if (is_within_bounds(new_r, new_c, max_filas, max_columnas) && grid[new_r][new_c] == '*') {
            return false;  // No es una estrella si tiene un vecino '*'
        }
    }
    
    return true;  // Es una estrella si no tiene vecinos '*'
}

int main() {
    while (true) {
        int filas, columnas;
        cin >> filas >> columnas;
        
        if (filas == 0 && columnas == 0) {
            break;  // Fin de la entrada
        }
        
        vector<vector<char>> grid(filas, vector<char>(columnas));
        
        // Leer la cuadrícula
        for (int r = 0; r < filas; r++) {
            for (int c = 0; c < columnas; c++) {
                cin >> grid[r][c];
            }
        }
        
        int contador = 0;  // Contador de estrellas
        
        // Buscar estrellas en la cuadrícula
        for (int r = 0; r < filas; r++) {
            for (int c = 0; c < columnas; c++) {
                if (is_star(grid, r, c, filas, columnas)) {
                    contador++;  // Incrementar el contador de estrellas
                }
            }
        }
        
        cout << contador << endl;  // Imprimir el número total de estrellas para esta cuadrícula
    }
    
    return 0;
}
