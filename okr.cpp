#include<bits/stdc++.h>
using namespace std;

int N, a;
list<char> wyraz;
list<char>::iterator it1, it2;
char x;

bool check(int l)
{
	it1=wyraz.begin(); it2=wyraz.begin();
	for(int i=0; i<l; i++)
	it2++;
	
	for(it1; it2!=wyraz.end(); ++it1, ++it2)
	{
		if(*it1!=*it2)
		return false;
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	
	for(int i=1; i<=N; i++)
	{
		cin>>a>>x;
		if(a==1)
		wyraz.push_front(x);
		else if(a==2)
		wyraz.push_back(x);
		
		if(i==1)
		cout<<"1\n";
		
		for(int i=1; i<wyraz.size(); i++)
		{
			if(check(i)==true)
			{
				int w=wyraz.size()/i;
				if(wyraz.size()%i!=0)
				w++;
				cout<<w<<"\n";
				break;
			}
			
			if(i==wyraz.size()-1)
			cout<<"1\n";
		}
	}
	
}
