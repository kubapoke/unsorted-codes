#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, w=0, jed=0, zer=0, a=-1, b=-1;
		
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		b=a;
		
		cin>>a;
		
		if(a==1)
		jed++;
		else
		zer++;
		
		if(a==b&&a==1)
		{
			w++;
		}		
		
	}
	
	if(zer<jed-1)
	{
		cout<<"-1";
		return 0;
	}
	
	
	cout<<w;	
}
