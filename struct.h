 #ifndef STRUCT_H
    #define STRUCT_H
    typedef struct Paint_struct{
        int rows;
        int columns;
        char** painting;
    } Paint;

    typedef struct Command_struct{
        char letter;
        char* filename;
        char position;
        int d1;
        int d2;
        int d3;
        int d4;
    } Command;
#endif
