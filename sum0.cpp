#include<bits/stdc++.h>
using namespace std;

int N, A;
map<int,vector<int> > wiel;
map<int,int> czy;
map<int,vector<int> >::iterator it;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		int B=A;
		cin>>A;
		A+=B;
		//cout<<A<<endl;
		
		for(int j=1; j*j<=A; j++)
		{
			if(A%j==0)
			{
				wiel[j].push_back(A);
				if(j*j!=A)
				wiel[A/j].push_back(A);
				
				if(i==N-1)
				{
					czy[j]++;
					if(j*j!=A)
					czy[A/j]++;
				}
			}
		}
	}
	
	for(it=wiel.begin(); it!=wiel.end(); it++)
	{
		//cout<<it->first<<" "<<it->second[it->second.size()-1]<<endl;
		if(it->second[it->second.size()-1]==it->first*it->second.size() && czy[it->first]>0)
		{
			cout<<it->second.size();
			return 0;
		}
		
	}
}
