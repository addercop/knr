#include <stdio.h>
#define BUFSIZE (100)
int get_line(char line[], int maxline);
void reverse(char line[], int len);

main()
{
	int len;
	char line[BUFSIZE];

	while ((len = get_line(line, BUFSIZE)) > 0)
	{
		reverse(line,len);
		printf("%s", line);
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

void reverse(char line[],int len)
{
	int i;
	int j;
	char c;
	i = 0;
	j = len-1;
	while(i < j)
	{
		c = line[i];
		line[i] = line[j];
		line[j] = c;	
		i++;
		j--;
	}

	return;
}
