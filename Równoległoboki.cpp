#include<iostream>
using namespace std;

int main()
{
	int tab[4];
	bool czy=true;
	
	for(int i=0; i<4; i++)
	{
		cin>>tab[i];
	}
	
	for(int i=0; i<4; i++)
	{
		for(int j=i+1; j<4; j++)
		{
			if(tab[i]==tab[j]&&tab[i]!=0&&tab[j]!=0)
			{
				tab[i]=0;
				tab[j]=0;
			}
		}
	}
	
	for(int i=0; i<4; i++)
	{
		if(tab[i]!=0)
		czy=false;
	}
	
	if(czy==true)
	cout<<"TAK";
	else
	cout<<"NIE";
	
	return 0;
}
