/*
* =================================================
*       Filename:  input.h
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#ifndef _INPUT_H_
#define _INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "settings.h"

typedef struct _key {
    char *order;
    char *pos;
    char *plugboard;
} Key;

Key *KeyInput(int filein, char *filename);
void RemoveKey(Key *);
char TextInput(void);
char *StringInput(int size);
void KeyRotation(char *key);

#endif
