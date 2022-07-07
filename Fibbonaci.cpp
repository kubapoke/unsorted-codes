#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register long long a=1, b=1, c=2, l=2, m, n;
	
	cin>>m>>n;
	
	if(m==0||m==1)
	{
		cout<<1%n;
		return 0;
	}
	
	while(l<m)
	{
		l++;
		a=b;
		b=c;
		c=a+b;
	}
	
	
	cout<<c%n;
}
