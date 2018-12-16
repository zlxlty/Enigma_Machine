/*
* =================================================
*       Filename:  linked_list.h
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#ifndef _LINKED_H_
#define _LINKED_H_

#include <stdio.h>
#include <stdlib.h>
#include "settings.h"

typedef struct _unit {
    char lttr;
    struct _unit *left;
    struct _unit *right;
    struct _unit *down;
} Unit;

typedef struct _rotorhead {
    int cnt;
    Unit *down;
} Rotorhead;

Rotorhead * InitRotor(void);
int AddUnit(Rotorhead *pRh, const char lttr);
int PrintUnits(Rotorhead *pRh);
Unit *FindUnit(Rotorhead *pRh, const char lttr);
int RemoveRotor(Rotorhead *pRh);

#endif
