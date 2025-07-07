#include <gtk/gtk.h>

static void text(GtkWidget *widget,gpointer data){
	g_print("Hello World");
}

static void text2(GtkWidget *widget,gpointer data){
	g_print("Ola Mundo");
}	

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "ContabilidadeOne");
    gtk_window_maximize(GTK_WINDOW(window));

    GtkWidget *button;
    GtkWidget *grid;


    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window),grid);


    button = gtk_button_new_with_label("Button 1");
    g_signal_connect(button,"clicked",G_CALLBACK(text),NULL);
    gtk_grid_attach(GTK_GRID(grid),button,0,0,1,1);

    button = gtk_button_new_with_label("Button 2");
    g_signal_connect(button,"clicked",G_CALLBACK(text2),NULL);
    gtk_grid_attach(GTK_GRID(grid),button,0,1,1,1);

    button = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button,"clicked",G_CALLBACK(gtk_window_destroy),window);
    gtk_grid_attach(GTK_GRID(grid),button,1,0,1,2);


    gtk_window_present(GTK_WINDOW(window));

}


int main(int argc, char *argv[]){
    GtkApplication *app = gtk_application_new("com.contabilidade.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
