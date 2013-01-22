#include <Elementary.h>

#include "carrousel.h"

#define NB_ITEMS 8

#define ICON_SIZE_W 128
#define ICON_SIZE_H 192
#define WIDTH 800
#define HEIGHT 600
#define PADDING 32

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

static Eina_List *items = NULL;

static Eina_Bool
_anim(void)
{
    Carrousel_Item *item;
    Eina_List *l;
    Evas_Coord x, y, w, h;
    double scale = 0.0;

    EINA_LIST_FOREACH(items, l, item)
    {
        scale = 0.5 + (1.0 + cos(item->angle)) / 2.0;
        y =  128 * scale;
        x = WIDTH / 2.0 + (sin(item->angle) * (WIDTH / 2.0)) - ICON_SIZE_W  / 2.0;
        w = ICON_SIZE_W * scale;
        h = ICON_SIZE_H * scale;
        elm_grid_pack_set(item->obj, x, y, w, h);
    }
 
    return ECORE_CALLBACK_RENEW;
}

Evas_Object *
carrousel_add(Evas_Object *parent)
{
    int i;
    Evas_Object *grid;
    Evas_Object *img;
    Carrousel_Item *item;
    char buf[PATH_MAX];
    double theta_inc = (double)(2 * M_PI) / (double)NB_ITEMS;
    double theta = 0;

    grid =  elm_grid_add(parent);
    elm_grid_size_set(grid, 800, 600);

    for (i = NB_ITEMS -1 ; i >= 0; i--)
    {
        item = calloc(1, sizeof(Carrousel_Item));
        item->parent = grid;
        item->obj = elm_layout_add(grid);
        elm_layout_file_set(item->obj, PACKAGE_DATA_DIR"/themes/default/default.edj",
                            "carrousel/layout/item");
        snprintf(buf, sizeof(buf), PACKAGE_DATA_DIR"/images/%s",  files[i % 7]);
        img = evas_object_image_filled_add(evas_object_evas_get(item->obj));
        item->img = img;
        evas_object_image_file_set(img, buf, NULL);
        elm_object_part_content_set(item->obj, "cover.swallow", img);

        evas_object_show(item->obj);
        elm_grid_pack(grid, item->obj, 0, 0, 0, 0);
        item->angle =  theta;
        theta += theta_inc;

        items = eina_list_append(items, item);
    }

    _anim();

    return grid;
}
