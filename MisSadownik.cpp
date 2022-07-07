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

int main()
{
	int s=0;
	for(int i=0; i<32; i++)
	{
		if(ifthree(i))
		{
			bitset<5> b(i);
			cout<<i<<" - "<<b<<"\n";
			s++;
		}
	}
	cout<<s;
}
