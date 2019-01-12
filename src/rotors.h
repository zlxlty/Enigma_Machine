/*
* =================================================
*       Filename:  Rotors.h
*        Version:  1.1.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#ifndef _ROTORS_H_
#define _ROTORS_H_

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "settings.h"

Rotorhead *StringToRotor(const char *str, int size); //size is the number of characters in the str
int ConnectRotorPair(Rotorhead *pRh1, Rotorhead *pRh2, char klttr1, char klttr2);
int PrintRotorPair(Rotorhead *pRh1);

#endif
