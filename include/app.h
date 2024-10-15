#ifndef CURLY_APP_H
#define CURLY_APP_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CURLY_TYPE_APP (curly_app_get_type ())

G_DECLARE_FINAL_TYPE (CurlyApp, curly_app,
		      CURLY, APP,
		      GtkApplication)

GApplication *curly_app_new (void);     

G_END_DECLS

#endif // CURLY_APP_H
