Enigma
======

### This is a simulator of `Enigma Machine` which is a kind of mechanical cipher used by Germany army in the WW2.

****

## Content
* [Getting_Started](#getting_started)
* [Compiling](#compiling)
* [Run_Enigma](#run_enigma)
    * Basic Function
    * Costumize Key
* [Feature](#feature)
    * Unit Test
* [Rotorsettings](#rotorsettings)

****

## Getting_Started
### Prerequisites
* For linux and Mac
* gcc version 7.3.0 (Ubuntu 7.3.0-16ubuntu3)
* GUN Make 4.1

### Installing  
Clone this repo by using
```
$ git clone https://github.com/zlxlty/Enigma_Machine.git
```

****

## Compiling
Enter the `src` folder and type in
```
$ make
```
Delete all the object files by using
```
$ make clean_objs
```

****

## Run_Enigma
### Basic Function
To use the encryption function in `Enigma simulator`, you just have to compile first and use terminal and type in:
```
$ make run_fe
```
To use the decryption function, type in
```
$ make run_fd
```
### Customize Key
Use
```
$ make run_e
```
to encrypt with your own key. Similarly, use
```
$ make run_d
```
for decryption  

As most of other ciphers, `Enigma` requires key to encrypt and and decrypt messages  
I am simulating an early version of `Enigma` which has three keys:
* The Sequence of `Rotors`: A **three-digit number** made up of `1` `2` `3`
* The initial position of each `Rotor`: **Three English letters**
* The settings of `Plugboard`: **Six pairs of letters**

There is no need for you to know all the theories and processes behind the mechanism of `Enigma Machine`. If you are interested, you can go to [this website](http://enigma.louisedade.co.uk/howitworks.html) for more information

****

## Feature
### Unit Test
```c
#define _LINKED_DEBUG_ 0
#define _ROTORS_DEBUG_ 0
#define _GROUP_DEBUG_  0
#define _INPUT_DEBUG_  0
#define _MAIN_DEBUG_   0
#define _MAIN_         1
```
Each source file has a unit test controlled by macro in `settings.h`. To activate a unit test, just change the corresponding macro to `1`.

****

## Rotorsettings
The configuration of the rotors are as follow:
```c
#define _plugboard "AHLOCJKXWERO"
#define _rotor1    "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define _rotor2    "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define _rotor3    "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define _rotor4    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define _reflector "YRUHQSLDPXNGOKMIEBFZCWVJAT"
#define _alphabet  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
```

****

|Author|SkyL|
|---|---|
|E-mail|2924312854@qq.com|

****
