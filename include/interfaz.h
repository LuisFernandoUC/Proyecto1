#ifndef INTERFACE_H
#define INTERFACE_H

#include <gtk/gtk.h>

// Declaración de funciones para la interfaz gráfica
GtkWidget* crear_ventana_principal(void);
GtkEntry** crear_campos_entrada(GtkWidget *contenedor);
GtkWidget* crear_etiqueta_resultado(GtkWidget *contenedor);
GtkWidget* crear_boton_calculo(GtkWidget *contenedor, GtkEntry **entradas, GtkWidget *etiqueta_resultado);
void al_presionar_calcular(GtkButton *boton, gpointer datos_usuario);
void al_presionar_reiniciar(GtkButton *boton, gpointer datos_usuario);
void construir_interfaz(void);

#endif
