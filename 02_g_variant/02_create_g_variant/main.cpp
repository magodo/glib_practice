/*************************************************************************
 Author: Zhaoting Weng
 Created Time: Thu 10 Nov 2016 01:10:07 PM CST
 File Name: main.cpp
 Description: 
 ************************************************************************/

#include <iostream>
#include <vector>

#include "glib.h"

using namespace std;

#define BRANCH_TUPLE_OF_ARRAY

#if defined(BRANCH_TUPLE_OF_ARRAY)
int main()
{
    vector<gint32> v {1,2,3, 4,5};
    GVariantBuilder g_builder;
    GVariant *gvariant;

    g_variant_builder_init(&g_builder, G_VARIANT_TYPE("(ai)"));
    g_variant_builder_open(&g_builder, G_VARIANT_TYPE("ai"));
    
    for (vector<gint32>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        g_variant_builder_add_value(&g_builder, g_variant_new("i", *it));
    }

    g_variant_builder_close(&g_builder);
    gvariant = g_variant_builder_end(&g_builder);
    {
        GVariantIter *iter;
        int i;

        g_variant_get(gvariant, "(ai)", &iter);
        while (g_variant_iter_loop(iter, "i", &i))
            g_print("%i\n", i);
        g_variant_iter_free(iter);
    }
    
    //g_variant_unref(gvariant);

}

#elif defined(BRANCH_ARRAY)
int main()
{
    vector<gint32> v{1,2,3};
    GVariant *gvariant;
    GVariantBuilder gbuilder;

    g_variant_builder_init(&gbuilder, G_VARIANT_TYPE("ai")); // initialize a GVariantBuilder, associated memory is alloc'd
    for (vector<gint32>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        g_variant_builder_add_value(&gbuilder, g_variant_new("i", *it));
    }

    gvariant = g_variant_builder_end(&gbuilder);

    {
        GVariantIter iter;
        gint32 i;

        g_variant_iter_init(&iter, gvariant);
        while (g_variant_iter_loop(&iter, "i", &i))
            g_print("%i\n", i);
    }
    
    g_variant_unref(gvariant);

}

#elif defined(BRANCH_TUPLE)

int main()
{
    GVariant *gvariant;

    gvariant = g_variant_new("(ii)", 1, 2);
    {
        int i, j;
        g_variant_get(gvariant, "(ii)", &i, &j);
        g_print("%i, %i\n", i, j);
    }
    g_variant_unref(gvariant);

}

#endif
