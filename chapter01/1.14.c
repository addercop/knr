#include <stdio.h>

#define IN_WORD (0)
#define IN_WHITE (1)

int main(int argc, char *argv[])
{
	int char_counts[256];
	int current_length;
	int state;
	int i;
	int j;
	int c;

	for(i = 0; i < 256; i++)
	{
		char_counts[i] = 0;
	}


	for(c = getchar(); c != EOF; c = getchar())
	{
		//only handle lowercase characters.
		if('a' <= c && c <= 'z')
		{
			printf("Saw letter %c\n",c);
			char_counts[c]++;
		}
	}
	
	//Print histogram.
	for(i = 0; i < 256; i++)
	{
		if('a' <= i && i <= 'z')
		{
			printf("%c ",i);
			for(j = 0; j < char_counts[i]; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}


	return 0;
}
