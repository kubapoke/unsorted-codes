#include<bits/stdc++.h>
using namespace std;

int Z, n, s[5001], p[5001], c[5001];
vector<int> graf[5001];

vector<pair<long long,long long>> merge(vector<pair<long long,long long>> v, vector<pair<long long,long long>> u)
{
	vector<pair<long long,long long>> ans;
	
	vector<pair<long long,long long>>::iterator it, ir;
	it=v.begin(); ir=u.begin();
	
	while(it!=v.end() || ir!=u.end())
	{
		if(it!=v.end() && ir!=u.end())
		{
			if(it->first==ir->first+1)
			{
				ans.push_back({it->first,it->second+ir->second});
				it++;
				ir++;
			}
			else if(it->first<ir->first+1)
			{
				ans.push_back({it->first,it->second});
				it++;
			}
			else if(it->first>ir->first+1)
			{
				ans.push_back({ir->first+1,ir->second});
				ir++;
			}
		}
		else
		{
			if(it!=v.end())
			{
				ans.push_back({it->first,it->second});
				it++;
			}
			else if(ir!=v.end())
			{
				ans.push_back({ir->first+1,ir->second});
				ir++;
			}
		}
	}
	
	return ans;
}

vector<pair<long long,long long>> flatten(vector<pair<long long,long long>> v, int l)
{
	if(v.empty() || l==0)
	return v;
	
	long long nad=0, currh=0, pocz=v[0].first, prevh=0, hdiff=0; //nadmiar, obecna wysokoœæ, od jakiego pola zaczynamy
	
	vector<long long> h;
	vector<long long> w;
	
	vector<pair<long long,long long>> ans;
	
	for(int i=1; i<v.size(); i++)
	{
		currh+=v[i-1].second;
		 if(currh==l)
		 {
		 	h.push_back(currh);
			w.push_back(v[i].first-v[i-1].first);
		 }
		 else if(currh>l)
		 {
		 	h.push_back(l);
		 	w.push_back(v[i].first-v[i-1].first);
		 	nad+=(currh-l)*(v[i].first-v[i-1].first);
		 }
		 else if(currh<l)
		 {
		 	long long spa=(l-currh)*(v[i].first-v[i-1].first);;;;;;;;
		 	
		 	if(spa<=nad)
		 	{
		 		nad-=spa;
		 		h.push_back(l);
		 		w.push_back(v[i].first-v[i-1].first);
			}
			else if(spa>nad)
			{
				long long a=nad/(l-currh), b=nad%(l-currh);
				nad=0;
				
				if(!a && !b)
				{
					h.push_back(currh);
					w.push_back(v[i].first-v[i-1].first);
				}
				else if(a)
				{
					h.push_back(l);
					w.push_back(a);
					
					if(b)
					{
						h.push_back(currh+b);
						w.push_back(1);
						h.push_back(currh);
						w.push_back(v[i].first-v[i-1].first-a-1);
					}
					else
					{
						h.push_back(currh);
						w.push_back(v[i].first-v[i-1].first-a);
					}
				}
				else if(b)
				{
					h.push_back(currh+b);
					w.push_back(1);
					h.push_back(currh);
					w.push_back(v[i].first-v[i-1].first-1);
				}
			}
		 }
	}
	
	if(nad)
	{
		long long a=nad/(l), b=nad%(l);
		if(a)
		{
			h.push_back(l);
			w.push_back(a);
		}
		if(b)
		{
			h.push_back(b);
			w.push_back(1);
		}
	}
	
	currh=0;
	
	for(int i=0; i<h.size(); i++)
	{
		hdiff=h[i]-prevh;
		prevh=h[i];
		
		currh+=hdiff;
		
		if(hdiff)
		ans.push_back({pocz,hdiff});
		
		pocz+=w[i];
	}
	
	ans.push_back({pocz,-currh});
	
	return ans;
}

vector<pair<long long,long long>> dfs(int v)
{
	vector<pair<long long,long long>> w;
	
	if(v!=1)
	{
		int a=s[v]/c[v], b=s[v]%c[v];
		
		if(a)
		{
			w.push_back({0,c[v]});
			w.push_back({a,-c[v]+b});
			if(b)
			w.push_back({a+1,-b});
		}
		else if(b)
		{
			w.push_back({0,b});
			w.push_back({1,-b});
		}
	}
	
//	cout<<v<<": ";
//	for(int i=0; i<w.size(); i++)
//	cout<<w[i].first<<" "<<w[i].second<<"   ";
//	cout<<"\n";
	
	for(int i=0; i<graf[v].size(); i++)
	{
		w=merge(w,dfs(graf[v][i]));
	}
	
//	cout<<v<<" merged: ";
//	for(int i=0; i<w.size(); i++)
//	cout<<w[i].first<<" "<<w[i].second<<"   ";
//	cout<<"\n";
	
	w=flatten(w,c[v]);
	
//	cout<<v<<" flattened: ";
//	for(int i=0; i<w.size(); i++)
//	cout<<w[i].first<<" "<<w[i].second<<"   ";
//	cout<<"\n";
	
	return w;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>Z;
	
for(int mm=0; mm<Z; mm++)
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		graf[i].clear();
	}
	for(int i=2; i<=n; i++)
	{
		cin>>s[i];
	}	
	for(int i=2; i<=n; i++)
	{
		cin>>p[i];
		graf[p[i]].push_back(i);
	}	
	for(int i=2; i<=n; i++)
	{
		cin>>c[i];
	}	
	
	vector<pair<long long,long long>> ans=dfs(1);
	
	cout<<ans[ans.size()-1].first-1<<"\n";
}
}
