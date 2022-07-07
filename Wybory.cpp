#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin>>n;
	
	cout<<n<<"\n";
	
	for(int i=n+1; i<=2*n; i++)
	cout<<i<<" ";
	
}
