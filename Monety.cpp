#include<iostream>
using namespace std;

int main()
{
	int n, x, s=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>x;	
		s+=x;
	}
	
	if(s<=n-s)
	cout<<s;
	else
	cout<<n-s;
	
	
	return 0;
}
