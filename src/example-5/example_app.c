#include "example_app.h"
#include "example_app_win.h"

struct _ExampleApp {
	GtkApplication parent;
};

G_DEFINE_TYPE(ExampleApp, example_app, GTK_TYPE_APPLICATION);

static void example_app_init(ExampleApp* app)
{
	// Nothing yet..
}

static void example_app_activate(GApplication* app)
{
	ExampleAppWindow* win = example_app_window_new(EXAMPLE_APP(app));
	gtk_window_present(GTK_WINDOW(win));
}

static void example_app_open(GApplication* app, GFile** files, int num_files,
		const char* hint)
{
	GList* windows = gtk_application_get_windows(GTK_APPLICATION(app));

	ExampleAppWindow* win;
	if (windows)
		win = EXAMPLE_APP_WINDOW(windows->data);
	else
		win = example_app_window_new(EXAMPLE_APP(app));

	for (int i = 0; i < num_files; ++i)
		example_app_window_open(win, files[i]);

	gtk_window_present(GTK_WINDOW(win));
}

static void example_app_class_init(ExampleAppClass* class)
{
	G_APPLICATION_CLASS(class)->activate = example_app_activate;
	G_APPLICATION_CLASS(class)->open = example_app_open;
}

ExampleApp* example_app_new(void)
{
	return g_object_new(EXAMPLE_APP_TYPE,
			"application-id",
			"org.gtk.exampleapp",
			"flags",
			G_APPLICATION_HANDLES_OPEN,
			NULL);
}

