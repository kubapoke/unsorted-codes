#include<iostream>
#include <iomanip>      
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	
	register long long a, b, w, w2;
	
	cin>>a>>b;
	
	a/=1000;
	
	w=a-b;
	
	w*=1000;
	
	w2=a/(b+1)-1;
	
	w2*=1000;
	
	if(w<=w2&&w>0)
	cout<<w;
	else if(w2<w&&w2>0)
	cout<<w2;
	else
	cout<<"0";
	
	return 0;
}
