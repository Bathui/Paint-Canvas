/*This part of program will add a new row or column at the specified position, 
or delete a row or column at the specified position, or resize the canvas to be A by B big.*/
#include <stdio.h>
#include <stdlib.h>
#include "add_delete_resize.h"

/**
 * Add a new row or column on a specified location of the canvas
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: the defined struct that comtains the information of how to modify the canvas
*/
void change_canvas_a (Paint* canvas, Command input) {
    if(input.position == 'r') {
		canvas->painting = (char**)realloc(canvas->painting, (canvas->rows + 1) * sizeof(char*));
		canvas->painting[canvas->rows] = (char*)malloc(canvas->columns * sizeof(char));
		for (int i = canvas->rows - 1; i >= canvas->rows - input.d1; i--) {
			for (int j = 0; j < canvas->columns; j++) {
				canvas->painting[i + 1][j] = canvas->painting[i][j] ;
			}
		}
		for (int j = 0; j < canvas->columns; ++j) {
			canvas->painting[canvas->rows - input.d1][j] = '*';
		}
		canvas->rows += 1;
	}
	if (input.position == 'c') {
		for (int i = 0 ; i < canvas->rows; i++) {
			canvas->painting[i] = (char*)realloc(canvas->painting[i], (canvas->columns + 1) * sizeof(char));
		}
		for (int i = 0; i < canvas->rows; ++i) {
			for (int j = canvas->columns; j >= input.d1; j--) {
				canvas->painting[i][j + 1] = canvas->painting[i][j];
			}
		}
		for (int i = 0; i < canvas->rows; ++i) {
			canvas->painting[i][input.d1] = '*';
		}
		canvas->columns += 1;
	}   
}

/**
 * Delete a row or column on a specified location of the canvas
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: the defined struct that comtains the information of how to modify the canvas
*/
void change_canvas_d (Paint* canvas, Command input){
	if(input.position == 'r') {
		for (int i = canvas->rows - input.d1; i < canvas->rows; i++){
			for (int j = 0; j < canvas->columns; j++){
				canvas->painting[i - 1][j] = canvas->painting[i][j];
			}
		}
		canvas->painting = (char**)realloc(canvas->painting,(canvas->rows - 1) * sizeof(char*));
		canvas->rows -= 1;
	}
	if (input.position == 'c') {
		for (int i = 0; i < canvas->rows; i++){
			for (int j = input.d1 + 1; j < canvas->columns; j++){
				canvas->painting[i][j - 1] = canvas->painting[i][j];
			}
		}
		for (int i = 0; i < canvas->rows; i++){
			canvas->painting[i] = (char*)realloc(canvas->painting[i], (canvas->columns - 1) * sizeof(char));
		}
		canvas->columns -= 1;
	}
}

/**
 * Resize the canvas to be specified num_rows by num_cols big
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: the defined struct that comtains the information of how to modify the canvas
*/
void change_canvas_r (Paint* canvas, Command input){
	if (canvas->rows >= input.d1 && canvas->columns >= input.d2){
		int k = 0;
		for (int i = canvas->rows - input.d1; i < canvas->rows; i++) {
			for (int j = 0; j < input.d2; j++) {
				canvas->painting[k][j] = canvas->painting[i][j];
			}
			k++;
		}
		canvas->painting = (char**)realloc(canvas->painting, (input.d1) * sizeof(char*));
		for (int i = 0; i < input.d1; i++) {
			canvas->painting[i] = (char*)realloc(canvas->painting[i], input.d2 * sizeof(char));
		}
		canvas->rows = input.d1;
		canvas->columns = input.d2;
	}
	else{
		int k = 0; 
		canvas->painting = (char**)realloc(canvas->painting, input.d1 * sizeof(char*));
		for (int i = 0; i < input.d1; i++) {
			canvas->painting[i] = (char*)realloc(canvas->painting[i], input.d2 * sizeof(char));
		}
		for (int i = canvas->rows - 1; i >= 0; i--) {
			for (int j = 0; j < canvas->columns; j++) {
				canvas->painting[input.d1 - k - 1][j] = canvas->painting[i][j];
			}
            k++;
		}
		for (int i = 0; i < input.d1 - canvas->rows; i++) {
			for (int j = 0; j < input.d2; j++) {
				canvas->painting[i][j] = '*';
			}
		}
		for (int i = input.d1 - canvas->rows; i < input.d1; i++) {
			for (int j = canvas->columns; j < input.d2; j++) {
				canvas->painting[i][j] = '*';
			}
		}
		canvas->rows = input.d1;
		canvas->columns = input.d2;
	}
}