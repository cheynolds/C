#include<stdio.h>

void fun1(int x)
{
	printf("%d\n", x);
}

void fun2(int* p)
{
	printf("%d\n", *p);
}

void fun3(int* p)
{
	*p = 15;
}

void pointerIsStillACopy(int* p)
{
	int someOneElse = 2;
	p = &someOneElse;
	fun1(someOneElse);
	fun2(p);
	fun3(p);
	fun1(someOneElse);
}

/*
void AndX(int &y)
{
	// nope, that would be c++
}
*/

int main()
{
	int x = 5;
	int* pointer = &x;
	fun1(x);
	fun2(pointer);
	fun3(pointer);
	fun1(x);
	x = 23;
	fun1(x);
	pointerIsStillACopy(pointer);
	fun1(x);

	return 0;
}
