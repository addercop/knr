#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char s[] = "Hello this is a test string.";

	printf("Searching [%s] for any of [%s]\n", s,"H");
	printf("Found at position %d\n", any(s,"H"));

	printf("Searching [%s] for any of [%s]\n", s,"osatg");
	printf("Found at position %d\n", any(s,"osatg"));

	printf("Searching [%s] for any of [%s]\n", s,"qxz");
	printf("Found at position %d\n", any(s,"qxz"));

	return 0;
}

int any(char s1[], char s2[])
{
	int i;
	int j;

	for(i = 0; s1[i] != '\0'; i++)
	{
		for(j = 0; s2[j] != '\0'; j++)
		{
			if(s1[i] == s2[j])
			{
				return i;
			}
		}
	}

	return -1;
}
