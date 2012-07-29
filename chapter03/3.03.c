#include <ctype.h>
#include <stdio.h>
#define SIZE (100)

//Expand ranges like "a-z" into the characters 'a' through 'z'.
//Handle cases like "a-b-c" and "a-z0-9".
//Interpret leading and trailing '-' characters literally.
void expand(char *s, char *t);
int in_same_range(char left, char right);
void test(char *t);

int main()
{
	test("");
	test("-");
	test("--");
	test("a-z");
	test("a-0");
	test("-a-f-");
	//Handles this case by just doubling the d. 
	test("a-d-e");
	test("a-zA-Z0-9");
	return 0;
}

void test(char *t)
{
	char s[SIZE];

	printf("Original string: [%s]\n",t);
	expand(s,t);
	printf("New string: [%s]\n", s);
	printf("\n");
}

void expand(char *s, char *t)
{
	char left, right, c;

	if(*t == '\0')
	{
		return;
	}
	if(*t == '-')
	{
		*s++ = '-';
		t++;
		if(*t == '\0')
			return;
	}

	while(*t)
	{
		//find next '-'.
		while(*t != '-' && *t != '\0')
		{
			printf("%c was not - or \\0.\n",*t);
			t++;
		}

		if(*t == '\0')
			break;
		
		left = *(t-1);
		right = *(t+1);
		//if next/previous character is '-'
		//or if the next character is '\0'.
		if( left == '-' || right == '-' || right == '\0')
		{
			t++;
			continue;
		}

		//Of the groups uppercase, lowercase, digit,
		//both left and right limits must belong
		//to the same group.
		if(!in_same_range(left,right))
		{
			t++;
			continue;
		}

		for(c = left; c <= right; c++)
		{
			printf("Outputting %c\n", c);
			*s++ = c;
		}		

		t++;
	}

	if(*(t-1) == '-')
	{
		*s++ = '-';
	}

	*s = '\0';
}

int in_same_range(char left, char right)
{
	if( isupper(left) && isupper(right) )
		return 1;
	if( islower(left) && islower(right) )
		return 1;
	if( isdigit(left) && isdigit(right) )
		return 1;

	return 0;
}
