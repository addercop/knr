#include <stdio.h>
#include <string.h>

int htoi(char s[]);
int int_from_hex_digit(char h);

int main()
{
	char *hex_numbers[] = { 
		"0",
		"0x",
		"0X",
		"0x0",
		"0x1",
		"0x10",
		"0x100",
		"0x1234",
	};
	char hex_digits[] = "0123456789abcdefABCDEF";

	int i;
	for(i = 0; i < sizeof(hex_numbers)/sizeof(char *); i++)
	{
		printf("[%s] = %d\n",hex_numbers[i], htoi(hex_numbers[i]));
	}

	return 0;
}

int htoi(char s[])
{
	int n = 0;
	int h;
	char *p;
	
	//establish length
	if(int_from_hex_digit(s[0]) == -1)
		return 0;
	if(s[1] == '\0')
	{
		printf("Only one character.\n");
		return int_from_hex_digit(s[0]);
	}

	//from now on we know total len >= 2

	p = s;
	//check if prefix exists.
	if(strncmp(s,"0x",2) == 0 || strncmp(s,"0X",2) == 0)
	{
		printf("Found prefix on this string.\n");
		//skip prefix
		p += 2;
	}

	//establish length again
	if(p[0] == '\0')
	{
		printf("String was nothing but prefix\n");
		return 0;
	}

	for(n = 0; (h = int_from_hex_digit(*p)) != -1; p++)
	{
		printf("Found digit %d\n", h);
		n = n*16 + h;
	}

	printf("Returning %d\n",n);
	return n;	
}

int int_from_hex_digit(char h)
{
	if('0' <= h && h <= '9')
		return h-'0';
	if('a' <= h && h <= 'f')
		return 10 + (h-'a');
	if('A' <= h && h <= 'F')
		return 10 + (h-'A');

	return -1;
}
