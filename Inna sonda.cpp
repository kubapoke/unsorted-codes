#include<iostream>
using namespace std;

int main()
{
	string s;
	int k, j;
	
	cin>>s>>k;
	
	int tab[k];
	
	for(int i=0; i<k; i++)
	{
		cin>>tab[i];
	}
	
	cout<<s<<"^"<<k;
	
	
	
	return 0;
}
