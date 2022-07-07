#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	register long long naj=0, a, b, c, d;
	
	cin>>a;
	if(a>naj)
	naj=a;
	
	cin>>b;
	if(b>naj)
	naj=b;
	
	cin>>c;
	if(c>naj)
	naj=c;
	
	cin>>d;
	if(d>naj)
	naj=d;
	
	cout<<naj+1;
	
	
	return 0;
}
