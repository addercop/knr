#include <stdio.h>

int main(int argc, char *argv[])
{
	int blanks = 0;
	int tabs = 0;
	int newlines = 0;
	int c;

	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			blanks++;
		}
		else if(c == '\t')
		{
			tabs++;
		}
		else if(c == '\n')
		{
			newlines++;
		}
	}
	printf("%d %d %d\n", blanks, tabs, newlines);

	return 0;
}
