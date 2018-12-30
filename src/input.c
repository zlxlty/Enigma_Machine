/*
* =================================================
*       Filename:  input.c
*        Version:  1.0.1
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#include "input.h"

static char *RotorPosInput(FILE *fp)
{
    char c;
    register int i = 1;
    char *tmpch = (char *)malloc(sizeof(char)*5);
    tmpch[0] = 'A';

    if (fp == stdin)
        printf("\nEnter a three-digit Key: ");

    while (((c = getc(fp)) != EOF) && (i <= 3))
    {
        if (isalpha(c))
            tmpch[i++] = toupper(c);
    }
    tmpch[i] = '\0';

    return tmpch;
}

static char *PlugboardInput(FILE *fp)
{
    char c;
    register int i = 0;
    char *tmpch = (char *)malloc(sizeof(char)*13);

    if (fp == stdin)
        printf("\nEnter a 12-digit Plugboard: ");

    while (((c = getc(fp)) != EOF) && (i <= 11))
    {
        if (isalpha(c))
            tmpch[i++] = toupper(c);
    }
    tmpch[i] = '\0';

    return tmpch;
}

static char *RotorOrderInput(FILE *fp)
{
    char c;
    register int i = 0;
    char *tmppos = (char *)malloc(sizeof(char)*4);

    if (fp == stdin)
        printf("\nEnter rotors' position: ");

    while (((c = getc(fp)) != EOF) && (i <= 2))
    {
        if (c > '1' || c < '3')
            tmppos[i++] = c;
    }

    tmppos[i] = '\0';

    return tmppos;
}

Key *KeyInput(int filein, char *filename)
{
    Key *pkey = (Key *)malloc(sizeof(Key));

    if (filein == 0)
    {
        pkey->order = RotorOrderInput(stdin);
        pkey->pos = RotorPosInput(stdin);
        pkey->plugboard = PlugboardInput(stdin);
    }
    else if (filein == 1)
    {
        FILE *fp;

        if ((fp = fopen(filename, "r")) == NULL)
        {
            fprintf(stderr, ERRORMSG, "can not open file");
            return NULL;
        } else {
            pkey->order = RotorOrderInput(fp);
            pkey->pos = RotorPosInput(fp);
            pkey->plugboard = PlugboardInput(fp);
        }

    }

    return pkey;
}

void RemoveKey(Key *pkey)
{
    free((void *)pkey->order);
    free((void *)pkey->pos);
    free((void *)pkey->plugboard);
    free((void *)pkey);
}

char TextInput()
{
    char c;
    while (((c = getchar()) == EOF) || isalpha(c) == 0)
    {
        if (c == '-')
            return c;
        if (c != '\n')
            fprintf(stderr, ERRORMSG, "Illegal text input");
    }

    return toupper(c);
}

char *StringInput(int size)
{
    int i = 0;
    char *str = (char *)malloc(sizeof(char)*size);
    char c;
    while ((c = getchar()) != '-' && i < size-1)
    {
        // putchar(c);
        if (c != '\n' && isalpha(c) == 0)
            continue;
        // printf("Hello\n");
        if (c == '\n')
        {
            str[i] = '\0';
            return str;
        }

        // printf("Hello\n");
        str[i++] = toupper(c);
    }

    if (c == '-')
    {
        str[0] = c;
        str[1] = '\0';
        return str;
    }
}

void KeyRotation(char *key)
{
    if (key[1] != 'Z')
        key[1]++;
    else if (key[2] != 'Z')
    {
        key[1] = 'A';
        key[2]++;
    }
    else if (key[3] != 'Z')
    {
        key[2] = 'A';
        key[3]++;
    }
    else
        key[1] = key[2] = key[3] = 'A';
}


#if _INPUT_DEBUG_

int main(int argc, char const *argv[]) {

    int i;
    char *temp;
    // char ch = TextInput();
    // printf("%c\n", ch);
    // temp = KeyInput(0);
    // printf("%s\n", temp);
    temp = StringInput(1000);
    printf("%s\n", temp);

    // for (i = 0; i < 1000; i++)
    // {
    //     KeyRotation(temp);
    //     printf("%s\n", temp);
    // }
    //
    // temp = PlugboardInput(0);
    // printf("%s\n", temp);
    return 0;
}

#endif
