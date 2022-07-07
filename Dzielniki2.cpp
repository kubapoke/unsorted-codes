#include<bits/stdc++.h>
using namespace std;

map<int,int> mozl;
map<int,int>::iterator it;
map<int,vector<int>> dzielniki;
map<int,vector<int>>::iterator x;
bool d[1001][1001];

int main()
{
	for(int i=1; i<=1000; i++)
	for(int j=1; j<=1000; j++)
	if(i%j==0)
	d[i][j]=true;
	
	for(int i=1; i<=1000; i++)
	for(int j=1; j<=1000; j++)
	mozl[i*j]=max(mozl[i*j], max(i,j));
	
	for(it=mozl.begin(); it!=mozl.end(); it++)
	{
		for(int i=1; i<=it->second; i++)
		{
			if(it->first%i==0)
			dzielniki[it->first].push_back(i);
		}
	}
	
	int maks=0, temp=0;
	
	for(x=dzielniki.begin(); x!=dzielniki.end(); x++)
	{
		for(int i=26; i<=1000; i++)
		{
			temp=0;
			for(int j=0; j<x->second.size(); j++)
			{
				if(d[x->second[j]][i]==true)
				temp++;
			}
			maks=max(maks,temp);
		}
	}
	
	cout<<maks<<"\n";
	
	for(x=dzielniki.begin(); x!=dzielniki.end(); x++)
	{
		for(int i=26; i<=1000; i++)
		{
			temp=0;
			for(int j=0; j<x->second.size(); j++)
			{
				if(d[x->second[j]][i]==true)
				temp++;
			}
			if(temp==maks)
			{
				cout<<i<<" "<<x->first<<"\n";
				for(int j=0; j<x->second.size(); j++)
				cout<<x->second[j]<<" ";
			}
		}
	}
}
