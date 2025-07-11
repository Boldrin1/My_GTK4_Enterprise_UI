#include <gtk/gtk.h>

int total = 0;
GtkWidget *label;

static void atualizar_label(){
    gchar *texto = g_strdup_printf("O valor total é: %d", total);
    gtk_label_set_text(GTK_LABEL(label), texto);
    g_free(texto);
}

static void adicionar(GtkWidget *widget, gpointer data) {
    total += 1;
    atualizar_label();
}

static void remover(GtkWidget *widget, gpointer data) {
    total -= 1;
    atualizar_label();
}


static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button_add;
    GtkWidget *button_remove;
    GtkWidget *grid;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"ContabilidadeOne");
    gtk_window_maximize(GTK_WINDOW(window));

    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window),grid);

    label = gtk_label_new("O valor total é: 0");
    gtk_grid_attach(GTK_GRID(grid),label,0,0,1,1);

    button_add = gtk_button_new_with_label("Adicionar");
    g_signal_connect(button_add,"clicked",G_CALLBACK(adicionar),NULL);
    gtk_grid_attach(GTK_GRID(grid),button_add,0,1,1,1);
    
    button_remove = gtk_button_new_with_label("Excluir");
    g_signal_connect(button_remove,"clicked",G_CALLBACK(remover),NULL);
    gtk_grid_attach(GTK_GRID(grid),button_remove,1,1,1,1);


    gtk_window_present(GTK_WINDOW(window));
}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("com.contabilidade.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
