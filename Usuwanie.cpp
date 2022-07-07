#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b=1, count, w, naj=0;
	
	cin>>n;
	
	cin>>a;
	b=a;
	naj=a;
	
	for(int i=1; i<n; i++)
	{
		cin>>a;
		if(a==b&&a==naj)
		{
			count++;		
		}
		else if(a>naj)
		{
			count=1;
			naj=a;
		}
		else
		count=1;
		b=a;
	}
	
	if(count%2!=0)
	cout<<"Lukasz";
	else
	cout<<"Marcin";
	
	
}
