/*This part of program will print out the canvas based on the command line parameters 
entered at the beginning and any mommands entered later by the user*/
#include <stdio.h>
#include <stdlib.h>
#include "paint_canvas.h"

/**
 * Generate the empty canvas based on given information
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
*/
void generate_canvas(Paint* canvas) {
    canvas->painting = (char**)malloc(canvas->rows * sizeof(char*));
    for (int i = 0; i < canvas->rows; ++i) {
        canvas->painting[i] = (char*)malloc(canvas->columns * sizeof(char));
    }
    for (int i = 0; i < canvas->rows; ++i) {
        for (int j = 0; j < canvas->columns; ++j) {
            canvas->painting[i][j] = '*';
        }
    }
}

/**
 * Print the empty canvas along with row and column indices
 * @canvas: the defined struct that contains the information of the canvas
*/
void print_canvas (Paint canvas){
    for (int i = 0; i < canvas.rows; ++i) {
        printf("%d", canvas.rows - 1 - i);
        for (int j = 0; j < canvas.columns; ++j) {
        printf(" %c", canvas.painting[i][j]);
        }
        printf("\n");
    }
    printf(" ");
    for (int k = 0; k < canvas.columns; k++) {
        printf(" %d", k);
    }
    printf("\n");
}

