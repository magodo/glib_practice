/* Own header                                      */
#include "common.h"         /* Example bus defines */

/* System header                                   */
#include <gio/gio.h>        /* GIO  for dbus       */
#include <glib-2.0/glib.h>  /* GLIB for main loop  */

/* Generated headers */
#include "common-generated.h"

static GMainLoop         *l = NULL;
static GDBusConnection   *c = NULL;
static ContiGdbusExample *p = NULL;

static gboolean
timer(gconstpointer user_data)
{
  GError      *e       = NULL;
  const gchar *in_arg  = "Hello";
  gchar       *out_arg = NULL;

  g_print("Property retrieved. Value: %s\n", conti_gdbus_example_get_my_property(p));

  conti_gdbus_example_call_my_method_sync(p, in_arg, &out_arg, NULL, &e);

  if(e == NULL)
  {
    g_print("Method called. Return value: %s\n", out_arg);
    g_free(out_arg);
  }
  else
  {
    g_print("Failed to call method. Reason: %s\n", e->message);
    g_error_free(e);
  }

  return TRUE;
}

static gboolean
on_signal(ContiGdbusExample *object,
          const gchar       *arg,
          gpointer          user_data)
{
  g_print("Signal received. Paramater value: %s\n", arg);

  return TRUE;
}

int main(void)
{
  GError      *e       = NULL;

  g_type_init();   /* Init for usage of "g" types */

  g_print("Client started\n");

  c = g_bus_get_sync(CONTI_GDBUS_EXAMPLE_BUS, NULL, &e);

  if(e == NULL)
  {
    g_print("Connected to dbus.\n");

    p = conti_gdbus_example_proxy_new_sync(c,
                                           G_DBUS_PROXY_FLAGS_NONE,
                                           CONTI_GDBUS_EXAMPLE_BUS_NAME,
                                           CONTI_GDBUS_EXAMPLE_OBJECT_PATH,
                                           NULL,
                                           &e);

    if(e == NULL)
    {
        l = g_main_loop_new(NULL, FALSE);
        
        /* Callbacks for timer and signal, invoked from main loop */
        (void) g_signal_connect(p, "my-signal", G_CALLBACK(on_signal), NULL);
        g_timeout_add(1000, &timer, NULL);
        
        g_main_loop_run(l);
        
        g_main_loop_unref(l);
    }
    else
    {
      g_print("Error: Failed to create proxy. Reason: %s\n", e->message);
      g_error_free(e);
    }
  }
  else
  {
    g_print("Error: Failed to connect to dbus. Reason: %s\n", e->message);
    g_error_free(e);
  }


  return 0;
}
