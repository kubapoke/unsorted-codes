#include<bits/stdc++.h>
using namespace std;

int main()
{
	int s=0;
	int g=1;
	while(g)
	{
		s+=60;
		if(g%5==1)
		s-=30;
		
		if(s>=300000)
		{
			cout<<g;
			return 0;
		}
		
		g++;
	}
}
