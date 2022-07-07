#include<iostream>
#include<algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register long long pole, p, k, s, count=100;
	
	cin>>pole;
	
	p=1;
	
	k=pole/2;
	
	s=k+p/2;
	

	
	while(count!=0)
	{
		if(s*s>=pole&&(s-1)*(s-1)<pole)
		break;
		else if(s*s<pole)
		{
			p=s+1;
		}
		else
		{
			k=s-1;	
		}
		s=(k+p)/2;

		count--;
	}
	
	
	
	cout<<s;
	
	return 0;
}
