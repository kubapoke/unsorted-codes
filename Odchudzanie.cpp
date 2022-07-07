#include<iostream>
using namespace std;

int main()
{
	long long n, k, naj=0, w=0;
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>k;
		
		if(k>naj)
		naj=k;
		
		if(naj-k>w)
		w=naj-k;
	}
	
	cout<<w;
	
	return 0;
}
