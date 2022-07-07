#include<bits/stdc++.h>
using namespace std;
//4 -1 1 2 2 3 2 5 1
int n, w;
long long p, r, currkon=-1e18;
stack<long long> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	currkon--;
	w=n;
	
	for(int i=0; i<n; i++)
	{
		cin>>p>>r;
		if(currkon>=p)
		{
			w--;
			currkon=max(currkon,p+r);
			continue;
		}
		currkon=max(currkon,p+r);
		//cout<<currkon<<endl;
		
		while(1)
		{
			if(s.empty()) break;
			if(p-r>s.top()) break;
			
			w--; s.pop();
		}
		
		s.push(p);
	}
	
	cout<<w;
	
}
