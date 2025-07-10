#include <gtk/gtk.h>

static void adicionar(GtkWidget *widget,gpointer data){
	int i;
	i = i+1;
	int *ptr;
	ptr = &i;
}

static void remover(GtkWidget *widget,gpointer data){
	int x;
	x= x+1;
	int *ptr2;
	ptr2 = &x;
}


static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *grid;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"ContabilidadeOne");
    gtk_window_maximize(GTK_WINDOW(window));

    grid = gyk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window),grid);


    button = gtk_button_new_with_label("Adicionar");
    g_signal_connect(button,"activate",G_CALLBACK(adicionar),NULL);
    gtk_grid_attach(GTK_GRID(grid),button,0,0,1,1);

    
    button = gtk_button_new_with_label("Excluir");
    g_signal_connect(button,"activate",G_CALLBACK(button,"activate",G_CALLBACK(remover));
    gtk_grid_attach(GTK_GRID(grid),button,0,0,1,1);


    gtk_window_present(GTK_WINDOW(window));
}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("com.contabilidade.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
