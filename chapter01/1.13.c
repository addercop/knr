#include <stdio.h>

#define IN_WORD (0)
#define IN_WHITE (1)

int main(int argc, char *argv[])
{
	int lengths[10];
	int current_length;
	int state;
	int i;
	int j;
	int c;

	for(i = 0; i < 10; i++)
	{
		lengths[i] = 0;
	}

	current_length = 0;
	c = getchar();
	if(c == ' ' || c == '\t' || c == '\n')
	{
		state = IN_WHITE;
	}
	else
	{
		state = IN_WORD;
	}

	while(c != EOF)
	{
		//This is a sample line of input.
		//    x  x x      x    x  x      
		//deal with input
		if(state == IN_WHITE && (c == ' ' || c == '\t' || c == '\n'))
		{
			//transition whitespace to whitespace. do nothing.
			printf("White to white.\n");
		}
		if(state == IN_WHITE && c != ' ' && c != '\t' && c != '\n')
		{
			//transition whitespace to nonwhitespace. change state.
			printf("White to nonwhite.\n");
			state = IN_WORD;
		}
		if(state == IN_WORD && c != ' ' && c != '\t' && c != '\n')
		{
			//transition nonwhitespace to nonwhitespace. increment length.
			printf("Nonwhite to nonwhite. current_length: %d\n", current_length+1);
			current_length++;
		} 
		if(state == IN_WORD && (c == ' ' || c == '\t' || c == '\n'))
		{
			//transition whitespace to nonwhitespace.
			//we exited a word, so save length and reset to zero.
			printf("Saving length %d\n",current_length);
			if(0 < current_length && current_length < 10)
			{
				lengths[current_length]++;
			}
			current_length = 0;
			//seems to be superfluous. oh well.
			state = IN_WHITE;
		}

		c = getchar();

	}
	
	//Print histogram.
	for(i = 0; i < 10; i++)
	{
		printf("%02d ",i);
		for(j = 0; j < lengths[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//print sideways histogram
	for(j = 9; j >= 0; j--)
	{
		for(i = 0; i < 10; i++)
		{
			if(lengths[i] > j)
			{
				printf("*");
			}
			else
			{
				printf(".");
			}
		}
		printf("\n");
	}

	return 0;
}
