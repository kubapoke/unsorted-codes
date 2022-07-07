#include<iostream>
using namespace std;

int main()
{
	register int n, d, w=1000000, tw=0, l, ch=0, dzi=0, x=0, zer=0;
	bool czy=false;
	
	cin>>n>>d;
	
	int sprawdz[n];
	
	
	
	for(int i=0; i<n; i++)
	{
		cin>>l;
		
		if(czy==true)
		{
			if(l==1)
			ch++;
			else
			{
				sprawdz[x]=ch;
				//cout<<sprawdz[x]<<endl;
				ch=0;
				x++;	
			}
		}
		
		if(l==0)
		{
			czy=true;
			zer++;
		}
		
		//cout<<x<<endl;
		//cout<<ch<<endl;
	}
	
	if(zer<d)
	{
		cout<<"NIE";
		return 0;
	}
	
	for(int i=0; i<x; i++)
	{
		for(int j=i; j<i+d; j++)
		tw=tw+sprawdz[j];
		
		if(tw<w)
		w=tw;
		
		//cout<<tw<<endl;
		
		tw=0;
	}
	
	if(w==1000000)
	cout<<"0";
	else
	cout<<w;
	
	return 0;
}
