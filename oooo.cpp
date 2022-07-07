#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{

	
	int w=0;
	cin>>n;
	
	while(n%2==0)
	{
		w++;
		n/=2;
	}
 	
	for(int i=3; i<=sqrt(n); i+=2)
	{
		while(n%i==0)
		{
			w++;
			n/=i;
		}
	}
	
	if(n>2)
	w++;
	
	cout<<w;
 	
}
