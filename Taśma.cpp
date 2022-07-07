#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, a, w=1000000001;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		if(a<w)
		w=a;
	}
	
	cout<<w<<".00";
	
}
