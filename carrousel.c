#include <Elementary.h>

#include "carrousel.h"

Evas_Object *
carrousel_add(Evas_Object *parent)
{
    Evas_Object *grid;

    grid =  elm_grid_add(parent);
    evas_object_grid_size_set(grid, 800, 600);

    return grid;
}
