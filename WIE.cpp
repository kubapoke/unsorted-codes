#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

multiset<pair<int,int>> S;
multiset<pair<int,int>>::iterator it;
multiset<pair<int,int>>::reverse_iterator rit;

int n, k, w, tab[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=1; i<=n; i++)
	{
		cin>>w;
		S.insert({w,i});
	}
	
	for(int i=0; i<k; i++)
	{
		it=S.begin();
		rit=S.rbegin();
		
		if(it->first==rit->first)
		{
			k=i;
			break;
		}
		
		//cout<<rit->second<<" "<<it->second<<"\n";
		tab[i]=rit->second;
		tab[i+100000]=it->second;
		
		int a=it->first;
		int b=it->second;
		
		int c=rit->first;
		int d=rit->second;
		
		S.erase(S.begin());
		S.erase(prev(S.end()));
		
		S.insert({a+1,b}); S.insert({c-1,d});
		
		//for(it=S.begin(); it!=S.end(); it++)
		//cout<<it->first<<" ";
		//cout<<"\n";
	}
	
	it=S.begin();
	rit=S.rbegin();
	
	cout<<rit->first-it->first<<" "<<k<<"\n";
	
	
	int i=0;
	while(tab[i]!=0 && i<100000)
	{
		cout<<tab[i]<<" "<<tab[i+100000]<<"\n";
		i++;
	}
	
}
