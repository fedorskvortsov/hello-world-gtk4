#include <gtk/gtk.h>
//#include <glib/gstdio.h>
#include <stdio.h>

static void
print_hello(GtkWidget *widget, gpointer data)
{
	g_print("Hello World\n");
}

static void
show_label(GtkLabel *label)
{
	gtk_label_set_text(label, "Hello World!");
}

static void
activate(GtkApplication *app, gpointer user_data)
{
	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "builder.ui", NULL);

	GObject *window = gtk_builder_get_object(builder, "window");
	gtk_window_set_application(GTK_WINDOW(window), app);

	GObject *label = gtk_builder_get_object(builder, "label");

	GObject *button = gtk_builder_get_object(builder, "button");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(show_label), label);

	gtk_window_present(GTK_WINDOW(window));
	g_object_unref(builder);
}

int main(int argc, char **argv)
{
	GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

	int status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

