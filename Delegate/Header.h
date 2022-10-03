#pragma once
#include <stdio.h>
#include <malloc.h>


typedef int (*pointer)(int, int);
typedef pointer* delegate;
typedef struct Array
{
	size_t count;
	delegate d;
} Array;


int summ(int, int);
int subtraction(int, int);
delegate InitDelegate();
void AddFunc(Array *, pointer);
void DeleteFunc(Array*, pointer);
void StartAll(Array a, int x, int y);