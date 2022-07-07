#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, a=0, b;
	bool wyn=true;
	cin>>N;
	for(int i=0; i<N; i++)
	{
		b=a;
		cin>>a;
		if(a<b)
		wyn=false;
	}
	
	if(wyn==true)
	cout<<"TAK";
	else
	cout<<"NIE";
}
