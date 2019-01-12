/*
* =================================================
*       Filename:  rotorgroup.h
*        Version:  1.1.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#ifndef _ROTORGROUP_H_
#define _ROTORGROUP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "rotors.h"
#include "settings.h"

typedef struct _rotorgroup {
    Rotorhead *pAlphts[4];
    Rotorhead *pCiphts[4];
} Rotorgroup;

void RemoveRotorGroup(Rotorgroup *pRg);
Rotorgroup *SetEnigmaRotors(const char pos[3], const char key[4]);
char PlugboardEncryption(char plugboard[13], char lttr);
char RotorsEncryption(Rotorgroup *pRg, char lttr);

#endif
