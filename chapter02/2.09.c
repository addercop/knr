#include <stdio.h>

void print_binary(unsigned int n);
void test_harness(int n);
int count_ones(int n);

int main()
{

	test_harness(1234);
	test_harness(1233);

	return 0;
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

void test_harness(int n)
{
	printf("n  : %d\n",n);
	print_binary(n);

	printf("n-1: %d\n",n-1);
	print_binary(n-1);

	printf("1s : %d\n",count_ones(n));

	printf("-----------------------\n");
}

//If n is odd, its LSB is 1, so (n-1) has a LSB of 0.
//The bitwise AND clears the LSB in the result.

//If n is even, computing (n-1) requires a borrow from each bit to the left,
//ending at the first high bit. Bits further left are identical to the pattern
//of n itself. So the rightmost high bit becomes zero,
//and the bits to the right remain zero.
int count_ones(int n)
{
	int ones = 0;
	while(n != 0)
	{
		ones++;
		n &= (n-1);
	}

	return ones;
}
