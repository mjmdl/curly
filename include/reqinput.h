#ifndef CURLY_REQINPUT_H
#define CURLY_REQINPUT_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CURLY_TYPE_REQ_INPUT (curly_req_input_get_type ())

G_DECLARE_FINAL_TYPE (CurlyReqInput, curly_req_input,
                      CURLY, REQ_INPUT,
                      GtkBox)

GtkWidget *curly_req_input_new (void);

G_END_DECLS

#endif // CURLY_REQINPUT_H
