#include <bits/stdc++.h>
using namespace std;
#define input freopen("in.txt", "r", stdin)

const vector<pair<int, int>> movimientos = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, 
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
};

int minMovimiento(const string &comienzo, const string &final) {
    if (comienzo == final) return 0;
    auto coordenadas = [](const string &pos) { 
        return make_pair(pos[1] - '1', pos[0] - 'a'); 
    };
    auto limites = [](int r, int c) { 
        return r >= 0 && r < 8 && c >= 0 && c < 8; 
    };
    queue<pair<int, int>> q;
    unordered_set<int> visitado;

    auto [sr, sc] = coordenadas(comienzo); //sr= start row, sc= start column
    auto [er, ec] = coordenadas(final);    //er= end row, ec= end column
    q.push({sr, sc});
    visitado.insert(sr * 8 + sc);

    for (int moves = 0; !q.empty(); ++moves) {
        for (int i = q.size(); i--; ) {
            auto [r, c] = q.front(); q.pop();
            if (r == er && c == ec) return moves;
            for (const auto &[dr, dc] : movimientos) {
                int nr = r + dr, nc = c + dc, idx = nr * 8 + nc;
                if (limites(nr, nc) && !visitado.count(idx)) {
                    q.push({nr, nc});
                    visitado.insert(idx);
                }
            }
        }
    }
    return 0; 
}
int main() {
    input;
    string comienzo, final;
    while (cin >> comienzo >> final) {
        cout << "To get from " << comienzo << " to " << final << 
        " takes " << minMovimiento(comienzo, final) << " knight moves." << endl;
    }
    return 0;
}
