#include<bits/stdc++.h>
using namespace std;

long long n, d;
vector<long long> poprzedni, obecny, checker, checked;

long long ansforpos(int x)
{
	if(x<0 || x>(int)checked.size()-(int)checker.size())
	return 1e18;
	
	long long odp=0;
	
	for(int i=0; i<checker.size(); i++)
	odp+=abs(checker[i]-checked[i+x]);
	
	return odp;
}

void get_answer()
{
	int p=0, k=((int)checked.size()-(int)checker.size()), s;
	s=(p+k)/2;
	
	while(69)
	{	
		long long a=ansforpos(s-1), b=ansforpos(s), c=ansforpos(s+1);
		
		if(a>=b && c>=b)
		{
			cout<<b<<"\n";
			return;
		}
		
		if(a<b)
		{
			k=s-1;
		}
		else if(c<b)
		{
			p=s+1;
		}
		
		s=(p+k)/2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>d;
	
	for(int j=0; j<n; j++)
	{
		int s;
		cin>>s;
		
		checker.clear(); checked.clear();
		
		poprzedni=obecny;

		obecny.clear();
		for(int i=0; i<s; i++)
		{
			int p;
			cin>>p;
			obecny.push_back(p);
		}
		
		if(poprzedni.size()>=obecny.size())
		{
			for(int i=0; i<s; i++)
			checked.push_back(0);
			for(int i=0; i<obecny.size(); i++)
			checked.push_back(obecny[i]);
			for(int i=0; i<s; i++)
			checked.push_back(d);
			
			checker=poprzedni;
		}
		else
		{
			for(int i=0; i<s; i++)
			checked.push_back(0);
			for(int i=0; i<poprzedni.size(); i++)
			checked.push_back(poprzedni[i]);
			for(int i=0; i<s; i++)
			checked.push_back(d);
			
			checker=obecny;
		}
		
		if(j)
		{
			get_answer();
		}
	}
}
