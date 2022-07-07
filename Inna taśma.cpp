#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, w=1001, s=0, s1=0, s2=0;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
		s+=tab[i];
	}
		
	if(n<=1)
	{
		cout<<tab[0];
		return 0;
	}
	
	s2=s;
	
	for(int i=0; i<n; i++)
	{
		s1+=tab[i];
		s2-=tab[i];
		
		if(s2>=s1)
		{
			if(s2-s1<w)
			w=s2-s1;
		}
		else
		{
			if(s1-s2<w)
			w=s1-s2;
		}	
	}
	
	if(w==0)
	w+=1998;
	
	cout<<w;
	
}
