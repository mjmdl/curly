#include <gtk/gtk.h>

#include "app.h"

int
main (int   argc,
      char *argv[])
{
  GApplication *app = curly_app_new ();
  return g_application_run (app, argc, argv);
}
