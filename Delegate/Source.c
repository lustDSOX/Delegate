#include "Header.h"

main() {
	Array array = { 0,InitDelegate() };
	AddFunc(&array, summ);
	AddFunc(&array, subtraction);
	StartAll(array, 1, 2);
	DeleteFunc(&array, summ);
	StartAll(array, 1, 2);

}

delegate InitDelegate() {
	delegate d = calloc(1, sizeof(pointer));
	return d;
}

void AddFunc(Array *a, pointer f) {
	a->count++;
	a->d = realloc(a->d, (a->count+1) * sizeof(pointer));
	a->d[a->count - 1] = f;
}

void DeleteFunc(Array* a, pointer f) {
	size_t n = a->count;
	for (size_t i = 0; i < n; i++)
	{
		if (a->d[i] == f) {
			a->d[i] = NULL;
			a->count--;
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		if (a->d[i] == NULL)
			a->d[i] = a->d[i+1];
	}
	a->d = realloc(a->d, (a->count) * sizeof(pointer));
}

void StartAll(Array a,int x,int y) {
	for (size_t i = 0; i < a.count; i++)
	{
		printf("%d ", a.d[i](x, y));
	}
	printf("\n");
}

int summ(int a, int b) {
	return a + b;
}

int subtraction(int a, int b) {
	return a - b;
}