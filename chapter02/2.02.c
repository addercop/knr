#include <stdio.h>
#define MAXLINE (10) /*maximum input line size*/

int get_line(char line[], int maxline);

/*print longest input line*/

main()
{
	char line[MAXLINE];

	while ( get_line(line, MAXLINE) > 0)
	{
		printf("%s",line);
	}

	return 0;
}

int get_line(char s[], int lim)
{
	int c;
	int i;

	for(i = 0; 1; i++)
	{
		if(i >= lim-1)
			break;

		if((c=getchar()) == EOF)
			break;

		if(c == '\n')
			break; 

		s[i] = c;
	}

	if(c == '\n')
	{
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}
