### README para `colas`
```markdown
# Implementación de Colas
Este directorio contiene una implementación en C++ de una cola (queue), con operaciones básicas como `enqueue`, `dequeue`, `front`, e `isEmpty`.

## Operaciones Básicas
- `enqueue(int x)`: Agrega un elemento al final de la cola.
- `dequeue()`: Elimina el elemento frontal de la cola.
- `front()`: Devuelve el elemento frontal sin eliminarlo.
- `isEmpty()`: Devuelve `true` si la cola está vacía y `false` si no lo está.

## Compilación y Ejecución
Para compilar el archivo `queue.cpp`, puedes usar el siguiente comando:

```bash
g++ -o colas colas.cpp

./colas
