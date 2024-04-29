#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Clase para implementar una cola
class Queue {
private:
    queue<int> q;  // Cola subyacente

public:
    // Operación para agregar un elemento al final de la cola
    void enqueue(int x) {
        q.push(x);
    }

    // Operación para eliminar el elemento frontal de la cola
    void dequeue() {
        if (isEmpty()) {
            throw out_of_range("La cola está vacía");
        }
        q.pop();
    }

    // Operación para obtener el elemento frontal sin eliminarlo
    int front() {
        if (isEmpty()) {
            throw out_of_range("La cola está vacía");
        }
        return q.front();
    }

    // Verifica si la cola está vacía
    bool isEmpty() {
        return q.empty();
    }
};

// Ejemplo de uso
int main() {
    Queue cola;
    cola.enqueue(1);
    cola.enqueue(2);
    cola.enqueue(3);
    cout << "El frente de la cola es: " << cola.front() << endl;  // Debe ser 1
    cola.dequeue();
    cout << "Después de dequeue, el frente es: " << cola.front() << endl;  // Debe ser 2
    cout << "¿Está vacía la cola? " << (cola.isEmpty() ? "Sí" : "No") << endl;

    return 0;
}
