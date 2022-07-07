#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string s;
long long odp[100001];
vector<string> wyr[100001];
int a, b, c;

void wypisz(string ss)
{
	for(int i=0; i<ss.size(); i++)
	{
		if(ss[i]==9)
		cout<<"\\t";
		else if(ss[i]==10)
		cout<<"\\n";
		else
		cout<<ss[i];
	}
	
	cout<<"\n";
}

int getone(int p)
{
	return(s[p]-48);
}

int gettwo(int p)
{
	if(p<1) return 0;
	if(s[p-1]=='0') return 0;
	return (s[p]-48+10*(s[p-1]-48));
}

int getthree(int p)
{
	if(p<2) return 0;
	if(s[p-2]=='0') return 0;
	return (s[p]-48+10*(s[p-1]-48)+100*(s[p-2]-48));
}

long long ans=0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	
	for(int i=0; i<s.size(); i++)
	{
		a=getone(i); b=gettwo(i); c=getthree(i);
		
		if(a==9)
		{
			if(i==0)
			odp[0]+=1;
			else
			odp[i]=(odp[i]%MOD+odp[i-1]%MOD)%MOD;
		}
		if(b==10||b==32||(b>=48 && b<=57)||(b>=65 && b<=90)||b>=97)
		{
			if(i==1)
			odp[1]+=1;
			else
			odp[i]=(odp[i]%MOD+odp[i-2]%MOD)%MOD;
		}
		if(c>=100&&c<=122)
		{
			if(i==2)
			odp[2]+=1;
			else
			odp[i]=(odp[i]%MOD+odp[i-3]%MOD)%MOD;
		}
	}
	
	cout<<odp[s.size()-1]<<"\n";
	
	if(odp[s.size()-1]<100)
	{
		for(int i=0; i<s.size(); i++)
		{
			a=getone(i); b=gettwo(i); c=getthree(i);
			
			if(a==9)
			{
				char z=a;
				
				if(i==0)
				{
					wyr[0].push_back("");
					wyr[0][wyr[0].size()-1].push_back(z);
				}
				else
				for(int j=0; j<wyr[i-1].size(); j++)
				{
					wyr[i].push_back(wyr[i-1][j]);
					wyr[i][wyr[i].size()-1].push_back(z);
				}
			}
			if(b==10)
			{
				char z=b;
				
				if(i==1)
				{
					wyr[1].push_back("");
					wyr[1][wyr[1].size()-1].push_back(z);;
				}
				else
				for(int j=0; j<wyr[i-2].size(); j++)
				{
					wyr[i].push_back(wyr[i-2][j]);
					wyr[i][wyr[i].size()-1].push_back(z);
				}
			}
			if(b==32||(b>=48 && b<=57)||(b>=65 && b<=90)||b>=97)
			{
				char z=b;
				
				if(i==1)
				{
					wyr[1].push_back("");
					wyr[1][wyr[1].size()-1].push_back(z);
				}
				else
				for(int j=0; j<wyr[i-2].size(); j++)
				{
					wyr[i].push_back(wyr[i-2][j]);
					wyr[i][wyr[i].size()-1].push_back(z);
				}
			}
			if(c>=100&&c<=122)
			{
				char z=c;
				
				if(i==2)
				{
					wyr[2].push_back("");
					wyr[2][wyr[2].size()-1].push_back(z);
				}
				else
				for(int j=0; j<wyr[i-3].size(); j++)
				{
					wyr[i].push_back(wyr[i-3][j]);
					wyr[i][wyr[i].size()-1].push_back(z);
				}
			}
			if(i>3)
			wyr[i-4].clear();
		}
		
		sort(wyr[s.size()-1].begin(),wyr[s.size()-1].end());
		
		for(int j=0; j<wyr[s.size()-1].size(); j++)
		wypisz(wyr[s.size()-1][j]);
	}
	
}
