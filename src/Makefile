# =================================================
#       Filename:  Makefile
#        Version:  1.0.0
#        Created:  12/15/18 09:48:25
#   Make_Version:  GUN Make 4.1
#         Coding:  UTF-8
#         Author:  Tianyi Lu
# =================================================

objs = linked_list.o rotors.o rotorgroup.o input.o main.o

Enigma : $(objs)
	gcc -o Enigma $(objs)

linked_list.o : linked_list.c linked_list.h settings.h

rotors.o : rotors.c rotors.h linked_list.h settings.h

rotorgroup.o : rotorgroup.c rotorgroup.h linked_list.h rotors.h settings.h

input.o : input.c input.h settings.h

.PHONY : clean_objs run_e run_d

clean_objs :
	rm $(objs)

run_e :
	./Enigma -e

run_d :
	./Enigma -d
