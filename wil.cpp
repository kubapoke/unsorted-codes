#include<bits/stdc++.h>
#define N 2000010
using namespace std;

int n, d, w, dol[N];
long long p, pref[N], dech[N];
list< pair<long long, int> > qmax;

void add(long long v, int idx)
{
	while(!qmax.empty()&&qmax.back().first<=v)
	qmax.pop_back();
	qmax.push_back({v,idx});
}

void sub(int idx)
{
	if(qmax.front().second==idx)
	qmax.pop_front();
}

long long maks()
{
	if(!qmax.empty())
	return qmax.front().first;
	return 1e18;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>p>>d;
	w=d;
	
	for(int i=1; i<=n; i++)
	{
		cin>>dol[i];
		pref[i]=pref[i-1]+dol[i];
	}
	
	for(int i=1; i<=n-d+1; i++)
	dech[i]=pref[i+d-1]-pref[i-1];
	
	add(dech[1],1);
	
	int i=1; int j=d;
	
	while(1)
	{
		if(j>=n) break;
		
		if(pref[j+1]-pref[i-1]-max(maks(),dech[j-d+2])<=p)
		{
			add(dech[j-d+2],j-d+2); j++;
		}
		else
		{
			sub(i); i++;
		}
		w=max(w,j-i+1);
	}
	
	cout<<w;
}
