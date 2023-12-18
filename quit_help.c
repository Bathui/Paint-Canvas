/*This part of program will quit the painting process immediately whenever the enter 'q' 
and display the help information whenever the user enters "h" as "help".*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Print out the helpful prompts when the user entered 'h'
*/
void print_help(){
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

/**
 * Quit the whole program when the user entered 'q'
*/
void quit_command (){
    exit(0);
}