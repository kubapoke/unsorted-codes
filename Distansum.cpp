#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, w=0, p=0, o=0;
	cin>>n;
	int t[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>t[i];
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			p=t[i]+t[j]+o;
			if(p>w)
			w=p;
			o++;
		}
		o=0;
		if(p>w)
		w=p;
	}
	
	
	cout<<w;
	
	
	return 0;
}
