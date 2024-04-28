#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Definición de los movimientos de un caballo
const vector<pair<int, int>> knight_moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
};

// Función para convertir una posición en formato de ajedrez a coordenadas numéricas
pair<int, int> chess_to_coords(const string& position) {
    int col = position[0] - 'a';
    int row = position[1] - '1';
    return {row, col};
}

// Función para verificar si una posición está dentro de los límites del tablero
bool is_within_bounds(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

// Función para encontrar la distancia mínima entre dos posiciones usando BFS
int minimum_knight_moves(const string& start, const string& end) {
    if (start == end) {
        return 0;  // Si las posiciones son iguales, no se requiere movimiento
    }

    auto [start_row, start_col] = chess_to_coords(start);
    auto [end_row, end_col] = chess_to_coords(end);

    queue<pair<int, int>> q;  // Cola para BFS
    unordered_map<int, unordered_map<int, bool>> visited;  // Registro de posiciones visitadas
    q.push({start_row, start_col});
    visited[start_row][start_col] = true;

    int moves = 0;  // Contador para el número de movimientos
    
    while (!q.empty()) {
        int level_size = q.size();
        
        // Para cada nivel en BFS
        for (int i = 0; i < level_size; i++) {
            auto [current_row, current_col] = q.front();
            q.pop();

            // Si llegamos a la posición final, retornamos el número de movimientos
            if (current_row == end_row && current_col == end_col) {
                return moves;
            }

            // Explorar todas las posibles movidas de un caballo
            for (const auto& move : knight_moves) {
                int new_row = current_row + move.first;
                int new_col = current_col + move.second;

                if (is_within_bounds(new_row, new_col) && !visited[new_row][new_col]) {
                    visited[new_row][new_col] = true;
                    q.push({new_row, new_col});
                }
            }
        }

        moves++;  // Incrementamos el número de movimientos por nivel en BFS
    }

    return -1;  // Esto no debería ocurrir porque siempre hay un camino entre dos celdas en un tablero de ajedrez
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            continue;  // Saltar líneas vacías
        }

        string start, end;
        stringstream ss(line);
        ss >> start >> end;

        int moves = minimum_knight_moves(start, end);  // Calcular el número mínimo de movimientos
        
        cout << "To get from " << start << " to " << end << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}
