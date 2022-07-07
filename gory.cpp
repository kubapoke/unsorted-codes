#include<iostream>
using namespace std;

int tab[1000000];
int wys[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b, MAX=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	cin>>a>>b;
	
	wys[a-1]=b;
	
	if(a!=1)
	wys[0]=tab[0]-b;
	
	if(a!=n)
	wys[n-1]=tab[n-1]-b;
	
	MAX=wys[0];
	
	for(int i=1; i<a-1; i++)
	{
		wys[i]=tab[i]-MAX-b;
		
		if(wys[i]>MAX)
		MAX=wys[i];
	}
	
	MAX=wys[n-1];
	
	for(int i=n-2; i>a-1; i--)
	{
		wys[i]=tab[i]-MAX-b;
		
		if(wys[i]>MAX)
		MAX=wys[i];
	}
	
	for(int i=0; i<n; i++)
	cout<<wys[i]<<" ";
	
}
