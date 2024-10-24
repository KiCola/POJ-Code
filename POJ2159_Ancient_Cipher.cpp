//POJ 2159 Ancient Cipher

//I1:字符串长度的表示方法
//I2：关键：只要频率分布一样，就是YES！不要被题干的substitution误导 

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	string str1,str2;
	cin >> str1 >> str2;
	//cout << strlen(str1.c_str()) << endl;//重要！学习 
	//cout << str2.size() << endl;
	if(strlen(str1.c_str()) != strlen(str2.c_str()))
	{
		cout << "NO" << endl;
		return 0;
	}
	
	int dif=0;
	int table1[26]={0};
	int table2[26]={0};
	
	/*祭奠我刚开始被题干误导的思路 
	for(int i=0;i<str1.size();i++)
	{
		dif = str1[i]-'A';
		str1[i]='Z'-dif;
		table[str1[i]-'A']+=1;
	}*/
	
	for(int i=0;i<strlen(str1.c_str());i++)
	{
		table1[str1[i]-'A'] += 1;	
	} 
	
	
	for(int i=0;i<str2.size();i++)
	{
		table2[str2[i]-'A']+=1;
	}
	
	int check1=0, check2=0;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(table1[i] == table2[j] && table1[i]>0 && table2[j]>0)
			{
				table1[i]=0;
				table2[j]=0;
			}
		}
	}
	for(int i=0;i<26;i++)
	{
		check1+=table1[i];
		check2+=table2[i];
	}
	
	if(check1 == 0 && check2==0)
	{
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	
	
	
	return 0; 
}
