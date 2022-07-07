#include<iostream>
using namespace std;

int main()
{
	//5 3 4 3 2 4 1 2 1 3 5 1 4 1
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, w=0, jed=0, zer=0;
	
	cin>>n;
	
	int tab[n];
	
	if(n==1)
	{
		cin>>tab[0];
		cout<<tab[0];
		return 0;
	}
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
		if(tab[i]==1)
		jed++;
		
		if(i>0)
		if(tab[i]==0&&tab[i-1]==0)
		zer++;
	}
	
	if(tab[n-1]==0&&tab[0]==0)
	zer++;
	
	w=n/3;
	
	if(n%3!=0)
	w++;
	
	w-=zer;
	
	
	cout<<w;
}
