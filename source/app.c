#include <gtk/gtk.h>

#include "app.h"
#include "appwindow.h"

struct _CurlyApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE (CurlyApp, curly_app,
               GTK_TYPE_APPLICATION)

static void
curly_app_init (CurlyApp *app)
{
}

static void
curly_app_activate (GApplication *application)
{
  GtkWidget *window = app_window_new (CURLY_APP (application));
  gtk_window_present (GTK_WINDOW (window));
}

static void
curly_app_class_init (CurlyAppClass *klass)
{
  G_APPLICATION_CLASS(klass)->activate = curly_app_activate;
}

GApplication *
curly_app_new (void)
{
  return g_object_new (CURLY_APP_TYPE,
                       "application-id", "com.github.mjmdl.curly",
                       "flags", G_APPLICATION_DEFAULT_FLAGS,
                       NULL);
}
