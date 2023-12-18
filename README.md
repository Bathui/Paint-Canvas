# Paint Canvas project algorithms

##  Paint of canvas
1. Ask for the canvas information and print out.
2. Ask for commands and print out.
## Ask for the canvas information and print out
1. Let the user to enter the number of rows and columns.
2. If not enter anything or invalid numbers or forms, the canvas should default to a size of 10 X 10.
3. The blank spaces will be denoted with "*".
4. Rows and columns will be labeled with numbers starting from 0.
4. Print out the starting canvas determined by the user or the default canvas.
## Ask for commands and print out
### Quit and help
  - Enter "q" as "quit": this will quit the painting process immediately.
  - Enter "h" as "help": this will display the help information.
### Write, erase and resize
  - Enter "w A B C D" as "write": this will draw a line from position (A,B) to (C,D). Horizontal lines are drawn with "-"; vertical lines are drawn with "|"; right diagonal lines are drawn with "/"; left diagonal lines are drawn with "\". If a line you are drawing intersects with another line a "+" should be drawn at the intersection. Overlapping with the same character should continue to be drawn with the same character.
   
  - Enter "e A B" as "erase": this will erase the character at (A,B) and revert it back to a blank space "*".
   
  - Enter "r A B" as "resize"(resize the canvas): We assume the original canvas is m by n, and the user resize the canvas to a by b.
      1. **If the user resize the canvas to a bigger one.** 
         - New rows (a-m) are added to the top of the canvas; new columns (b-n) are added to the right of the canvas, and new rows are added to the top of the canvas. **PS: new rows and columns are empty.** 
      2. **If the user resize the canvas to a smaller one**. We assume the original canvas is m by n, and the user resize to a by b. The right (n-b) columns will be deleted. Also, the top (m-a) rows will be deleted. If there are some contents by the previous actions like "write", they will also be deleted at the same time along with the the shrink of rows and columns.
### Add and delete
  - Enter "a r X" or "a c X" as "add": this will add a new row or column at the specified position. 'r' stands for row and 'c' stands for column. Valid values for position are between 0 and num of rows and columns based on whether a row or column is specified. If adding a row, the row at that position and all rows above are moved up 1; if adding a column, the column at that position and all columns to the right are moved to the right by 1.
  
  - Enter "d r X" or "d c X" as "delete": this will delete a row or column at the specified position. Valid values for position are between 0 and the number of rows/columns - 1. If deleting a row, all the rows above the one deleted are shifted down by 1; if deleting a column, all the columns to the right of the one deleted are shifted to the left by 1.
### Save and Load file
  - Enter "s file_name" as "save": this will save the current canvas to the  file named file_name and show the canvas we save to the user.
  
  - Enter "l file_name" as "load": this will load a canvas from the file with file_name and show the canvas we load from the file chosen by the user.
### Invalid input (start of the game and during the game )
  - **Invalid input at the start of the game**
      - If the user enters in invalid input you should ask them for a new command until they enter a valid command.
  
      - If each time the user enters a valid command, then the changed canvas based on that command will be printed out.
  
  - **Invalid input during the game**
  
    - If the user types the wrong mode (not write, add, delete, erase, resize, save, load mode), tell them they chose an improper mode, which cannot be recognized, and let them keep entering the mode and ask the "help" mode for help until they enter the correct mode.
  
    - If the user types invalid number of numbers we used in each mode, tell them improper input and let them keep entering until they type the correct input. (ex: w 1  the user only type one number, it should be four number)
  
    - If the user types some gibberish (like letters) as the numbers, tell them improper input and let them keep entering until they type the correct input. (ex: w asd/ asddj sdsd sds    user should type 4 numbers after the w, but the user typed four gibberish, so it should be invalid).
