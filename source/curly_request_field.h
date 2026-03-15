#ifndef CURLY_REQUEST_FIELD_H
#define CURLY_REQUEST_FIELD_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CURLY_TYPE_REQUEST_FIELD curly_request_field_get_type()

G_DECLARE_FINAL_TYPE(CurlyRequestField, curly_request_field, CURLY, REQUEST_FIELD, GtkBox)

CurlyRequestField *curly_request_field_new(void);
void curly_request_field_set_request_body_buffer(CurlyRequestField *http, GtkTextBuffer *buffer);
void curly_request_field_set_response_body_buffer(CurlyRequestField *http, GtkTextBuffer *buffer);

G_END_DECLS

#endif // CURLY_REQUEST_FIELD_H
