#include "logica.h"
#include <ctype.h>
#include <stdlib.h>

bool es_entero_valido(const char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isdigit(texto[i])) return false;
    }
    return true;
}

EstadoValidacion validar_entradas_puras(const Entradas *datos) {
    if (datos->texto1[0] == '\0' || datos->texto2[0] == '\0')
        return ERROR_VACIO;
    if (!es_entero_valido(datos->texto1) || !es_entero_valido(datos->texto2))
        return ERROR_NO_ENTERO;
    int num1 = atoi(datos->texto1);
    int num2 = atoi(datos->texto2);
    if (num1 <= 0 || num2 <= 0)
        return ERROR_NEGATIVO;
    return VALIDACION_OK;
}

Entradas leer_datos(GtkEntry **entradas) {
    const gchar *texto1 = gtk_entry_get_text(entradas[0]);
    const gchar *texto2 = gtk_entry_get_text(entradas[1]);
    Entradas datos = { texto1, texto2 };
    return datos;
}

int calcular_mcd(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int calcular_mcm(int a, int b) {
    return (a * b) / calcular_mcd(a, b);
}
