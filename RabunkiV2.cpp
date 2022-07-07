#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> P, B;
vector<pair<int,int>> odp;
long long ans;

bool comp(pair<int,int> a, pair<int,int> b)
{
	if(a.first < 0 && b.first > 0) // <0 p bli¿ej, >0 p dalej 
	return false;
	
	if(a.first > 0 && b.first < 0)
	return true;
	
	if(a.first > 0 && b.first > 0)
	return a.second<b.second;
	
	if(a.first < 0 && b.first < 0)
	return a.second>b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		P.push_back(a);
	}
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		B.push_back(a);
		
		ans+=abs(B[B.size()-1]-P[B.size()-1]);
		
		odp.push_back({P[B.size()-1]-B[B.size()-1], i+1});
	}

	sort(odp.begin(), odp.end(), comp);
	
	cout<<ans<<"\n";
	for(int i=0; i<odp.size(); i++)
	cout<<odp[i].second<<" ";
}
