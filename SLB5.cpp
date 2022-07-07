#include<bits/stdc++.h>
using namespace std;

string s, kmin, kmax;
long long w, mn, wmin=1e11, wmax=0;

int main()
{
	for(int i=0; i<999; i++)
	{
		cin>>s;
		
		int r=s[s.size()-1]-48;
		mn=1; w=0;
		
		for(int i=s.size()-2; i>=0; i--)
		{
			w+=(s[i]-48)*mn;
			mn*=r;
		}
		
		if(w>wmax)
		{
			wmax=w;
			kmax=s;
		}
		if(w<wmin)
		{
			wmin=w;
			kmin=s;
		}
		
	}
	cout<<kmin<<"\n"<<kmax<<"\n"<<wmin<<"\n"<<wmax;
}
