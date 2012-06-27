#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;

	for(c = getchar(); c != EOF; c = getchar())
	{
		if(c == ' ')
		{
			putchar(c);
			while((c = getchar()) == ' ')
			{
				//consume spaces silently
			}
		}
		putchar(c);
	}

	return 0;
}
