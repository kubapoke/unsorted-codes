#include<bits/stdc++.h>
using namespace std;

int S, sum;
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>S;
	
	bool n=true;
	
	while(sum<S)
	{
		if(n==true)
		{
			s.push(9);
			n=false;
			sum+=9;
		}
		else
		{
			s.push(8);
			n=true;
			sum+=8;
		}
	}
	
	if(sum!=S)
	{
		sum-=s.top();
		s.pop();
		int wym=S-sum;
		
		if(s.empty())
		s.push(wym);
		else if(wym!=s.top())
		s.push(wym);
		else
		{
			sum-=s.top();
			s.pop();
			s.push(7);
			sum+=7;
			
			wym=S-sum;
			
			s.push(wym);
		}
	}
	
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}
