#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	
	cin>>n;
	
	int tab[n+1];
	int fin[n+1];
	int l[n];
	int p[n];
	
	for(int i=1; i<n+1; i++)
	tab[i]=0;
	
	for(int i=1; i<n; i++)
	{
		cin>>l[i]>>p[i];
		
		tab[l[i]]++;
		tab[p[i]]++;
	}
	
	tab[1]-=1;
	
	for(int i=1; i<n+1; i++)
	{
		if(tab[i]>2)
		tab[i]-=2;
		else
		tab[i]=0;
		
		tab[i]*=2;
	}
	
	
	sort(fin, fin+(n+1))
	
	cout<<fin[n];
}
