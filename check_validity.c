/*This part of program will check the validity of command line parameters and
the validity of every command entered by the user afterwards.*/
#include <stdio.h>
#include <stdlib.h>
#include "check_validity.h"

/**
 * Check the validity of command line parameters. If not valid, canvas should default to a 10 X 10. Otherwiese, save the valid information
 * @argc: the number of arguments entered by the user
 * @argv: contains the parameters of numbers of rows and columns
 * @canvas: the defined struct that contains the information of the canvas
*/
void commandline_validity (int argc, char** argv, Paint* canvas){
    if (argc != 1 && argc != 3){
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        canvas->rows = 10;
        canvas->columns = 10;
    }
    else if (argc == 1){
        canvas->rows = 10;
        canvas->columns = 10;
    }
    else{
        if (sscanf(argv[1], "%d", &canvas->rows) != 1 || sscanf(argv[2], "%d", &canvas->columns) != 1){
            if (sscanf(argv[1], "%d", &canvas->rows) != 1 && sscanf(argv[2], "%d", &canvas->columns) != 1){ 
                printf("The number of rows is not an integer.\n");
                printf("The number of columns is not an integer.\n");
            }
            else if (sscanf(argv[1], "%d", &canvas->rows) != 1){
                if (canvas->columns < 1){
                    printf("The number of rows is not an integer.\n");
                    printf("The number of columns is less than 1.\n");
                }
                else {
                    printf("The number of rows is not an integer.\n");
                } 
            }
            else if (sscanf(argv[2], "%d", &canvas->columns) != 1){
                if (canvas->rows < 1){
                    printf("The number of rows is less than 1.\n");
                    printf("The number of columns is not an integer.\n");
                }
                else {
                    printf("The number of columns is not an integer.\n");
                } 
            }
            printf("Making default board of 10 X 10.\n");
            canvas->rows = 10;
            canvas->columns = 10;
        }
        else {
            if (canvas->rows < 1 || canvas->columns < 1){
                if (canvas->rows < 1){
                    printf("The number of rows is less than 1.\n");
                }
                if (canvas->columns < 1){
                    printf("The number of columns is less than 1.\n");
                }
                printf("Making default board of 10 X 10.\n");
                canvas->rows = 10;
                canvas->columns = 10;
            }
        }
    }
}

/**
 * Check if the user's command inputs are valid. If yes, execute. Otherwise, shouw prompt and keep asking
 * @canvas: a pointer points to the defined struct that contains the information of the canvas
 * @input: a pointer points to the defined struct that comtains the information of how to modify the canvas
*/
void userCommand_validity (Paint* canvas, Command* input){
    scanf(" %c", &input->letter);
    if (input->letter == 'q' || input->letter == 'h' || input->letter == 'w' || input->letter == 'e' || input->letter == 'a'
    || input->letter == 'd' || input->letter == 'r' || input->letter == 's' || input->letter == 'l'){
        if (input->letter == 'q'){
            quit_command ();
        }
        else if (input->letter == 'h'){
            print_help();
            print_canvas (*canvas);
        }
        else {
            if (input->letter == 'w'){
                scanf(" %d %d %d %d", &input->d1, &input->d2, &input->d3, &input->d4);
                change_canvas_w (canvas,*input);
                print_canvas (*canvas);
            }
            else if (input->letter == 'e'){
                scanf(" %d %d", &input->d1, &input->d2);
                change_canvas_e(canvas, *input);
                print_canvas (*canvas);
            }
            else if (input->letter == 'a'){
                scanf(" %c %d", &input->position, &input->d1);
                change_canvas_a (canvas, *input);
                print_canvas (*canvas);
            }
            else if (input->letter == 'd'){
                scanf(" %c %d", &input->position, &input->d1);
                change_canvas_d (canvas, *input);
                print_canvas (*canvas);       
            }
            else if (input->letter == 'r'){
                scanf(" %d %d", &input->d1, &input->d2);
                change_canvas_r (canvas, *input);
                print_canvas (*canvas);
            }
            else if (input->letter == 's'){
                scanf(" %s", input->filename);
                change_canvas_s(canvas, *input);
                print_canvas (*canvas);
                
            }
            else if (input->letter == 'l'){
                scanf(" %s", input->filename);
                change_canvas_l(canvas, *input);
                print_canvas (*canvas);
            }
        }
    }
    else {
        printf("Unrecognized command. Type h for help.\n");
        printf("Enter your command: ");
    }   
}