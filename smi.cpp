#include<bits/stdc++.h>
#define N 100001
using namespace std;

list<pair<int,int> > graf[N];
int n, m, a, b, s, t, ile, visited[N], onstack[N], nr;
vector<int> cycles[1000005], euler;
stack<int> st;

struct edge
{
	int a,b;
	list<pair<int,int> >::iterator it1, it2;
}kraw[1000005];

void cut(int num)
{
	graf[kraw[num].a].erase(kraw[num].it1);
	graf[kraw[num].b].erase(kraw[num].it2);
}

void dfs(int v)
{
	while(graf[v].size())
	{
		list<pair<int,int> >::iterator it=graf[v].begin();
		int u, num;
		u=(*it).first; num=(*it).second;
		cut(num);
		dfs(u);
	}
	euler.push_back(v);
}

void find(int p)
{
	euler.clear();
	while(st.size())
	st.pop();
	
	dfs(p);
	for(int i=0; i<euler.size(); i++)
	{
		int v=euler[i];
		if(onstack[v])
		{
			cycles[ile].push_back(v);
			while(st.top()!=v)
			{
				onstack[st.top()]=0;
				cycles[ile].push_back(st.top());
				st.pop();
			}
			cycles[ile++].push_back(v);
		}
		else
		{
			onstack[v] = 1;
			st.push(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b>>s>>t;
		if(s!=t)
		{
			graf[a].push_front(make_pair(b,nr));
			graf[b].push_front(make_pair(a,nr));
			kraw[nr].a = a;
			kraw[nr].b = b;
			kraw[nr].it1 = graf[a].begin();
			kraw[nr++].it2 = graf[b].begin();
		}
	}
	
	for(int i=1; i<=n; i++) 
	if(graf[i].size()%2==1) 
	{
		cout<<"NIE";
		return 0;
	}
	
	for(int i=1; i<=n; i++) 
	if(graf[i].size()) 
	find(i);
	
	cout<<ile<<"\n";
	
	for(int i=0; i<ile; i++)
	{
		cout<<cycles[i].size()-1<<" ";
		for(int j=0; j<cycles[i].size(); j++) cout<<cycles[i][j]<<" ";
		cout<<"\n";
	}
}
