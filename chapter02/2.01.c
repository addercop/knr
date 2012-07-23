#include <stdio.h>
#include <limits.h>

char upper_char();
char lower_char();
unsigned char upper_unsigned_char();

int main()
{
	char hi_char = upper_char();
	char lo_char = lower_char();
	unsigned char hi_u_char = upper_unsigned_char();

	printf("High signed char (computed): %d\n", hi_char);
	printf("High signed char (header): %d\n", CHAR_MAX);

	printf("Low signed char (computed): %d\n", lo_char);
	printf("Low signed char (header): %d\n", CHAR_MIN);

	printf("High unsigned char (computed): %d\n", hi_u_char);
	printf("High unsigned char (header): %d\n", UCHAR_MAX);

	return 0;
}


char upper_char()
{
	char prev;
	char cur;
	
	prev = 0;
	cur = 0;
	while(prev <= cur)
	{
		prev = cur;
		cur++;
	}

	return prev;
}

char lower_char()
{
	char prev;
	char cur;
	prev = 0;
	cur = 0;
	while(prev >= cur)
	{
		prev = cur;
		cur--;
	}

	return prev;
}

unsigned char upper_unsigned_char()
{
	unsigned char prev;
	unsigned char cur;
	prev = 0;
	cur = 1;
	while(prev < cur)
	{
		prev = cur;
		cur++;
	}

	return prev;
}
