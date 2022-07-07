#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int,vector<int>,greater<int>> PQ;
ll n, cz;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	while(n)
	{
		if(n%10!=0)
		PQ.push(n%10);
		else
		cz++;
		n/=10;
	}
	
	cout<<PQ.top();
	PQ.pop();
	
	for(int i=0; i<cz; i++)
	cout<<"0";
	
	while(PQ.size())
	{
		cout<<PQ.top();
		PQ.pop();
	}
}
