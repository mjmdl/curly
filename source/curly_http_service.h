#ifndef CURLY_HTTP_SERVICE_H
#define CURLY_HTTP_SERVICE_H

#include <glib-object.h>

G_BEGIN_DECLS

#define CURLY_TYPE_HTTP_SERVICE curly_http_service_get_type()

G_DECLARE_FINAL_TYPE(CurlyHttpService, curly_http_service, CURLY, HTTP_SERVICE, GObject)

CurlyHttpService *curly_http_service_new(void);
gboolean curly_http_service_perform(CurlyHttpService *http, const char *verb, const char *address);
void curly_http_service_set_request_body_buffer(CurlyHttpService *http, GtkTextBuffer *buffer);
void curly_http_service_set_response_body_buffer(CurlyHttpService *http, GtkTextBuffer *buffer);

G_END_DECLS

#endif // CURLY_HTTP_SERVICE_H
