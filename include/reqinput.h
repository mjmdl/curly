#ifndef CURLY_REQINPUT_H
#define CURLY_REQINPUT_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define REQ_INPUT_TYPE (req_input_get_type ())

G_DECLARE_FINAL_TYPE (ReqInput, req_input,
                      REQ, INPUT,
                      GtkBox)

GtkWidget *req_input_new (void);

G_END_DECLS

#endif // CURLY_REQINPUT_H
