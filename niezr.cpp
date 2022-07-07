#include<bits/stdc++.h>
using namespace std;

bool niezr(int n)
{
	int par=0, npar=0;
	for(int i=1; i*i<=n; i++)
	{
		if(n%i==0)
		{
			if(i%2==0)
			par++;
			if(i%2==1)
			npar++;
			if(i*i!=n)
			{
				if((n/i)%2==0)
				par++;
				if((n/i)%2==1)
				npar++;
			}
		}
	}
	
	if(par>npar*2 || npar>par*2)
	return true;
	
	return false;
}

int main()
{
	int idx=1;
	for(int i=1; i<100; i++)
	{
		if(niezr(i)==true/* && i%2==0*/)
		{
			cout<<idx<<": "<<i<<"\n";
			idx++;
		}
	}
}
