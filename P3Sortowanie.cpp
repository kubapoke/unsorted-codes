//Program P-3
#include <bits/stdc++.h> 
using namespace std;

int N, a;
vector<int> v;

bool comp(int a, int b)
{
	while(a && b)
	{
		int x=a%10;
		int y=b%10;
		
		if(x!=y)
		return(x<y);
		
		a/=10;
		b/=10;
	}
	
	return(a<b);
}

int main() 
{
    cin>>N;
    
    while(N--)
    {
        cin>>a;
        v.push_back(a);
    }
    
    sort(v.begin(),v.end(),comp);
    
    for(int i=0; i<v.size(); i++)
    {
    	if(i)
    	if(v[i]%100!=v[i-1]%100)
    	cout<<"\n";
    	cout<<v[i]<<"\n";
	}
	
	return 0;
}
