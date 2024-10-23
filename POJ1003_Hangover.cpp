//POJ Problem:1003 HangOver

#include<cstdio>
#include<cmath>
#define MAX 300

float HashTable[MAX]={0};

void fillHash()
{
	float num=2; 
	HashTable[0]=0.5;
	//printf("%.2f\n",HashTable[0]);
	for(int i=1;i<MAX;i++)
	{
		num++;
		HashTable[i] = HashTable[i-1] + 1/num;
		//printf("HashTable[%d]:%.2f",i,HashTable[i]);
	}
	
}  

int findNum(float n)
{
	for(int j=0;j<MAX-1;j++)
	{
		if(n>HashTable[j] && n<=HashTable[j+1])
			return j+2;
		else if(n<=HashTable[0])
			return 1;
		else continue;
	}
	
	printf("beyond the max output!");
	return -1;
}

int main()
{
	float c=0;
	int final=0;
	fillHash();
	scanf("%f",&c);
	while(c>1e-3)
	{
		//printf("%.2f",c); 
			final=findNum(c);
			printf("%d card(s)\n",final);
			scanf("%f",&c);
	}
}
