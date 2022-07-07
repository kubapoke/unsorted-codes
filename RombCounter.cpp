#include<bits/stdc++.h>
using namespace std;

long long romb(long long n)
{
	long long ans=n;
	
	while(n)
	{
		ans*=(n%10);
		n/=10;
	}
	
	return ans;
}

long long pararomb(long long n)
{
	long long ans=1;
	
	while(n)
	{
		ans*=(n%10);
		n/=10;
	}
	
	return ans;
}

long long tab[1000001], pri;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(long long i=1; i<=10000000; i++)
	{
		cout<<i<<" * "<<pararomb(i)<<" = "<<romb(i)<<"\n";
		//PQ.push({romb(i), i});
		
		if(romb(i)>i*i)
		{
			cout<<"NIE";
			break;
		}
		//long long R=romb(i);
		
		//if(R<=1000000)
		//tab[R]++;
	}
	
	while(PQ.size())
	{
		cout<<PQ.top().second<<": "<<PQ.top().first<<"\n";
		PQ.pop();
	}
	
	/*
	for(int i=1; i<=1000; i++)
	{
		while(tab[i]--)
		{
			cout<<i<<" "<<i-pri<<"\n";
			pri=i;
		}
	}
	*/
}
