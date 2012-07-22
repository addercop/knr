#include <stdio.h>
#define MAXLINE (10) /*maximum input line size*/

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/*print longest input line*/

main()
{
	int len;
	int max;
	int c;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
	{
		//if line was too big for the buffer,
		//it will not end with a newline
		if (len == (MAXLINE-1) && line[len-2] != '\n')
		{
			//consume bytes, incrementing len
			while ((c=getchar()) != EOF && c != '\n')
			{
				len++;
			}
		}

		if (len > max)
		{
			max = len;
			copy(longest,line);
		}
	}

	if(max > 0)
	{
		printf("%d %s\n", max, longest);
	}
	else
	{
		printf("No longest.\n");
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

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
	{
		i++;
	}
}
