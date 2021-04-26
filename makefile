all: main.c generate_dataset.o sort_int.o sort_string.o
		gcc main.c generate_dataset.o sort_int.o sort_string.o -o main

generate_dataset.o:  generate_dataset.c generate_dataset.h
		gcc -c generate_dataset.c -o generate_dataset.o

sort_int.o: sort_int.c sort_int.h
		gcc -c sort_int.c -o sort_int.o

sort_string.o: sort_string.c sort_string.h
		gcc -c sort_string.c -o sort_string.o

clean:
		rm -f sort_string.o sort_int.o main
