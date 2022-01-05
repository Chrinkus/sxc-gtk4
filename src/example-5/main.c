#include <gtk/gtk.h>

#include "example_app.h"

int main(int argc, char* argv[])
{
	/* During development the schema will be installed in the
	 * build directory. This line tells GTK where to find it.
	 */
	g_setenv("GSETTINGS_SCHEMA_DIR", ".", FALSE);

	return g_application_run(G_APPLICATION(example_app_new()), argc, argv);
}

