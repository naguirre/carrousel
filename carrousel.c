#include <Elementary.h>

#include "carrousel.h"

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
    Evas_Object *grid;
    
    grid =  elm_grid_add(parent);
    evas_object_grid_size_set(grid, 800, 600);

    return grid;
}
