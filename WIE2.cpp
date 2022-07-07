#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

multiset<pair<int,int>> S;
multiset<pair<int,int>>::iterator it;
multiset<pair<int,int>>::reverse_iterator rit;
queue<int> Q;

int n, k, w;

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
		
		Q.push(rit->second);
		Q.push(it->second);
		
		int a=it->first;
		int b=it->second;
		
		int c=rit->first;
		int d=rit->second;
		
		S.erase(it); rit--; S.erase(rit.base());
		
		S.insert({a+1,b}); S.insert({c-1,d});
	}
	
	it=S.begin();
	rit=S.rbegin();
	
	cout<<rit->first-it->first<<" "<<k<<"\n";
	
	cout<<"\n\n";
	
	while(Q.size())
	{
		cout<<Q.front()<<" ";
		Q.pop();
		cout<<Q.front()<<"\n";
	}
}
