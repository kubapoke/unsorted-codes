#include<bits/stdc++.h>
using namespace std;

//5
//1 3 4 9 11
//10

int main()
{
	set<int> test;
	set<int>::iterator it1, it2;
	
	int n, a, b;
	
	cin>>n;
	
	while(n--)
	{
		cin>>a;
		test.insert(a);
	}
	
	cin>>n;
	
	while(n--)
	{
		cin>>a;
		it1=test.lower_bound(a); it2=test.upper_bound(a);
		
		cout<<*it1<<" "<<*it2<<" "<<distance(it1,it2)<<"\n";
	}
}
