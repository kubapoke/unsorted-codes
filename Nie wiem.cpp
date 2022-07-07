#include<iostream>
using namespace std;

int main()
{
	int n, x=0, c=0;
	
	cin>>n;
	
	for(int i = 1; i * i <= n; i++)
    if (n % i == 0)
    {
        x=x+2;
    }
    
    int tab[x];
    
    for(int i = 1; i * i <= n; i++)
    if (n % i == 0)
    {
        tab[c]=i;
        tab[x]=n/i;
        c++;
    }
    
    for(int i=1; i<x; i++)
    {
    	if(tab[x]!=0)
    	cout<<tab[x]<<" ";
	}
	
	return 0;
}
