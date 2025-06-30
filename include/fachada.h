#ifndef FACHADA_H
#define FACHADA_H

#include <gtk/gtk.h>
#include "logica.h"

GtkWidget* crear_ventana(const gchar *titulo, int ancho, int alto);
GtkWidget* crear_etiqueta(const gchar *texto, GtkWidget *contenedor);
GtkWidget* crear_boton(const gchar *texto, GtkWidget *contenedor, GCallback callback, gpointer datos);

void limpiar_entradas(GtkEntry **entradas);
void actualizar_etiqueta(GtkWidget *etiqueta, const gchar *mensaje);
void mostrar_error(GtkWidget *parent, const gchar *mensaje);

void procesar_y_mostrar(const Entradas *datos, GtkEntry **entradas, GtkWidget *etiqueta);

#endif
