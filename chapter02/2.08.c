#include <stdio.h>

int rightrot(unsigned int x, int n);

void print_binary(unsigned int n);

void test_harness(int x, int n);

int main()
{
	int i;

	for(i = 0; i <= sizeof(int)*8; i += 4)
	{
		printf("0x%08x\n", rightrot(0xabcd1234,i));
	}

	return 0;
}

//returns x rotated right n bits.
//make x unsigned due to sign-extended right shifts.
int rightrot(unsigned int x, int n)
{
	int width_bits = sizeof(int)*8;
	int temp = 0;

	//avoid shifting things into oblivion.
	n = n % width_bits;

	//0x1234abcd >>> 4 == 0xd1234abc

	return (x << (width_bits -n)) |  (x >> n);

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

void test_harness(int x,  int n)
{
	
	int result = 0;

	printf("x: 0x%08x\n", x);
	printf("n: %d\n", n);

	result = rightrot(x,n);
	
	printf("Result 0x%08x\n", result);
}
