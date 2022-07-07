#include<bits/stdc++.h>
using namespace std;

struct mur{
	int w, idx;
}m[500001];

bool compare(const mur &x, const mur &y)
{
	return x.w>y.w;
}

int n, uz[500001], ans;
set<int> ktore[500001];
set<int>::iterator it1, it2;

int main()
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>m[i].w;
		m[i].idx=i;
	}
	
	sort(m+1,m+n+1,compare);
	
	int g=n, s=0;
	
	for(int i=1; i<=n; i++)
	//cout<<m[i].w<<" "<<m[i].idx<<"\n";
	
		
	while(g>0)
	{
		s++;
		
		for(int i=1; i<=n; i++)
		{
			it1=ktore[s].upper_bound(m[i].idx);
			it2=ktore[s].lower_bound(m[i].idx-1);
			//cout<<*it1<<" "<<*it2<<" "<<m[i].idx<<"\n";
			
			if(uz[i]==0)
			{
				if(ktore[s].empty())
				{
					uz[i]++;
					ktore[s].insert(m[i].idx);
					ans+=m[i].w;
					g--;
					//cout<<"!\n";
				}
				else if(*it1!=m[i].idx+1&&*it2!=m[i].idx-1)
				{
					uz[i]++;
					ktore[s].insert(m[i].idx);
					g--;
					//cout<<"!\n";
				}
			}
			
		}
	}
	
	cout<<ans;
}
