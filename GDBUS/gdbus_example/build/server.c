/* Own header                                      */
#include "common.h"         /* Example bus defines */

/* System header                                   */
#include <gio/gio.h>        /* GIO  for dbus       */
#include <glib-2.0/glib.h>  /* GLIB for main loop  */

/* Generated headers */
#include "common-generated.h"

static GMainLoop         *l = NULL;
static ContiGdbusExample *s = NULL;

static gboolean
timer(gconstpointer p)
{
  conti_gdbus_example_emit_my_signal(s, "World");
  return TRUE;
}

static gboolean
method(ContiGdbusExample     *object,
       GDBusMethodInvocation *invocation,
       const gchar           *in_arg,
       gpointer               user_data)
{
  g_print("Received method call. Parameter: %s\n", in_arg);
  conti_gdbus_example_complete_my_method(object, invocation, "Hello world");

  return TRUE;
}

static void 
bus_acquired_cb(GDBusConnection *connection,
                const gchar     *bus_name,
                gpointer         user_data)
{
  GError *e = NULL;

  s = conti_gdbus_example_skeleton_new();

  conti_gdbus_example_set_my_property(s, "Hello World");
  (void) g_signal_connect(s, "handle-my-method", G_CALLBACK(method), NULL);

  (void) g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(s),
                                          connection,
                                          CONTI_GDBUS_EXAMPLE_OBJECT_PATH,
                                          &e);

  if(e != NULL)
  {
     g_print("Error: Failed to export object. Reason: %s\n", e->message);
     g_error_free(e);
     g_main_loop_quit(l);
  }
}

static void 
name_acquired_cb(GDBusConnection *connection,
                 const gchar     *bus_name,
                 gpointer         user_data)
{
  g_print("Acquired bus name: %s\n", CONTI_GDBUS_EXAMPLE_BUS_NAME);
}


static void 
name_lost_cb(GDBusConnection *connection,
             const gchar     *bus_name,
             gpointer         user_data)
{
  if(connection == NULL)
  {
    g_print("Error: Failed to connect to dbus.\n");
  }
  else
  {
    g_print("Error: Failed to obtain bus name: %s\n",
            CONTI_GDBUS_EXAMPLE_BUS_NAME);
  }

  g_main_loop_quit(l);
}


int main(void)
{
  g_type_init();   /* Init for usage of "g" types */

  l = g_main_loop_new(NULL, FALSE);

  (void) g_bus_own_name(CONTI_GDBUS_EXAMPLE_BUS,
                        CONTI_GDBUS_EXAMPLE_BUS_NAME,
                        G_BUS_NAME_OWNER_FLAGS_NONE,
                        &bus_acquired_cb,
                        &name_acquired_cb,
                        &name_lost_cb,
                        NULL,
                        NULL);

  g_timeout_add(1000, &timer, NULL);

  /* Blocking function. Triggers callbacks */
  g_main_loop_run(l);

  g_main_loop_unref(l);

  return 0;
}
