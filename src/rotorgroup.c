/*
* =================================================
*       Filename:  rotorgroup.c
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#include "rotorgroup.h"

Rotorgroup *InitRotorGroup()
{
    Rotorgroup *pRg = (Rotorgroup *)malloc(sizeof(Rotorgroup));
    int i;

    for (i = 0; i <= 3; i++)
    {
        pRg->pAlphts[i] = InitRotor();
        pRg->pCiphts[i] = InitRotor();
    }

    return pRg;
}

Rotorgroup *SetEnigmaRotors(const char pos[3], const char key[4])
{
    Rotorgroup *pRg = InitRotorGroup();
    int i;

    for (i = 0; i <= 3; i++)
        pRg->pAlphts[i] = StringToRotor(_alphabet, 26);

    pRg->pCiphts[pos[0]-'1'] = StringToRotor(_rotor1, 26);
    pRg->pCiphts[pos[1]-'1'] = StringToRotor(_rotor2, 26);
    pRg->pCiphts[pos[2]-'1'] = StringToRotor(_rotor3, 26);
    pRg->pCiphts[3] = StringToRotor(_rotor4, 26);

    for (i = 0; i <= 3; i++)
        ConnectRotorPair(pRg->pAlphts[i], pRg->pCiphts[i], key[i], key[(i+1)%4]);

    #if _MAIN_DEBUG_ || _GROUP_DEBUG_
    for (i = 0; i <= 3; i++)
    {
        printf("\n-----------%d-----------\n", i+1);
        PrintRotorPair(pRg->pAlphts[i]);
    }
    #endif

    return pRg;
}

char RightEncrypt(Rotorgroup *pRg, int index, char lttr)
{
    if (index >= 4)
        return lttr;

    Rotorhead *pAlpht = pRg->pAlphts[index];
    Unit *ptemp = FindUnit(pAlpht, lttr);
    char tmplttr = ptemp->right->lttr;

    return RightEncrypt(pRg, index+1, tmplttr);
}

char LeftEncrypt(Rotorgroup *pRg, int index, char lttr)
{
    if (index <= -1)
        return lttr;

    Rotorhead *pCipht = pRg->pCiphts[index];
    Unit *ptemp = FindUnit(pCipht, lttr);
    char tmplttr = ptemp->left->lttr;

    return LeftEncrypt(pRg, index-1, tmplttr);
}

char Reflector(char lttr)
{
    static char reflector[27] = {_reflector};
    return reflector[lttr-'A'];
}

char PlugboardEncryption(char plugboard[13], char lttr)
{
    char *ptemp = strchr(plugboard, lttr);
    if (ptemp == NULL)
        return lttr;

    int index = (int)(ptemp - plugboard);
    index = index%2 ? index-1 : index+1;

    return plugboard[index];
}

char RotorsEncryption(Rotorgroup *pRg, char lttr)
{
    char tmpch;

    tmpch = RightEncrypt(pRg, 0, lttr);
    tmpch = Reflector(tmpch);
    tmpch = LeftEncrypt(pRg, 3, tmpch);

    return tmpch;
}

#if _GROUP_DEBUG_

int main(int argc, char const *argv[]) {

    char temp = PlugboardEncryption(_plugboard, 'Z');
    printf("%c\n", temp);
    return 0;
}

#endif
