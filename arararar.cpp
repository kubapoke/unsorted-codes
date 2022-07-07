#include<bits/stdc++.h>
using namespace std;

long long idx=1;
map<long long,long long> imp;
vector<long long> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while(ans.size()<8000)
	{
		if(imp[idx]!=1)
		{
			for(int i=0; i<ans.size(); i++)
			{
				imp[idx+(idx-ans[i])]=1;
			}
			ans.push_back(idx);
		}
		idx++;
	}
	
	for(int i=0; i<ans.size(); i++)
	{
		cout<<i+1<<" "<<ans[i];
		if(i>0)
		cout<<" - "<<ans[i]-ans[i-1];
		cout<<"\n";
	}
}
