#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long a, n, sum=0;
	
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>a;
		sum+=a;
	}
	
	if(sum%n==0)
	cout<<"TAK";
	else
	cout<<"NIE";
	
	return 0;
}
