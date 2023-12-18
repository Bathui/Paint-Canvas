/*This part of program will execute every valid command entered by the user
and print out the corresponding canvas after every commmand*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input_commands.h"

/**
 * This part of program will continue asking for user's commands until a 'q' entered
 * @canvas: the defined struct that contains the information of the canvas
 * @input: the defined struct that comtains the information of how to modify the canvas
*/
void user_input (Paint canvas, Command input){
    printf("Enter your command: ");
    while (true){
    userCommand_validity (&canvas, &input);
    printf("Enter your command: ");
    }    
}