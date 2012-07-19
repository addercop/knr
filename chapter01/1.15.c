#include <stdio.h>

float celcius_from_fahrenheit(float fahr);

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("%3s %6s\n","F","C");
	fahr = lower;
	while(fahr <= upper)
	{
		celsius = celcius_from_fahrenheit(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}

float celcius_from_fahrenheit(float fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
