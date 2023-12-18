paint.out: main.o check_validity.o paint_canvas.o free_canvas.o input_commands.o quit_help.o write_erase.o add_delete_resize.o save_load.o
		gcc -g -Wall -Werror -o paint.out main.o check_validity.o paint_canvas.o free_canvas.o input_commands.o quit_help.o write_erase.o add_delete_resize.o save_load.o

main.o: main.c check_validity.h paint_canvas.h free_canvas.h input_commands.h write_erase.h struct.h
		gcc -g -Wall -Werror -c main.c

check_validity.o: check_validity.c check_validity.h
		gcc -g -Wall -Werror -c check_validity.c

paint_canvas.o: paint_canvas.c paint_canvas.h
		gcc -g -Wall -Werror -c paint_canvas.c

free_canvas.o: free_canvas.c free_canvas.h
		gcc -g -Wall -Werror -c free_canvas.c

input_commands.o: input_commands.c input_commands.h
		gcc -g -Wall -Werror -c input_commands.c

quit_help.o: quit_help.c quit_help.h 
		gcc -g -Wall -Werror -c quit_help.c

write_erase.o: write_erase.c write_erase.h
		gcc -g -Wall -Werror -c write_erase.c

add_delete_resize.o: add_delete_resize.c add_delete_resize.h
		gcc -g -Wall -Werror -c add_delete_resize.c

save_load.o: save_load.c save_load.h
		gcc -g -Wall -Werror -c save_load.c
		
clean:
		rm -f *.o *.out

