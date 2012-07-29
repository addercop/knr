#include <stdio.h>

int strindex(char body[], char term[]);
void test(char body[], char term[]);

int main()
{

	test("Hello world.", ".");
	test("Hello world.", "H");
	test("Hello world.", " ");
	test("Hello world.", "r");
	test("Hello world.", "o");
	test("............", ".");

	return 0;
}

void test(char body[], char term[])
{
	printf("Searching [%s] for [%s]\n",body,term);
	printf("Found at position %d\n",strindex(body,term));
	printf("\n");
}

int strindex(char body[], char term[])
{
	int i,j,k;

	int rightmost_start = 0;

	for(i = 0; body[i] != '\0'; i++)
	{
		j = i;
		k = 0;
		while(term[k] != '\0' && body[j] == term[k])
		{
			j++;
			k++;
		}

		if(k > 0 && term[k] == '\0')
		{
			rightmost_start = i;
		}
	}

	return rightmost_start;
}
