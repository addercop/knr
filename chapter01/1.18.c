#include <stdio.h>
#define BUFSIZE (100)
int get_line(char line[], int maxline);
int right_trim(char line[], int len);

main()
{
	int len;
	char line[BUFSIZE];

	while ((len = get_line(line, BUFSIZE)) > 0)
	{
		len = right_trim(line,len);
		//omit blank lines.
		if(len > 0)
		{
			//wrap in brackets and replace newline for clarity.
			printf("[%s]\n", line);
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

//edit line from the right to delete all tabs and spaces.
//return the new length of the string.
int right_trim(char line[], int len)
{
	int i;
	//a b c d \0, len=4, len+null = 5
	//0 1 2 3  4
	if(len == 0)
	{
		return 0;
	}

	//a b c \t \t \0 len 5 becomes
	//a b c \0 \0 \0, len 3
	//\t \t \t \0 len 3 becomes
	//\0 \0 \0 \0, len 0
	for(i = len-1; i >= 0; i--)
	{
		if( line[i] == '\t' || line[i] == ' ' || line[i] == '\n')
		{
			line[i] = '\0';
		}
		else
		{
			break;
		}
	}

	if(i == -1)
		return 0;
	return i;
}
