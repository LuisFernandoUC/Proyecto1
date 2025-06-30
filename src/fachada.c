#include "fachada.h"
#include <stdio.h>

static char buffer[100];

void procesar_y_mostrar(const Entradas *datos, GtkEntry **entradas, GtkWidget *etiqueta) {
    EstadoValidacion estado = validar_entradas_puras(datos);

    if (estado != VALIDACION_OK) {
        switch (estado) {
            case ERROR_VACIO:
                mostrar_error(NULL, "Debe completar ambos campos.");
                break;
            case ERROR_NO_ENTERO:
                mostrar_error(NULL, "Ingrese dos números enteros positivos.");
                break;
            case ERROR_NEGATIVO:
                mostrar_error(NULL, "Los números deben ser mayores a cero.");
                break;
            default:
                break;
        }
        return;
    }

    int a = atoi(datos->texto1);
    int b = atoi(datos->texto2);
    int resultado = calcular_mcm(a, b);

    snprintf(buffer, sizeof(buffer), "El MCM entre %s y %s es: %d",
             datos->texto1, datos->texto2, resultado);

    limpiar_entradas(entradas);
    actualizar_etiqueta(etiqueta, buffer);
}

GtkWidget* crear_ventana(const gchar *titulo, int ancho, int alto) {
    GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), titulo);
    gtk_window_set_default_size(GTK_WINDOW(ventana), ancho, alto);
    gtk_window_set_resizable(GTK_WINDOW(ventana), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(ventana), 15);
    g_signal_connect(ventana, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    return ventana;
}

GtkWidget* crear_etiqueta(const gchar *texto, GtkWidget *contenedor) {
    GtkWidget *label = gtk_label_new(texto);
    gtk_box_pack_start(GTK_BOX(contenedor), label, FALSE, FALSE, 0);
    return label;
}

GtkWidget* crear_boton(const gchar *texto, GtkWidget *contenedor, GCallback callback, gpointer datos) {
    GtkWidget *boton = gtk_button_new_with_label(texto);
    g_signal_connect(boton, "clicked", callback, datos);
    gtk_box_pack_start(GTK_BOX(contenedor), boton, FALSE, FALSE, 0);
    return boton;
}

void limpiar_entradas(GtkEntry **entradas) {
    gtk_entry_set_text(entradas[0], "");
    gtk_entry_set_text(entradas[1], "");
}

void actualizar_etiqueta(GtkWidget *etiqueta, const gchar *mensaje) {
    gtk_label_set_text(GTK_LABEL(etiqueta), mensaje);
}

void mostrar_error(GtkWidget *parent, const gchar *mensaje) {
    GtkWidget *dialogo = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,
                            GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "%s", mensaje);
    gtk_dialog_run(GTK_DIALOG(dialogo));
    gtk_widget_destroy(dialogo);
}
