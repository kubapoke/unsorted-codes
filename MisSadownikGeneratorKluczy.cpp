#include<bits/stdc++.h>
using namespace std;

bool ifthree(int n)
{
	int c=0;
	
	//cout<<n<<": ";
	
	for(int i=16; i>0; i/=2)
	if(n>=i)
	{
		n-=i;
		c++;
	}
	
	//cout<<c<<"\n";
	
	if(c==3)
	return true;
	
	return false;
}

int rev(int n)
{
	int c=0, mn=1;
	for(int i=16; i>0; i/=2)
	{
		if(n>=i)
		{
			n-=i;
			c+=mn;
		}
		mn*=2;
	}
	
	return c;
}

int main()
{
	int s=0;
	for(int i=0; i<32; i++)
	{
		if(ifthree(i))
		{
			bitset<5> b(i);
			bitset<5> d(rev(i));
			cout<<b<<0<<d<<"\n";
			s++;
		}
	}
}
