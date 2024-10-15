#ifndef CURLY_APPWINDOW_H
#define CURLY_APPWINDOW_H

#include <gtk/gtk.h>

#include "app.h"

G_BEGIN_DECLS

#define CURLY_TYPE_APP_WINDOW (curly_app_window_get_type ())

G_DECLARE_FINAL_TYPE (CurlyAppWindow, curly_app_window,
                      CURLY, APP_WINDOW,
                      GtkApplicationWindow)

GtkWidget *curly_app_window_new (CurlyApp *app);
     
G_END_DECLS

#endif // CURLY_APPWINDOW_H
