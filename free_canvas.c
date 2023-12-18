/*This part of program will free the allocated memory of canvas*/
#include <stdio.h>
#include <stdlib.h>
#include "free_canvas.h"

/**
 * Free the allocated memory of canvas
 * @canvas: the defined struct that contains the information of the canvas
*/
void free_canvas(Paint canvas){
    for (int i = 0; i < canvas.rows; ++i) {
        free(canvas.painting[i]);
    }
    free(canvas.painting);
} 