#include<bits/stdc++.h>
using namespace std;

int n, a1, a2, b1, b2, c1, c2, d1, d2;
set<int>::iterator it1;
set<int>::reverse_iterator it2;

int main()
{
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a1>>a2>>b1>>b2>>c1>>c2>>d1>>d2;
		set<int> s1, s2;
		
		s1.insert(a1), s1.insert(b1), s1.insert(c1), s1.insert(d1);
		s2.insert(a2), s2.insert(b2), s2.insert(c2), s2.insert(d2);
		
		if(s1.size()!=2||s2.size()!=2)
		{
			cout<<"NIE\n";
			continue;
		}
		
		it1=s1.begin(); it2=s1.rbegin();
		int sum=abs(*it1-*it2);
		
		it1=s2.begin(); it2=s2.rbegin();
		
		if(sum!=abs(*it1-*it2))
		{
			cout<<"NIE\n";
			continue;
		}
		
		cout<<"TAK\n";
	}
}
