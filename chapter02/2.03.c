#include <stdio.h>
#include <string.h>

int htoi(char *s);

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

	int i;
	for(i = 0; i < sizeof(hex_numbers)/sizeof(char *); i++)
	{
		printf("[%s] = %d\n",hex_numbers[i], htoi(hex_numbers[i]));
	}

	return 0;
}

int htoi(char *s)
{
	int n = 0;
	int offset;
	
	//Zero length string.
	if(*s == '\0')
	{
		return 0;
	}

	//check leading '0x' or '0X'
	if(*s == '0')
	{
		s++;
	}

	//in case string was just '0'.
	if(*s == '\0')
	{
		return 0;
	}

	if(*s == 'x' || *s == 'X')
	{
		s++;
	}

	while(1)
	{

		if('0' <= *s && *s <= '9')
		{
			offset = '0';
		}
		else if('a' <= *s && *s <= 'f')
		{
			offset = 'a';
		}
		else if('A' <= *s && *s <= 'F')
		{
			offset = 'A';
		}
		else
		{
			break;
		}

		n = n*16 + (*s - offset);
		s++;
	}

	printf("Returning %d\n",n);
	return n;	
}
