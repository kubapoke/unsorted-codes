#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, cnt=0, s=0, cck=0;
	
	cin>>n;
	
	for(int i=1; i*i<=n; i++)
    if (n%i==0)
    {
        cnt=cnt+2;
    }
    
    int tab[cnt];
    
    for(int i=1; i*i<=n; i++)
    if (n%i==0)
    {
        tab[s]=i;
        tab[s+1]=n/i;
        s=s+2;
    }
    
    sort(tab, tab+cnt);
    
    for(int i=0; i<cnt; i++)
    {
    	if(tab[i]!=0 && tab[i]!=cck)
    	cout<<tab[i]<<endl;
    	
    	cck=tab[i];
	}
	
	return 0;
}
