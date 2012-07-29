#include <stdio.h>
#define SIZE (1000)
void itoa(int n, char s[], int w);
void test(int n);
void reverse(char line[]);

int main()
{
	int i;
	test(1);
	test(-1);
	test(0);

	for(i = 0x80000000; i < 0; i--)
	{
		test(i);
	}
	
	return 0;
}

void test(int n)
{
	char s[SIZE];
	printf("Got number %d\n",n);
	itoa(n,s,6);
	printf("My atoi: [%s]\n", s);	
	printf("\n");
}

//naive sign flip in the original is a bug, since
//the absolute value of the largest negative
//integer cannot be represented.
void itoa(int n, char s[], int w)
{
	int i, sign;
	int digit;
	int max_neg = 1 << ((8 * sizeof(int))-1);
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
			printf("number was max_neg\n");
			
			digit = ((n/10) *10) - n;
			printf("Using least significant digit %d\n", digit);
			s[i] = digit+'0';
			n /= 10;
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
		printf("Remaining digits to process: %d\n", n);
		s[i++] = n % 10 + '0';
	}
	while((n /= 10) > 0);

	if(sign < 0)
	{
		s[i++] = '-';
	}

	while(i < w)
	{
		s[i++] = ' ';
	}

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
