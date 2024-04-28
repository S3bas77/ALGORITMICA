#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Definición de direcciones para las adyacencias
const vector<pair<int, int>> direcciones = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

// Función para verificar si una posición está dentro de los límites de la cuadrícula
bool is_within_bounds(int r, int c, int m, int n) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

// Función para realizar Depth-First Search para marcar celdas como visitadas
void dfs(vector<vector<char>>& grid, 
vector<vector<bool>>& visitado, int r, int c, int m, int n) {
    visitado[r][c] = true;
    
    // Explorar todas las direcciones adyacentes
    for (const auto& direccion : direcciones) {
        int new_r = r + direccion.first;
        int new_c = c + direccion.second;
        
        if (is_within_bounds(new_r, new_c, m, n) && !visitado[new_r][new_c] && grid[new_r][new_c] == '@') {
            dfs(grid, visitado, new_r, new_c, m, n);
        }
    }
}

// Función para contar los depósitos de petróleo en la cuadrícula
int contador(vector<vector<char>>& grid, int m, int n) {
    vector<vector<bool>> visitado(m, vector<bool>(n, false));
    int count = 0;  // Contador de depósitos
    
    // Explorar todas las celdas de la cuadrícula
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (!visitado[r][c] && grid[r][c] == '@') {
                count++;  // Encontramos un nuevo depósito
                dfs(grid, visitado, r, c, m, n);  // Marcar todas las celdas conectadas
            }
        }
    }
    
    return count;  // Retornar el número total de depósitos
}

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;
        
        if (m == 0 && n == 0) {
            break;  // Fin de la entrada
        }
        
        vector<vector<char>> grid(m, vector<char>(n));
        
        // Leer la cuadrícula
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                cin >> grid[r][c];
            }
        }
        
        int depositado = contador(grid, m, n);  // Contar los depósitos
        cout << depositado << endl;  // Imprimir el resultado
    }

    return 0;
}
