/*This part of program will draw a line from position (A,B) to (C,D) or erase the character at (A,B) 
and revert it back to a blank space "*".If a line you are drawing intersects with another line a "+" 
should be drawn at the intersection.*/
#include <stdio.h>
#include <stdlib.h>
#include "write_erase.h"

/**
 * Draw a line between two specified locations on the canvas. When two different lines intersect, draw a '+' on the intersection
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: the defined struct that comtains the information of how to modify the canvas
*/
void change_canvas_w (Paint* canvas, Command input){
    // '/'
    if (input.d1 < input.d3 && input.d2 < input.d4){
        int j = input.d2;
        for (int i = canvas->rows - input.d1 - 1; i >= canvas->rows - input.d3 - 1; i--) {
            if (canvas->painting[i][j] == '\\' || canvas->painting[i][j] == '-' || canvas->painting[i][j] == '|' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '/';
            }
            j++;
        }
    }
    if (input.d1 > input.d3 && input.d2 > input.d4){
        int j = input.d4;
        for (int i = canvas->rows - input.d3 - 1; i >= canvas->rows - input.d1 - 1; i--) {
            if (canvas->painting[i][j] == '\\' || canvas->painting[i][j] == '-' || canvas->painting[i][j] == '|' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '/';
            }
            j++;
        }
    }
    // '\'
    if (input.d1 > input.d3 && input.d2 < input.d4){
        int j = input.d2;
        for (int i = canvas->rows - input.d1 - 1; i <= canvas->rows - input.d3 - 1; i++) {
            if (canvas->painting[i][j] == '/' || canvas->painting[i][j] == '-' || canvas->painting[i][j] == '|' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '\\';
            }
            j++;
        } 
    }
    if (input.d1 < input.d3 && input.d2 > input.d4){
        int j = input.d4;
        for (int i = canvas->rows - input.d3 - 1; i <= canvas->rows - input.d1 - 1; i++) {
            if (canvas->painting[i][j] == '/' || canvas->painting[i][j] == '-' || canvas->painting[i][j] == '|' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '\\';
            }
            j++;
        } 
    }
    // '-'
    if (input.d1 == input.d3 && input.d2 < input.d4){
        int i = canvas->rows - input.d1 - 1;
        for (int j = input.d2; j <= input.d4; ++j){
            if (canvas->painting[i][j] == '/' || canvas->painting[i][j] == '\\' || canvas->painting[i][j] == '|' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '-';
            }
        }
    }
    if (input.d1 == input.d3 && input.d2 > input.d4){
        int i = canvas->rows - input.d1 - 1;
        for (int j = input.d4; j <= input.d2; ++j){
            if (canvas->painting[i][j] == '/' || canvas->painting[i][j] == '\\' || canvas->painting[i][j] == '|' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '-';
            }
        }
    }
    // '|'
    if (input.d2 == input.d4 && input.d1 < input.d3){
        int j = input.d2;
        for (int i = canvas->rows - input.d1 - 1; i >= canvas->rows - input.d3 -1; --i){
            if (canvas->painting[i][j] == '/' || canvas->painting[i][j] == '\\' || canvas->painting[i][j] == '-' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '|';
            }
        }
    }
    if (input.d2 == input.d4 && input.d1 > input.d3){
        int j = input.d2;
        for (int i = canvas->rows - input.d3 - 1; i >= canvas->rows - input.d1 -1; --i){
            if (canvas->painting[i][j] == '/' || canvas->painting[i][j] == '\\' || canvas->painting[i][j] == '-' || canvas->painting[i][j] == '+'){
                canvas->painting[i][j] = '+';
            }
            else {
                canvas->painting[i][j] = '|';
            }
        }
    }
    if (input.d2 == input.d4 && input.d1 == input.d3){
        int i = canvas->rows - input.d1 - 1;
        int j = input.d2;
        if (canvas->painting[i][j] == '\\' || canvas->painting[i][j] == '/' || canvas->painting[i][j] == '|' || canvas->painting[i][j] == '+'){
            canvas->painting[i][j] = '+';
        }
        else{
            canvas->painting[i][j] = '-';
        }
    }
    
}

/**
 * Erase a specified location of the canvas by converting the character on it to '*'
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: the defined struct that comtains the information of how to modify the canvas
*/
void change_canvas_e (Paint* canvas, Command input){
    canvas->painting[canvas->rows - input.d1 - 1][input.d2] = '*';
}