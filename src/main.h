/*
* =================================================
*       Filename:  main.h
*        Version:  1.1.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include "settings.h"
#include "linked_list.h"
#include "rotors.h"
#include "rotorgroup.h"
#include "input.h"

#define MAXLEN 1000

struct {
    unsigned int encrypt : 1;
    unsigned int decrypt : 1;
    unsigned int filein  : 1;
} flags;

#endif
