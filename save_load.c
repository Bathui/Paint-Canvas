/*This part of program will save the current canvas to the file named file_name and load a canvas from 
the file with file_name. The structure of these files is the one that the user came up with in save.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "save_load.h"

/**
 * Save the current canvas to the file named by the user
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: the defined struct that comtains the information of how to modify the canvas
*/
void change_canvas_s (Paint* canvas, Command input) {
    FILE* fp = fopen(input.filename, "w");
    for (int i = 0; i < canvas->rows; i++) {
        for (int j = 0; j < canvas->columns; j++) {
             fprintf(fp, "%c", canvas->painting[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

/**
 * Load a canvas from the file with the name given by the user
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: the defined struct that contains the information of how to modify the canvas
*/
void change_canvas_l (Paint* canvas, Command input) {
    FILE* fp = fopen(input.filename, "r");
    char buffer;
    int countCol = 0;
    int countRow = 0;
    while (true) {
        fscanf(fp,"%c", &buffer);
        if (buffer == '\n') {
            break;
        }
        countCol++;
    }
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%c", &buffer);
    while (!feof(fp)) {
        if (buffer == '\n') {
            countRow++;
        }
        fscanf(fp, "%c", &buffer);
    }
    canvas->rows = countRow;
    canvas->columns = countCol;
  
    canvas->painting = (char**)realloc(canvas->painting, countRow * sizeof(char*));
    for (int i = 0; i < countRow; i++) {
        canvas->painting[i] = (char*)realloc(canvas->painting[i], countCol * sizeof(char));
    }
    fseek(fp, 0, SEEK_SET);
    int i = 0, j = 0;
    fscanf(fp, "%c", &buffer);
    while (!feof(fp)) {
        canvas->painting[i][j] = buffer;
        if (buffer == '\n') {
            i++;
            j = 0;
            fscanf(fp, "%c", &buffer);
            continue;
        }
        j++;
        fscanf(fp, "%c", &buffer);
    }
    
}