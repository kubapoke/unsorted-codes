#include<bits/stdc++.h>
using namespace std;

int N, M, a, b, pri[200001], vis[200001], st;
vector<int> graf[200001], wynik;
stack<int> S;

bool comp(int a, int b)
{
	return pri[a]>pri[b];
}

int main()
{
	cin>>N>>M;
	
	for(int i=0; i<M; i++)
	{
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	for(int i=0; i<N; i++)
	{
		int x;
		cin>>x;
		pri[x]=i;
		
		if(i==0)
		st=x;
	}
	
	S.push(st);
	vis[st]=1;
	
	while(!S.empty())
	{
		int x=S.top();
		wynik.push_back(x);
		S.pop();
		vector<int> temp;
		
		for(int i=0; i<graf[x].size(); i++)
		{
			if(vis[graf[x][i]]==0)
			{
				vis[graf[x][i]]++;
				temp.push_back(graf[x][i]);
			}
		}
		
		sort(temp.begin(), temp.end(), comp);
		
		for(int i=0; i<temp.size(); i++)
		S.push(temp[i]);
	}
	
	if(wynik.size()!=N)
	{
		cout<<"NIE";
		return 0;
	}
	
	for(int i=0; i<wynik.size(); i++)
	if(pri[wynik[i]]!=i)
	{
		cout<<"NIE";
		return 0;
	}
	
	
	
	cout<<"TAK";
}
