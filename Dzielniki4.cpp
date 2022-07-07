#include<bits/stdc++.h>
using namespace std;

int maks;
set<int> dzielniki;

void dziel(int n)
{
	for(int i=1; i*i<=n; i++)
	{
		if(n%i==0)
		{
			dzielniki.insert(i);
			dzielniki.insert(n/i);
		}
	}
}

int main()
{
	for(int i=1; i<=1000; i++)
	{
		for(int j=i; j<=1000; j++)
		{
			dziel(i); dziel(j);
			if(dzielniki.size()>maks)
			maks=dzielniki.size();
			dzielniki.clear();
 		}
	}
	
	cout<<maks;
}
