#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, star, ser=0, c, w=1;
	
	cin>>n>>k;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	star=tab[0];
			
	sort(tab, tab+n);
	
	while(tab[ser]!=star)
	{
		ser++;
	}	
	
	c=ser;
	
	//w dó³
	while(1)
	{
		if(c>0)
		c--;
		else
		break;
		
		if(tab[c+1]-tab[c]>k)
		break;
		else w++;
	}
	
	c=ser;
	
	// w górê
	while(1)
	{
		if(c<n-1)
		c++;
		else
		break;
		
		if(tab[c]-tab[c-1]>k)
		break;
		else w++;
	}	
	
	cout<<w;
}
