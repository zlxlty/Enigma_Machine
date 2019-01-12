/*
* =================================================
*       Filename:  Rotors.c
*        Version:  1.1.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#include "rotors.h"

Rotorhead *StringToRotor(const char *str, int size) //size is the number of characters in the str
{
    Rotorhead *pRh = InitRotor();
    int i;

    for (i = 0; i < size; i++)
        AddUnit(pRh, str[i]);

    return pRh;
}

int ConnectRotorPair(Rotorhead *pRh1, Rotorhead *pRh2, char klttr1, char klttr2)
{
    if (pRh1->cnt != pRh2->cnt || pRh1 == NULL || pRh2 == NULL)
    {
        fprintf(stderr, ERRORMSG, "ConnectTwoRotors: rotorheads error");
        return -1;
    }

    //create keyrotor
    Rotorhead *pRhAlpht = StringToRotor(_alphabet, 26);

    Unit* pAtemp = pRhAlpht->down;
    Unit* pAunit1 = FindUnit(pRhAlpht, klttr1);
    Unit* pAunit2 = FindUnit(pRhAlpht, klttr2);
    Unit* pRunit1 = pRh1->down;
    Unit* pRunit2 = pRh2->down;

    //connect keyrotor with the first rotor
    do {
        pAunit1->left = pRunit1;
        pAunit1 = pAunit1->down;
        pRunit1 = pRunit1->down;

    } while (pAunit1->lttr != klttr1);

    //connect keyrotor with the second rotor
    do {
        pAunit2->right = pRunit2;
        pAunit2 = pAunit2->down;
        pRunit2 = pRunit2->down;

    } while (pAunit2->lttr != klttr2);

    do {
        pAtemp->right->left = pAtemp->left;
        pAtemp->left->right = pAtemp->right;
        pAtemp = pAtemp->down;

    } while (pAtemp != pRhAlpht->down);

    RemoveRotor(pRhAlpht);

    return 0;

}

int PrintRotorPair(Rotorhead *pRh1)
{
    Unit *ptemp = pRh1->down;
    do {
        printf("|%c|=|%c|\n", ptemp->lttr, ptemp->right ? ptemp->right->lttr : ptemp->left->lttr);
        ptemp = ptemp->down;
    } while (ptemp != pRh1->down);
}

#if _ROTORS_DEBUG_

int main(int argc, char const *argv[]) {

    Rotorhead *pref = StringToRotor(_alphabet, 26);
    // PrintUnits(pref);
    Rotorhead *prot1 = StringToRotor(_rotor1, 26);
    // PrintUnits(prot1);
    ConnectRotorPair(pref, prot1, 'A', 'T');
    Unit *temp = FindUnit(pref, 'D');
    PrintRotorPair(prot1);

    return 0;
}

#endif
