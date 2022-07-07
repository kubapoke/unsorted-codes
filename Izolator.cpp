#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int a, w=0, x=0, z;
	
	cin>>a;
	
	int tab[a];
	
	z=a-1;
	
	for(int i=0; i<a; i++)
	cin>>tab[i];
	
	sort(tab, tab+a);
	
	while(x<z)
	{
		w+=tab[x]+tab[z];
		w+=tab[z]-tab[x];
		x++;
		z--;
	}
	
	if(x==z)
	w+=tab[x];
	
	cout<<w;
	
}
