#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, k, najw=0, w=0;
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>k;
		
		if(k>najw)
		najw=k;
		
		if(najw-k>w)
		w=najw-k;
	}
	
	cout<<w;
	
	return 0;
}
