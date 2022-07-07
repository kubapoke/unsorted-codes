#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, count=1;
	
	cin>>n;
	int tab[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
	}
	
	sort(tab, tab+n);
	
	for(int i=n-2; i>=0; i--)
	{
		if(tab[i]==tab[i+1])
		count++;
		else
		{
			if(count%2!=0)
			{
				cout<<"Lukasz";
				return 0;	
			}
			
			count=1;
		}
	}
	
	if(n%2==0)
	cout<<"Marcin";
	else
	cout<<"Lukasz";
}
