/*
* =================================================
*       Filename:  settings.c
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#define _LINKED_DEBUG_ 0
#define _ROTORS_DEBUG_ 0
#define _GROUP_DEBUG_  0
#define _INPUT_DEBUG_  0
#define _MAIN_DEBUG_   0
#define _MAIN_         1

#define ERRORMSG "\x1b[31mError: \x1b[0m\x1b[4m%s\n\x1b[0m"
#define EXITMSG  "\x1b[1m\x1b[4mThanks For Using Enigma!\n\n\n\n\x1b[0m"

#define _plugboard "AHLOCJKXWERO"
#define _rotor1    "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define _rotor2    "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define _rotor3    "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define _rotor4    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define _reflector "YRUHQSLDPXNGOKMIEBFZCWVJAT"
#define _alphabet  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define MAXINPUT 1000

#endif
