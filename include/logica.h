#ifndef LOGICA_H
#define LOGICA_H

#include <stdbool.h>

typedef struct {
    const char *texto1;
    const char *texto2;
} Entradas;

typedef enum {
    VALIDACION_OK,
    ERROR_VACIO,
    ERROR_NO_ENTERO,
    ERROR_NEGATIVO
} EstadoValidacion;

bool es_entero_valido(const char *texto);
EstadoValidacion validar_entradas_puras(const Entradas *datos);

int calcular_mcd(int a, int b);
int calcular_mcm(int a, int b);
Entradas leer_datos(GtkEntry **entradas);


#endif
