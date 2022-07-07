#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register long long n, a, start=0, odl=0, w=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		
		if(a>=start+odl)
		{
			start=a;
			odl=0;
		}
				
		if(start+odl+a>w)
		w=start+odl+a;
		
		odl++;
	}
	
	cout<<w;
}
