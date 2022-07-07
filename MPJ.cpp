#include<bits/stdc++.h>
using namespace std;
long long n, a, b, aq, bq, w;

int main()
{
	cin>>n;
	
	while(1)
	{
		if(a*a>n)
		{
			cout<<"NIE";
			return 0;
		}
		if(w<n)
		{
			b++;
			w+=b*b;
		}
		else if(w>n)
		{
			a++;
			w-=a*a;
		}
		else if(w==n)
		{
			cout<<a+1<<" "<<b;
			return 0;
		}
	}
}
