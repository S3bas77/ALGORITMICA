#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int BIT[10001];
int tamanhoVector;

void update(int posicion, int valor) {
    for(; posicion <= tamanhoVector; posicion += posicion & -posicion) {
        BIT[posicion] *= valor;  // Multiplicamos en la posición
    }
}

int query(int posicion) { 
    int result = 1;  // El producto neutro es 1, no 0
    for(; posicion > 0; posicion -= posicion & -posicion) {
        result *= BIT[posicion];  // Acumulamos multiplicando
    }
    return result; 
}

int query2(int inicio, int final) {
    return query(final) / query(inicio - 1);  // Dividimos para obtener el producto en el rango
}

// Nueva función para determinar el signo del producto en un rango
string multiplicar(int inicio, int final) {
    int product = query2(inicio, final);

    if (product > 0) return "Positivo";
    if (product < 0) return "Negativo";
    return "Cero";
}

int transformar(int valor) {
    if (valor > 0) return 1;
    if (valor < 0) return -1;
    return 0;
}

int main() {
    input;
    int queries; 
    cin >> tamanhoVector >> queries; 

    // Inicializamos el BIT con 1 en todas las posiciones
    fill(BIT, BIT + tamanhoVector + 1, 1);

    for (int i = 0; i < tamanhoVector; i++) {
        int x; cin >> x;
        x = transformar(x);  // Convertimos el número según la regla
        update(i + 1, x);  // Actualizamos usando 1-based indexing
    }

    for (int i = 1; i <= tamanhoVector; i++) {
        cout << "[" << BIT[i] << "]";
    }
    cout << endl;

    while (queries--) {
        int x, y; cin >> x >> y;
        cout << multiplicar(x, y) << endl;  // Usamos la nueva función multiplicar
    }

    return 0;
}
