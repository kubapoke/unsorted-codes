#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, naj, najm;
	
	cin>>n;
	
	cin>>a;
	
	naj=a;
	najm=a;
	
	for(int i=0; i<n-1; i++)
	{
		cin>>a;
		if(a>naj)
		naj=a;
		if(a<najm)
		najm=a;
	}
	cout<<naj<<" "<<najm;
}
