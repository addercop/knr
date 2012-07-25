#include <stdio.h>

void squeeze(char s[], char exclude[]);

int main()
{
	char s[] = "Hello this is a test string.";
	printf("%s\n", s);
	squeeze(s,"aeoiu");
	printf("%s\n", s);

	return 0;
}

void squeeze(char s[], char exclude[])
{
	int i,j,c;
	char *p;

	for(p = exclude; *p != '\0'; p++)
	{
		c = *p;
		for(i = j = 0; s[i] != '\0'; i++)
		{
			if(s[i] != c)
			{
				s[j++] = s[i];
			}
		}
		s[j] = '\0';
	}
}
