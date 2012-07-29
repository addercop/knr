#include <stdio.h>

#define SIZE (1000)

void escape(char *s, char *t);
void unescape(char *s, char *t);
void test(char *s);

int main()
{
	test("Hello	this	is	a	test	string.");
	test("Hello\nthis\nis\nanother\ntest\nstring.");
	return 0;
}

void test(char *s)
{
	char t[SIZE];
	char u[SIZE];
	printf("Original : [%s]\n",s);
	escape(t,s);
	printf("Escaped  :[%s]\n",t);
	unescape(u,t);
	printf("Descaped :[%s]\n",u);
	
}

void escape(char *s, char *t)
{
	while(*t)
	{
		switch(*t)
		{
			case '\t':
				*s++ = '\\';
				*s++ = 't';
				break;
			case '\n':
				*s++ = '\\';
				*s++ = 'n';
				break;
			default:
				*s++ = *t;
				break;
		}
		t++;
	}
	if(*t == '\0')
	{
		*s = '\0';
	}
}

void unescape(char *s, char *t)
{
	while(*t)
	{
		switch(*t)
		{
			case '\\':
				t++;
				switch(*t)
				{
					case 't':
						*s = '\t';
						break;
					case 'n':
						*s = '\n';
						break;
					case '\0':
						*s = '\0';
						return;
				}
				s++;
				break;
			case '\0':
				*s = '\0';
				return;
			default:
				*s++ = *t; 
		}
		t++;
	}
	*s = '\0';
}
