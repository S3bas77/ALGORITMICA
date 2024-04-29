#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Clase para implementar una pila
class Stack {
private:
    vector<int> stack;  // Contenedor para almacenar elementos

public:
    // Operación para insertar un elemento en la pila
    void push(int x) {
        stack.push_back(x);
    }

    // Operación para eliminar el elemento superior de la pila
    void pop() {
        if (isEmpty()) {
            throw out_of_range("La pila está vacía");
        }
        stack.pop_back();
    }

    // Operación para obtener el elemento superior sin eliminarlo
    int peek() {
        if (isEmpty()) {
            throw out_of_range("La pila está vacía");
        }
        return stack.back();
    }

    // Verifica si la pila está vacía
    bool isEmpty() {
        return stack.empty();
    }
};

// Ejemplo de uso
int main() {
    Stack pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    cout << "El tope de la pila es: " << pila.peek() << endl;  // Debe ser 3
    pila.pop();
    cout << "Después de pop, el tope es: " << pila.peek() << endl;  // Debe ser 2
    cout << "¿Está vacía la pila? " << (pila.isEmpty() ? "Sí" : "No") << endl;

    return 0;
}
