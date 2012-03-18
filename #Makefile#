# This is the Makefile
# It gives a rule for the make utility to build programs based of their object files' dependencies

ALL= main.o member_def_addelete.o booklist_modify.o book_transactions.o book_funcs.o date_funcs.o
all: lybrari

lybrari : $(ALL)
	cc $(ALL) -o lybrari
	echo "\nThe executable created is 'lybrari'. To run the program, type the command './lybrari' in the command line\n"

main.o : main.c headers.h
	cc -c main.c	

member_def_addelete.o : member_def_addelete.c headers.h
	cc -c member_def_addelete.c

booklist_modify.o : booklist_modify.c headers.h
	cc -c booklist_modify.c

book_transactions.o : book_transactions.c headers.h
	cc -c book_transactions.c #book_funcs.o

book_funcs.o : book_funcs.c headers.h
	cc -c book_funcs.c #date_funcs.o

date_funcs.o : date_funcs.c headers.h
	cc -c date_funcs.c

clean: 
	rm $(ALL)

