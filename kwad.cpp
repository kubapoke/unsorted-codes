#include<bits/stdc++.h>
using namespace std;

set<int> pla[2001];
set<int>::iterator it1, it2, it3, it4;
long long n, w;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		pla[a+1000].insert(b);
	}
	
	for(int i=0; i<=2000; i++)
	{
		for(it1=pla[i].begin(); it1!=pla[i].end(); ++it1)
		{
			for(it2=it1; it2!=pla[i].end(); ++it2)
			{
				if(it1==it2)
				continue;
				
				int roz=abs(*it2-*it1);
				
				if(i+roz>2000)
				break;
				
				if(!pla[i+roz].empty())
				{
					it3=pla[i+roz].lower_bound(*it1); it4=pla[i+roz].lower_bound(*it2);
					if(*it3==*it1 && *it4==*it2)
					{
						cout<<i-1000<<" "<<*it1<<"   "<<i-1000<<" "<<*it2<<"   "<<i+roz-1000<<" "<<*it3<<"   "<<i+roz-1000<<" "<<*it4<<"\n";
						
						w++;
					}
					
				}	
			}
		}
	}
	
	//cout<<w;
}
