#include<bits/stdc++.h>
using namespace std;
const long long dz=(1<<30);

struct ST{
	long double len;
	long long pos, num;
};
	
bool comp(const ST &a, const ST &b)
{
	if(a.len!=b.len)
	return(a.len<b.len);
	return(a.pos>b.pos);
}

struct qs{
	long long q, idx, ans;
};

bool c1(const qs &a, const qs &b)
{
	return(a.q<b.q);
}
bool c2(const qs &a, const qs &b)
{
	return(a.idx<b.idx);
}

priority_queue<ST, vector<ST>, decltype(&comp)> PQ(comp);
vector<qs> zap;
queue<ST> Q;

int n, X, z, x, y, k, curr, ch;

int main()
{
	cin>>n>>X>>z;
	for(int i=0; i<n; i++)
	{
		y=x;
		cin>>x;
		if(i)
		{
			ST st;
			st.len=x-y;
			st.pos=y;
			st.num=1;
			PQ.push(st);
		}
	}
	for(int i=0; i<z; i++)
	{
		cin>>k;
		qs Z;
		Z.q=k;
		Z.idx=i;
		Z.ans=0;
		zap.push_back(Z);
	}
	
	sort(zap.begin(),zap.end(),c1);
	
	while(curr<zap[zap.size()-1].q)
	{
		if(PQ.size())
		{
			if(!Q.size())
			{
				ST st;
				st.len=PQ.top().len/2;
				st.pos=PQ.top().pos;
				st.num=PQ.top().num*2;
			}
			else if(PQ.top().len>)
		}
	}
}
