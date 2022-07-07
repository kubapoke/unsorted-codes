#include<bits/stdc++.h>
using namespace std;

int n;
int tab[2000001];
vector<int> v;

void odt_wynik()
{
	int x=0;
	
	for(int i=1; i<=2*n; i++)
	{
		if(tab[i]==0)
		{
			tab[i]=v[x];
			tab[i+v[x]]=v[x];
			x++;
		}
		cout<<tab[i]<<" ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	if(n%4>1)
	{
		cout<<"NIE";
		return 0;
	}
	
	if(n==5)
	{
		cout<<"TAK\n1 1 3 4 5 3 2 4 2 5";
		return 0;
	}
	
	if(n%4==0)
	{
		cout<<"TAK\n";
		int m=n;
		
		while(m>0)
		{
			v.push_back(m);
			m-=2;
		}
		
		v.push_back(n-1);
		v.push_back(n/2-1);
		
		m=n-1;
		
		while(m>0)
		{
			if(m!=n-1 && m!=n/2-1)
			v.push_back(m);
			m-=2;
		}
		
		odt_wynik();
	}
	
	if(n%4==1)
	{
		cout<<"TAK\n";
		int m=n-1;
		
		while(m>0)
		{
			v.push_back(m);
			m-=2;
		}
		
		v.push_back(n);
		v.push_back(n/2-1);
		
		m=n-2;
		
		while(m>0)
		{
			if(m!=n/2-1)
			v.push_back(m);
			m-=2;
		}
		
		odt_wynik();
	}
}
