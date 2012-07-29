//Pipe this program through "grep Found" to make it less chatty.


//Book's algorithm:
//Find 7
//l                    m                             h
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

//l         m          h                             
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

//            l   m    h
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

//            m         
//            l h
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

//              l
//              m
//              h
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
#include <stdio.h>
#define SIZE (21)
int binsearch(int x, int v[], int n, int *comparisons);
int booksearch(int x, int v[], int n, int *comparisons);
void test(int x, int v[], int n);
int print_at(int i, int v[]);
int debug_status(int low, int mid, int high, int v[]);

int main()
{
	int v[SIZE];
	int i;

	for(i = 0; i < SIZE; i++)
	{
		v[i] = i;
	}

	test(-1,v,SIZE);
	for(i = 0; i < SIZE; i++)
	{
		test(i, v, SIZE);
	}
	test(SIZE,v,SIZE);

}

void test(int x, int v[], int n)
{
	int comparisons;
	printf("My search found %d at position %d\n", x, binsearch(x, v, SIZE, &comparisons));
	printf("Took %d comparisons\n", comparisons);
	printf("Book search found %d at position %d\n", x, booksearch(x, v, SIZE, &comparisons));
	printf("Took %d comparisons\n", comparisons);
	printf("\n");
}

int debug_status(int low, int mid, int high, int v[])
{
	printf("\nCurrent search status\n");
	print_at(low, v);
	print_at(mid, v);
	print_at(high,v);
}

int binsearch(int x, int v[], int n, int *comparisons)
{
	int low, mid, high;
	low = 0;
	high = n-1;
	*comparisons = 0;

	while(low + 1 <  high)
	{
		*comparisons += 1;

		mid = (low + high) / 2;
	
		//debug_status(low, mid, high, v);

		*comparisons += 1;
		if(x < v[mid])
		{
			high = mid;
		}
		else
		{
			low = mid;
		}

	}

	//debug_status(low, mid, high, v);

	*comparisons += 1;
	if(x == v[low])
	{
		return low;
	}

	*comparisons += 1;
	if(x == v[high])
	{
		return high;
	}

	return -1;

}

int booksearch(int x, int v[], int n, int *comparisons)
{
	int low, mid, high;
	*comparisons = 0;
	low = 0;
	high = n-1;
	while( low <= high)
	{
		*comparisons += 1;

		mid = (low+high) / 2;
		if( x < v[mid] )
		{
			*comparisons += 1;
			high = mid-1;
		}
		else if (x > v[mid])
		{
			*comparisons += 1;
			low = mid+1;
		}
		else
			return mid;
	}
	return -1;
}

int print_at(int i, int v[])
{
	printf("v[%2d] = %0d\n", i, v[i]);
}

