#include <Elementary.h>

#include "carrousel.h"

#ifndef ELM_LIB_QUICKLAUNCH

static void
_win_del(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
    elm_exit();
}


EAPI_MAIN int
elm_main(int argc EINA_UNUSED, char **argv EINA_UNUSED)
{
    Evas_Object *win;
    Evas_Object *ly;
    Evas_Object *carrousel;

    win = elm_win_add(NULL, "main", ELM_WIN_BASIC);
    elm_win_title_set(win, "EFL Demo");
    evas_object_smart_callback_add(win, "delete,request", _win_del, NULL);

    ly = elm_layout_add(win);
    elm_layout_file_set(ly,
                        PACKAGE_DATA_DIR"/themes/default/default.edj",
                        "layout");
    elm_win_resize_object_add(win, ly);
    evas_object_show(ly);

    carrousel = carrousel_add(ly);
    evas_object_show(carrousel);
    elm_object_part_content_set(ly, "carrousel.swallow", carrousel);

    evas_object_resize(win, 800, 600);
    evas_object_show(win);
    
    elm_run();

    elm_shutdown();
    return EXIT_SUCCESS;
}

#endif

ELM_MAIN()
