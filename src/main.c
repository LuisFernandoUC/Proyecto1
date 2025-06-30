#include <gtk/gtk.h>
#include "interfaz.h"

// Función principal del programa
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    construir_interfaz();
    gtk_main();
    return 0;
}
