//POJ 1005 I Think I Need a Houseboat 

#include<cstdio>
#include<cmath>

#define MAX 50
#define PI 3.14

float HashTable[MAX]={0};

void fillHashTable()
{
	for(int i=0;i<MAX;i++)
	{
		HashTable[i] = sqrt((float)2*i*50/PI);
		//printf("%.2f\n",HashTable[i]);
	}
	return ;
}

int main()
{
	int n=0;
	int j=0;
	float x=0,y=0;
	fillHashTable();
	
	scanf("%d\n",&n);
	while(j++<n)
	{
		scanf("%f%f",&x,&y);
		float r;
		r=sqrt(pow(x,(float)2.0)+pow(y,(float)2.0));
		//printf("%.2f%.2f\n",x,y);
		//printf("%.2f",r);
		for(int i=0;i<MAX-1;i++)
		{
			if(r>=HashTable[i] && r<HashTable[i+1])
			{
				printf("Property %d: This property will begin eroding in year %d.\n",j,i+1);
			}
			else continue;
		}
	}
	printf("END OF OUTPUT.");
	return 0;
}

