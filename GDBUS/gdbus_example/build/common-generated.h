/*
 * Generated by gdbus-codegen 2.32.4. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __COMMON_GENERATED_H__
#define __COMMON_GENERATED_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for com.contiautomotive.Gdbus.Example */

#define CONTI_TYPE_GDBUS_EXAMPLE (conti_gdbus_example_get_type ())
#define CONTI_GDBUS_EXAMPLE(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), CONTI_TYPE_GDBUS_EXAMPLE, ContiGdbusExample))
#define CONTI_IS_GDBUS_EXAMPLE(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), CONTI_TYPE_GDBUS_EXAMPLE))
#define CONTI_GDBUS_EXAMPLE_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), CONTI_TYPE_GDBUS_EXAMPLE, ContiGdbusExampleIface))

struct _ContiGdbusExample;
typedef struct _ContiGdbusExample ContiGdbusExample;
typedef struct _ContiGdbusExampleIface ContiGdbusExampleIface;

struct _ContiGdbusExampleIface
{
  GTypeInterface parent_iface;



  gboolean (*handle_my_method) (
    ContiGdbusExample *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_InArg);

  const gchar * (*get_my_property) (ContiGdbusExample *object);

  void (*my_signal) (
    ContiGdbusExample *object,
    const gchar *arg_Value);

};

GType conti_gdbus_example_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *conti_gdbus_example_interface_info (void);
guint conti_gdbus_example_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void conti_gdbus_example_complete_my_method (
    ContiGdbusExample *object,
    GDBusMethodInvocation *invocation,
    const gchar *OutArg);



/* D-Bus signal emissions functions: */
void conti_gdbus_example_emit_my_signal (
    ContiGdbusExample *object,
    const gchar *arg_Value);



/* D-Bus method calls: */
void conti_gdbus_example_call_my_method (
    ContiGdbusExample *proxy,
    const gchar *arg_InArg,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean conti_gdbus_example_call_my_method_finish (
    ContiGdbusExample *proxy,
    gchar **out_OutArg,
    GAsyncResult *res,
    GError **error);

gboolean conti_gdbus_example_call_my_method_sync (
    ContiGdbusExample *proxy,
    const gchar *arg_InArg,
    gchar **out_OutArg,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
const gchar *conti_gdbus_example_get_my_property (ContiGdbusExample *object);
gchar *conti_gdbus_example_dup_my_property (ContiGdbusExample *object);
void conti_gdbus_example_set_my_property (ContiGdbusExample *object, const gchar *value);


/* ---- */

#define CONTI_TYPE_GDBUS_EXAMPLE_PROXY (conti_gdbus_example_proxy_get_type ())
#define CONTI_GDBUS_EXAMPLE_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), CONTI_TYPE_GDBUS_EXAMPLE_PROXY, ContiGdbusExampleProxy))
#define CONTI_GDBUS_EXAMPLE_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), CONTI_TYPE_GDBUS_EXAMPLE_PROXY, ContiGdbusExampleProxyClass))
#define CONTI_GDBUS_EXAMPLE_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), CONTI_TYPE_GDBUS_EXAMPLE_PROXY, ContiGdbusExampleProxyClass))
#define CONTI_IS_GDBUS_EXAMPLE_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), CONTI_TYPE_GDBUS_EXAMPLE_PROXY))
#define CONTI_IS_GDBUS_EXAMPLE_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), CONTI_TYPE_GDBUS_EXAMPLE_PROXY))

typedef struct _ContiGdbusExampleProxy ContiGdbusExampleProxy;
typedef struct _ContiGdbusExampleProxyClass ContiGdbusExampleProxyClass;
typedef struct _ContiGdbusExampleProxyPrivate ContiGdbusExampleProxyPrivate;

struct _ContiGdbusExampleProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  ContiGdbusExampleProxyPrivate *priv;
};

struct _ContiGdbusExampleProxyClass
{
  GDBusProxyClass parent_class;
};

GType conti_gdbus_example_proxy_get_type (void) G_GNUC_CONST;

void conti_gdbus_example_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
ContiGdbusExample *conti_gdbus_example_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
ContiGdbusExample *conti_gdbus_example_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void conti_gdbus_example_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
ContiGdbusExample *conti_gdbus_example_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
ContiGdbusExample *conti_gdbus_example_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define CONTI_TYPE_GDBUS_EXAMPLE_SKELETON (conti_gdbus_example_skeleton_get_type ())
#define CONTI_GDBUS_EXAMPLE_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), CONTI_TYPE_GDBUS_EXAMPLE_SKELETON, ContiGdbusExampleSkeleton))
#define CONTI_GDBUS_EXAMPLE_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), CONTI_TYPE_GDBUS_EXAMPLE_SKELETON, ContiGdbusExampleSkeletonClass))
#define CONTI_GDBUS_EXAMPLE_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), CONTI_TYPE_GDBUS_EXAMPLE_SKELETON, ContiGdbusExampleSkeletonClass))
#define CONTI_IS_GDBUS_EXAMPLE_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), CONTI_TYPE_GDBUS_EXAMPLE_SKELETON))
#define CONTI_IS_GDBUS_EXAMPLE_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), CONTI_TYPE_GDBUS_EXAMPLE_SKELETON))

typedef struct _ContiGdbusExampleSkeleton ContiGdbusExampleSkeleton;
typedef struct _ContiGdbusExampleSkeletonClass ContiGdbusExampleSkeletonClass;
typedef struct _ContiGdbusExampleSkeletonPrivate ContiGdbusExampleSkeletonPrivate;

struct _ContiGdbusExampleSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  ContiGdbusExampleSkeletonPrivate *priv;
};

struct _ContiGdbusExampleSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType conti_gdbus_example_skeleton_get_type (void) G_GNUC_CONST;

ContiGdbusExample *conti_gdbus_example_skeleton_new (void);


G_END_DECLS

#endif /* __COMMON_GENERATED_H__ */
