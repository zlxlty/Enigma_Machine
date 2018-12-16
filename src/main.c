/*
* =================================================
*       Filename:  main.c
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#include "main.h"

#if _MAIN_ || _MAIN_DEBUG_

int main(int argc, char const *argv[]) {

    system("clear");
    printf("\x1b[1m\x1b[4mENIGMA MACHINE\n\n\x1b[0m");

    if (argc <= 1)
    {
        fprintf(stderr, ERRORMSG, "\nPlease Choose Mode:\nEncryption:\t-e\nDecryption:\t-d\nFileinput:\t-f\n");
        exit(1);
    }

    char c;
    const char *prog = argv[0];

    flags.encrypt = flags.decrypt = flags.filein = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'e':
                    flags.encrypt = 1;
                    break;
                case 'd':
                    flags.decrypt = 1;
                    break;
                case 'f':
                    flags.filein = 1;
                    break;
                default:
                    printf("%s: illegal option %c\n",prog, c);
                    argc = 0;
                    exit(1);
            }


    Key *pkey = KeyInput(flags.filein);
    char plaintxt;
    char ciphrtxt;

    if (flags.encrypt)
    {
        while (1)
        {
            Rotorgroup* pEnigma = SetEnigmaRotors(pkey->order, pkey->pos);
            printf("\nEnter one digit Plaintext: ");
            plaintxt = TextInput();

            if (plaintxt == '-')
            {
                system("clear");
                printf("Thanks For Using Enigma\n");
                sleep(1);
                return 0;
            }

            plaintxt = PlugboardEncryption(pkey->plugboard, plaintxt);
            plaintxt = RotorsEncryption(pEnigma, plaintxt);
            ciphrtxt = PlugboardEncryption(pkey->plugboard, plaintxt);
            printf("Ciphertext: %c\n", ciphrtxt);
            KeyRotation(pkey->pos);
        }
    }

    // TODO if (flags.decrypt)
    // {
    //
    // }

    return 0;
}

#endif
