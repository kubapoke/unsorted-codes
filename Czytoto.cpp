#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, a, b;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		cin>>b;
		
		cout<<count(tab, tab+n, b)<<'\n';
	}
	

	
	return 0;
}
