#include<bits/stdc++.h>
#define N 4001
using namespace std;

int n, v[N], d[N], p[N], mv, md, ans;
queue<int> Q;
priority_queue<int, vector<int>, greater<int>> PQ; //kolejka kolejnych czasów, w których krzyk v któregoœ dziecka przestaje mieæ znaczenie

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	cin>>v[i]>>d[i]>>p[i];
	
	for(int i=1; i<=n; i++)
	{
		if(p[i]-mv-md>=0)
		{
			ans++;
			Q.push(i);
			
			mv+=v[i];
			PQ.push(i+v[i]);
			
			mv++; //?
		}
		else
		md+=d[i];
		
		mv-=PQ.size();
		while(PQ.size() && PQ.top()==i)
		PQ.pop();
	}
	
	cout<<ans<<"\n";
	while(Q.size())
	{
		cout<<Q.front()<<" ";
		Q.pop();
	}
}
