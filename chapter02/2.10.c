#include <stdio.h>

int test_harness(char *p);
char lower(char c);

int main()
{
	test_harness("Hello THIS is A string OF length 36.");
	test_harness("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+;'\\,.");
}

int test_harness(char *p)
{
	while(*p != '\0')
	{
		putchar(lower(*p));
		p++;
	}
	putchar('\n');
}

char lower(char c)
{
	return ('A' <= c && c <= 'Z') ? c-('A'-'a') : c;
}
