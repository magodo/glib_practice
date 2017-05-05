/*
 * Generated by gdbus-codegen 2.48.1. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __A_H__
#define __A_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for Busname.ItfName */

#define TYPE_BUSNAME_ITF_NAME (busname_itf_name_get_type ())
#define BUSNAME_ITF_NAME(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_BUSNAME_ITF_NAME, BusnameItfName))
#define IS_BUSNAME_ITF_NAME(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_BUSNAME_ITF_NAME))
#define BUSNAME_ITF_NAME_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_BUSNAME_ITF_NAME, BusnameItfNameIface))

struct _BusnameItfName;
typedef struct _BusnameItfName BusnameItfName;
typedef struct _BusnameItfNameIface BusnameItfNameIface;

struct _BusnameItfNameIface
{
  GTypeInterface parent_iface;

  gboolean (*handle_foo_method) (
    BusnameItfName *object,
    GDBusMethodInvocation *invocation,
    GVariant *arg_byteArray);

};

GType busname_itf_name_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *busname_itf_name_interface_info (void);
guint busname_itf_name_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void busname_itf_name_complete_foo_method (
    BusnameItfName *object,
    GDBusMethodInvocation *invocation);



/* D-Bus method calls: */
void busname_itf_name_call_foo_method (
    BusnameItfName *proxy,
    GVariant *arg_byteArray,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean busname_itf_name_call_foo_method_finish (
    BusnameItfName *proxy,
    GAsyncResult *res,
    GError **error);

gboolean busname_itf_name_call_foo_method_sync (
    BusnameItfName *proxy,
    GVariant *arg_byteArray,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define TYPE_BUSNAME_ITF_NAME_PROXY (busname_itf_name_proxy_get_type ())
#define BUSNAME_ITF_NAME_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_BUSNAME_ITF_NAME_PROXY, BusnameItfNameProxy))
#define BUSNAME_ITF_NAME_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_BUSNAME_ITF_NAME_PROXY, BusnameItfNameProxyClass))
#define BUSNAME_ITF_NAME_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_BUSNAME_ITF_NAME_PROXY, BusnameItfNameProxyClass))
#define IS_BUSNAME_ITF_NAME_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_BUSNAME_ITF_NAME_PROXY))
#define IS_BUSNAME_ITF_NAME_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_BUSNAME_ITF_NAME_PROXY))

typedef struct _BusnameItfNameProxy BusnameItfNameProxy;
typedef struct _BusnameItfNameProxyClass BusnameItfNameProxyClass;
typedef struct _BusnameItfNameProxyPrivate BusnameItfNameProxyPrivate;

struct _BusnameItfNameProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  BusnameItfNameProxyPrivate *priv;
};

struct _BusnameItfNameProxyClass
{
  GDBusProxyClass parent_class;
};

GType busname_itf_name_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BusnameItfNameProxy, g_object_unref)
#endif

void busname_itf_name_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
BusnameItfName *busname_itf_name_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
BusnameItfName *busname_itf_name_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void busname_itf_name_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
BusnameItfName *busname_itf_name_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
BusnameItfName *busname_itf_name_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_BUSNAME_ITF_NAME_SKELETON (busname_itf_name_skeleton_get_type ())
#define BUSNAME_ITF_NAME_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_BUSNAME_ITF_NAME_SKELETON, BusnameItfNameSkeleton))
#define BUSNAME_ITF_NAME_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_BUSNAME_ITF_NAME_SKELETON, BusnameItfNameSkeletonClass))
#define BUSNAME_ITF_NAME_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_BUSNAME_ITF_NAME_SKELETON, BusnameItfNameSkeletonClass))
#define IS_BUSNAME_ITF_NAME_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_BUSNAME_ITF_NAME_SKELETON))
#define IS_BUSNAME_ITF_NAME_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_BUSNAME_ITF_NAME_SKELETON))

typedef struct _BusnameItfNameSkeleton BusnameItfNameSkeleton;
typedef struct _BusnameItfNameSkeletonClass BusnameItfNameSkeletonClass;
typedef struct _BusnameItfNameSkeletonPrivate BusnameItfNameSkeletonPrivate;

struct _BusnameItfNameSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  BusnameItfNameSkeletonPrivate *priv;
};

struct _BusnameItfNameSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType busname_itf_name_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (BusnameItfNameSkeleton, g_object_unref)
#endif

BusnameItfName *busname_itf_name_skeleton_new (void);


G_END_DECLS

#endif /* __A_H__ */