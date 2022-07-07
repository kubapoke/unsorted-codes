#include<bits/stdc++.h>
using namespace std;

int n;
char naw[1000001];
set<int> wart;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int p;
		cin>>p;
		
		if(wart.size() && wart.upper_bound(p)!=wart.begin())
		{
			naw[p]=')';
			naw[*prev(wart.upper_bound(p))]='(';
			wart.erase(prev(wart.upper_bound(p)));
		}
		else
		wart.insert(p);
	}
	
	while(wart.size())
	{
		if(wart.size()%2==0)
		naw[*prev(wart.end())]=')';
		else
		naw[*prev(wart.end())]='(';
		
		wart.erase(prev(wart.end()));
	}
	
	for(int i=1; i<=n; i++)
	cout<<naw[i];
}
