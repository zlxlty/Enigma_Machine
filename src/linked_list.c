/*
* =================================================
*       Filename:  linked_list.c
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#include "linked_list.h"

Rotorhead *InitRotor(void)
{
    Rotorhead *pRh = (Rotorhead *)malloc(sizeof(Rotorhead));

    if (pRh == NULL)
    {
        fprintf(stderr, ERRORMSG, "InitRotor: can not acquire space for rotorhead");
        return NULL;
    }

    pRh->cnt = 0;
    pRh->down = NULL;
    return pRh;
}

int AddUnit(Rotorhead *pRh, const char lttr)
{
    Unit *pUt = (Unit *)malloc(sizeof(Unit));

    if (pUt == NULL)
    {
        fprintf(stderr, ERRORMSG, "AddUnit: can not acquire space for unit");
        return -1;
    }

    pUt->lttr = lttr;
    pUt->left = pUt->right = pUt->down = NULL;

    if (pRh->down == NULL)
    {
        pRh->cnt++;
        pRh->down = pUt;
        pUt->down = pRh->down;
        return 0;
    } else {
        Unit *ptemp = pRh->down;

        while (ptemp->down != pRh->down)
            ptemp = ptemp->down;

        pRh->cnt++;
        ptemp->down = pUt;
        pUt->down = pRh->down;
        return 0;
    }
}

int PrintUnits(Rotorhead *pRh)
{
    if (pRh == NULL)
    {
        fprintf(stderr, ERRORMSG, "PrintUnits: Rotorhead doesn't exist");
        return -1;
    }

    printf("There are %d units\n", pRh->cnt);

    Unit *ptemp = pRh->down;

    do {

        printf(" |%c| ->", ptemp->lttr);
        ptemp = ptemp->down;

    } while (ptemp != pRh->down);

    putchar('\n');

    return 0;
}

Unit *FindUnit(Rotorhead *pRh, const char lttr)
{
    if (pRh == NULL)
    {
        fprintf(stderr, ERRORMSG, "FindUnit: Rotorhead does't exist");
        return NULL;
    }

    Unit *ptemp = pRh->down;

    do {
        if (ptemp->lttr == lttr)
            return ptemp;
        ptemp = ptemp->down;
    } while(ptemp != pRh->down);


    printf("Can not find letter: %c\n", lttr);
    return NULL;
}

int RemoveRotor(Rotorhead *pRh)
{
    if (pRh == NULL)
    {
        fprintf(stderr, ERRORMSG,"RemoveRotor: rotorhead doesn't exist");
        return -1;
    }

    Unit *ptemp = pRh->down;
    Unit *pprev;

    do {
        pprev = ptemp;
        ptemp = ptemp->down;
        pprev->down = NULL;
        free((void *)pprev);
    } while (ptemp != pRh->down);

    pRh->down = NULL;
    pRh->cnt = 0;
    free((void *)pRh);

    return 0;
}

#if _LINKED_DEBUG_

int main(int argc, char const *argv[]) {

    Rotorhead *pRh1 = InitRotor();
    Unit *pUt1;

    AddUnit(pRh1, 'a');
    AddUnit(pRh1, 'b');
    AddUnit(pRh1, 'c');
    AddUnit(pRh1, 'f');

    PrintUnits(pRh1);

    pUt1 = FindUnit(pRh1, 'x');
    if (pUt1)
        pUt1->lttr = 'e';
    PrintUnits(pRh1);

    RemoveRotor(pRh1);
    pRh1 = NULL;
    PrintUnits(pRh1);

    return 0;
}

#endif
