#ifndef CHECK_VALIDITY_H
    #define CHECK_VALIDITY_H
    #include "quit_help.h"
    #include "struct.h"
    #include "write_erase.h"
    #include "paint_canvas.h"
    #include "add_delete_resize.h"
    #include "save_load.h"
    void commandline_validity(int argc, char** argv, Paint* canvas);
    void userCommand_validity (Paint* canvas, Command* input);
#endif