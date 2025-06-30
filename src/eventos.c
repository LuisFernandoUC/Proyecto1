#include "eventos.h"

void manejar_calculo(GtkButton *boton, gpointer datos_usuario) {
    GtkEntry **entradas = (GtkEntry **)datos_usuario;
    const gchar *texto1 = gtk_entry_get_text(entradas[0]);
    const gchar *texto2 = gtk_entry_get_text(entradas[1]);

    Entradas datos = { texto1, texto2 };
    GtkWidget *etiqueta = g_object_get_data(G_OBJECT(boton), "etiqueta_resultado");
    procesar_y_mostrar(&datos, entradas, etiqueta);
}

void manejar_reinicio(GtkButton *boton, gpointer datos_usuario) {
    GtkEntry **entradas = (GtkEntry **)datos_usuario;
    GtkWidget *etiqueta = g_object_get_data(G_OBJECT(boton), "etiqueta_resultado");
    procesar_y_mostrar(&datos, entradas, etiqueta);
}
