//POJ Problem 1004 Financial Management

#include<cstdio>
using namespace std;

int main()
{
	float bill=0; 
	float sum=0;
	for(int month=12;month>=1;month--)
	{
		scanf("%f",&bill);
		sum += bill;
	}
	printf("$%.2f",sum/12);
	return 0;
} 
