#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

// Función para calcular el total de días acumulados hasta cada grupo
vector<int> dias_acumulados(int max_grupo) {
    vector<int> acumulados(max_grupo + 1);
    acumulados[0] = 0;  // No hay días antes del primer grupo
    for (int i = 1; i <= max_grupo; i++) {
        acumulados[i] = acumulados[i - 1] + i;
    }
    return acumulados;
}

// Función para calcular el total de monedas pagadas al caballero dados ciertos días
int monedas_totales(int dias) {
    int grupo = 1;  // Empezamos desde el primer grupo
    int acumulados = 1;  // Días acumulados en el primer grupo
    
    // Encontrar el grupo donde cae el día especificado
    while (acumulados < dias) {
        grupo++;
        acumulados += grupo;
    }
    
    // Días acumulados antes del grupo actual
    int prev_acumulados = acumulados - grupo;

    // Calcular las monedas para los grupos completos antes del grupo actual
    int total_monedas = 0;
    for (int i = 1; i < grupo; i++) {
        total_monedas += i * i;  // i días * i monedas por día
    }
    
    // Calcular monedas para los días restantes dentro del grupo actual
    int dias_adicionales = dias - prev_acumulados;
    total_monedas += dias_adicionales * grupo;

    return total_monedas;
}

int main() {
    int bloques_prueba;
    cin >> bloques_prueba;  // Número de bloques de prueba

    // Leer cada bloque de casos de prueba
    for (int bloque = 0; bloque < bloques_prueba; bloque++) {
        int cuenta_dias;
        
        while (cin >> cuenta_dias && cuenta_dias != 0) {
            int monedas = monedas_totales(cuenta_dias);  // Calcular las monedas totales para los días dados
            cout << cuenta_dias << " " << monedas << endl;
        }

        // Si no es el último bloque, imprimir una línea en blanco entre bloques
        if (bloque < bloques_prueba - 1) {
            cout << endl;
        }
    }

    return 0;
}
