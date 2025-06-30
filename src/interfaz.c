#include "fachada.h"
#include "eventos.h"

GtkWidget* crear_ventana_contenedor(GtkWidget **contenedor) {
    GtkWidget *ventana = crear_ventana("Calculadora de MCM", 750, 375);
    *contenedor = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_container_add(GTK_CONTAINER(ventana), *contenedor);
    return ventana;
}

GtkEntry** crear_campos_entrada(GtkWidget *contenedor) {
    GtkEntry **entradas = g_new(GtkEntry *, 2);
    entradas[0] = GTK_ENTRY(gtk_entry_new());
    entradas[1] = GTK_ENTRY(gtk_entry_new());

    gtk_entry_set_placeholder_text(entradas[0], "Ingrese el primer número");
    gtk_entry_set_placeholder_text(entradas[1], "Ingrese el segundo número");

    gtk_box_pack_start(GTK_BOX(contenedor), GTK_WIDGET(entradas[0]), FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(contenedor), GTK_WIDGET(entradas[1]), FALSE, FALSE, 0);

    return entradas;
}

void crear_botonera(GtkWidget *contenedor, GtkEntry **entradas, GtkWidget *etiqueta) {
    GtkWidget *boton_calcular = crear_boton("Calcular MCM", contenedor, G_CALLBACK(manejar_calculo), entradas);
    g_object_set_data(G_OBJECT(boton_calcular), "etiqueta_resultado", etiqueta);

    GtkWidget *boton_reiniciar = crear_boton("Reiniciar", contenedor, G_CALLBACK(manejar_reinicio), entradas);
    g_object_set_data(G_OBJECT(boton_reiniciar), "etiqueta_resultado", etiqueta);

    crear_boton("Salir", contenedor, G_CALLBACK(gtk_main_quit), NULL);
}

void construir_interfaz(void) {
    GtkWidget *contenedor;
    GtkWidget *ventana = crear_ventana_contenedor(&contenedor);

    GtkEntry **entradas = crear_campos_entrada(contenedor);
    GtkWidget *etiqueta = crear_etiqueta("", contenedor);

    crear_botonera(contenedor, entradas, etiqueta);

    gtk_widget_show_all(ventana);
}
