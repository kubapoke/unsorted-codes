#include<bits/stdc++.h>
using namespace std;

int n, arr[40], sum;
vector<pair<int,string>> left20;
unordered_map<int,string> right20;

void brut20(int sm, string &st, bool oi)
{
	string h=st;
	
	if(oi==false)
	{
		h.push_back('0');
	}
	else
	{
		h.push_back('1');
		sm+=arr[h.size()-1];
	}
	
	if(sm==sum)
	{
		while(h.size()<n)
		h.push_back('0');
		cout<<h;
	}
	
	if(h.size()<n)
	{
		brut20(sm,h,false);
		brut20(sm,h,true);
	}
}

void first20(int sm, string &st, bool oi)
{
	string h=st;
	
	if(oi==false)
	{
		h.push_back('0');
	}
	else
	{
		h.push_back('1');
		sm+=arr[h.size()-1];
	}
	
	left20.push_back({sm,h});
	
	if(h.size()<(n/2))
	{
		first20(sm,h,false);
		first20(sm,h,true);
	}
}

void second20(int sm, string &st, bool oi)
{
	string h=st;
	
	if(oi==false)
	{
		h.push_back('0');
	}
	else
	{
		h.push_back('1');
		sm+=arr[(n/2)+h.size()-1];
	}
	
	right20[sm]=h;
	
	if(h.size()+(n/2)<n)
	{
		second20(sm,h,false);
		second20(sm,h,true);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	cin>>sum;
	
	if(n<=20)
	{
		string s;
		brut20(0,s,false);
		brut20(0,s,true);
	}
	else
	{
		string s;
		first20(0,s,false);
		first20(0,s,true);
		second20(0,s,false);
		second20(0,s,true);
		
		for(int i=0; i<left20.size(); i++)
		{
			if(right20[sum-left20[i].first]!="")
			{
				s=left20[i].second.append(right20[sum-left20[i].first]);
				cout<<s;
			}
		}
	}
	
}
