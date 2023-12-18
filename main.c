/*This program will paint a canvas based on the information and commands provided by the user*/
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "check_validity.h"
#include "paint_canvas.h"
#include "free_canvas.h"
#include "input_commands.h"

/**
 * The function integrates the whole painting process  given by user commands
 * @argc: the number of arguments entered by the user
 * @argv: the user's inputs which contains rows and columns of the canvas
*/
int main (int argc, char** argv){
    Paint canvas;
    Command input;
    input.letter = '\0';
    input.position = '\0';
    input.filename = (char*)malloc(50*sizeof(char));
    
    commandline_validity(argc, argv, &canvas);
    generate_canvas (&canvas);
    print_canvas (canvas);
    user_input (canvas, input);
    free_canvas(canvas);
    free(input.filename);
	return 0;
}
