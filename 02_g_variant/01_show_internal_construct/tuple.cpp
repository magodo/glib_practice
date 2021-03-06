/*************************************************************************
 Author: Zhaoting Weng
 Created Time: Wed 26 Oct 2016 02:56:58 PM CST
 File Name: tuple.cpp
 Description: 
 ************************************************************************/

#include "glib.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;

#define GVARIANT_IS_SERIALISED_FORM(p_gvariant) (p_gvariant->state & 0x02)

//===================== Internal declarations ========================
//

struct _GVariantTypeInfo
{
  gsize fixed_size;
  guchar alignment;
  guchar container_class;
};
typedef struct _GVariantTypeInfo GVariantTypeInfo;

typedef void (* GBufferFreeFunc)                (void);

struct _GBuffer
{
  gconstpointer data;
  gsize size;

  /*< protected >*/
  GBufferFreeFunc free_func;

  /*< private >*/
  gint ref_count;
};
typedef struct _GBuffer GBuffer;


struct _GVariant
/* see below for field member documentation */
{
  GVariantTypeInfo *type_info;
  gsize size;

  union
  {
    struct
    {
      GBuffer *buffer;
      gconstpointer data;
    } serialised;

    struct
    {
      GVariant **children;
      gsize n_children;
    } tree;
  } contents;

  gint state;
  gint ref_count;
};

typedef struct _GVariant GVariant;
//=================================


void show_gvariant(GVariant *variant, int lvl)
{
    string head(lvl, ' ');
    cout << head + string("{\n")
         << head + string("  type_info\n")
         << head + string("  {\n")
         << head + string("    fixed_size: ") << variant->type_info->fixed_size << "\n"
         << head + string("    alignment: ") << variant->type_info->alignment << "\n"
         << head + string("    guchar: ") << variant->type_info->container_class << "\n"
         << head + string("  }\n")
         << head + string("  size: ") << variant->size << "\n"
         << head + string("  state: ") << variant->state<< "\n"
         << head + string("  ref_count: ") << variant->ref_count<< "\n";

    cout << head + string("  contents") << "\n";
    cout << head + string("  {") << "\n";
    if (!(GVARIANT_IS_SERIALISED_FORM(variant))) //
    {
        cout << head + string("    tree") << "\n";
        cout << head + string("    {") << "\n";
        int n_children = variant->contents.tree.n_children;
        cout << head + string("      n_children: ") << n_children << "\n";
        cout << head + string("      children:") << "\n";
        for (int i = 0; i < n_children; ++i)
            show_gvariant(*(variant->contents.tree.children + i), lvl+6); // TODO
        cout << head + string("    }") << "\n"; //  end brace of tree (+4)
    }
    else
    {
        const int *ptr = static_cast<const int*>(variant->contents.serialised.data);
        cout << head + string("    serialised") << "\n";
        cout << head + string("    {") << "\n";
        cout << head + string("      data: ") << *ptr << '\n';
        cout << head + string("    }") << "\n"; // end brace of serialised(+4)
    }
    cout << head + string("  }") << "\n"; // end brace of "content"
    cout << head + string("}") << "\n"; // end brace
}

int main()
{
    list<int> l {1,2,3,4,5};
	GVariantBuilder builder;
    GVariant *variant;

	g_variant_builder_init (&builder, G_VARIANT_TYPE ("(ai)"));
	g_variant_builder_open (&builder, G_VARIANT_TYPE ("ai"));

    for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        g_variant_builder_add_value(&builder, g_variant_new("i",*it));

	g_variant_builder_close (&builder);
	variant = g_variant_builder_end (&builder);

    {
        show_gvariant(variant, 0);

        GVariantIter *iter;
        int i;

        g_variant_get(variant, "(ai)", &iter);
        while (g_variant_iter_loop(iter, "i", &i))
            g_print("%i\n", i);
        g_variant_iter_free(iter);
    }

    g_variant_unref(variant);
}
