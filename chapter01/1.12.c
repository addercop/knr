#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;

	for(c = getchar(); c != EOF; c = getchar())
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			for(c = getchar(); c == ' ' || c == '\t' || c == '\n'; c = getchar())
			{
			}
			putchar('\n');
		}
		putchar(c);
	}

	return 0;
}
