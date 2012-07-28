#include <stdio.h>

int setbits(int x, int p, int n, int y);

void print_binary(unsigned int n);

void test_harness(int x, int p, int n, int y);

int main()
{

	test_harness(0x00000000, 16, 4, 0x0000000f);

	return 0;
}

//returns x with the bits n+p..p bits replaced with the rightmost
//n bits of y.
int setbits(int x, int p, int n, int y)
{
	//bit positions are 32..0 from left to right.
	int mask;
	int y_bits;

	//make a mask to clear out the n bits.
	mask = ~((~(~0 << n)) << p);

	printf("Mask   ");
	print_binary(mask);

	//now collect relevant bits from y.
	y_bits = ( ~((~0)<< n) & y) << p;

	printf("y_bits ");
	print_binary(y_bits);

	printf("x&mask ");
	print_binary(x&mask);

	return (x & mask) | y_bits;
}

void print_binary(unsigned int n)
{
	int i;
	printf("0b");
	for(i = 31; i >= 0; i--)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

void test_harness(int x, int p, int n, int y)
{
	
	int result = 0;

	printf("x: 0x%08x\n", x);
	//print_binary(x);
	printf("y: 0x%08x\n", y);
	//print_binary(y);
	printf("p: %d\n", n);
	printf("n: %d\n", p);

	result = setbits(x,p,n,y);
	
	printf("Result 0x%08x\n", result);
	//print_binary(result);
}
