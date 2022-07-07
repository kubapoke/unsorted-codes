#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, w=30001;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	for(int i=0; i<n-1; i++)
	for(int j=n-1; j>i; j--)
	{
		if(tab[i]+tab[i+1]>tab[j])
		if(n-(i+n-1-j)<w)
		w=n-(i+(n-1)-j);
	}
	
	cout<<w;
}
