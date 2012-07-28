#include <stdio.h>

int invertbits(int x, int p, int n);

void print_binary(unsigned int n);

void test_harness(int x, int p, int n);

int main()
{

	test_harness(0x000a0000, 16, 4);

	return 0;
}

//returns x with the bits n+p..p inverted.
int invertbits(int x, int p, int n)
{
	int mask = ~(~0 << n) << p;
	printf("Mask 0x%08x\n", mask);
	return x ^ mask;
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

void test_harness(int x, int p, int n)
{
	
	int result = 0;

	printf("x: 0x%08x\n", x);
	//print_binary(x);
	//print_binary(y);
	printf("p: %d\n", n);
	printf("n: %d\n", p);

	result = invertbits(x,p,n);
	
	printf("Result 0x%08x\n", result);
	//print_binary(result);
}
