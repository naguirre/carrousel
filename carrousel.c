#include <Elementary.h>

#include "carrousel.h"

#define NB_ITEMS 7

typedef struct _Carrousel_Item Carrousel_Item;

struct _Carrousel_Item
{
    Evas_Object *obj;
    Evas_Object *parent;
    Evas_Object *img;
    double angle;
    const char *filename;
};

static const char *files[] = {
    "fightclub.jpg",
    "forrestgump.jpg",
    "godfather.png",
    "inception.jpg",
    "pulpfiction.jpg",
    "thedarkknight.jpg",
    "titanic.jpg",
    "volaudessus.jpg"
};



Evas_Object *
carrousel_add(Evas_Object *parent)
{
    int i;
    Evas_Object *grid;
    Carrousel_Item *item;
    char buf[PATH_MAX];

    grid =  elm_grid_add(parent);
    elm_grid_size_set(grid, 800, 600);

    for (i = NB_ITEMS ; i >= 0; i--)
    {
        item = calloc(1, sizeof(Carrousel_Item));
        item->parent = grid;
        item->obj = elm_layout_add(grid);
        elm_layout_file_set(item->obj, PACKAGE_DATA_DIR"/themes/default/default.edj",
                            "carrousel/layout/item");
        evas_object_show(item->obj);
        elm_grid_pack(grid, item->obj, 0, 0, 0, 0);

    }
    return grid;
}
