#include <stdio.h>
#define SIZE (1000)
void itob(int n, char s[], int b);
void test(int n, int b);
void reverse(char line[]);

int main()
{
	int i;

	for(i = -16; i <= 16; i++)
	{
		test(i,16);
	}

	for(i = 0x80000000; i < 0; i--)
	{
		test(i,16);
	}

	test(1000000,36);
	
	return 0;
}

void test(int n, int b)
{
	char s[SIZE];
	itob(n,s,b);
	printf("%d in base %d : [%s]\n",n, b, s);	
}

//naive sign flip in the original is a bug, since
//the absolute value of the largest negative
//integer cannot be represented.
void itob(int n, char s[], int b)
{
	int i, sign;
	int digit;
	int max_neg = 1 << ((8 * sizeof(int))-1);
	char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int max_b = sizeof(digits)/sizeof(char) - 1;

	if( b < 1 || b > max_b)
	{
		s[0] = '\0';
		return; //give up.
	}

/*
	if((sign = n) < 0)
	{
		n = -n;
	}

	i = 0;
*/

	i = 0;
	if((sign = n) < 0)
	{
		if(n == max_neg)
		{
			digit = ((n/b) * b) - n;
			s[i] = digit+'0';
			n /= b;
			n = -n;
			i += 1;
		}
		else
		{
			n = -n;
		}
	}
	
	do
	{
		s[i++] = digits[n % b];
	}
	while((n /= b) > 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char line[])
{
        int i;
        int j;
        char c;

	if(line[0] == '\0')
	{
		return;
	}

        i = 0;

        j = 0;
	while(line[j] != '\0')
	{
		j++;
	}
	j--;

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
