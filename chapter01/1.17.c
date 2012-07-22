#include <stdio.h>
#define BUFSIZE (82)
#define MINSIZE (80)
int get_line(char line[], int maxline);

main()
{
	int len;
	int max;
	int c;
	char line[BUFSIZE];

	max = 0;
	while ((len = get_line(line, BUFSIZE)) > 0)
	{
		//if line was too big for the buffer,
		//it will not end with a newline
		if (len >= MINSIZE && line[BUFSIZE-2] != '\n')
		{
			//more than 80 printables
			//so print remaining bytes on the line
			printf("%s",line);
			while ((c=getchar()) != EOF && c != '\n')
			{
				putchar(c);
			}
			putchar('\n');
		}
	}
	return 0;
}

int get_line(char s[], int lim)
{
	int c;
	int i;

	for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
	{
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
