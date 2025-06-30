#ifndef EVENTOS_H
#define EVENTOS_H

#include <gtk/gtk.h>
#include "logica.h"
#include "fachada.h"

void manejar_calculo(GtkButton *boton, gpointer datos_usuario);
void manejar_reinicio(GtkButton *boton, gpointer datos_usuario);

#endif
