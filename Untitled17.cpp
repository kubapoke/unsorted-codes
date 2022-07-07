#include<iostream>
using namespace std;

int main()
{
	int k, s=0, sumA=0, sumB=0;
	string a;
	
	cin>>k;
	
	for(int i=0; i<k; i++)
	{
		cin>>a;
		
		for(int i=0; i<a.length(); i++)
		{
			if(a[i]=='a' || a[i]=='A')
			sumA++;
			else if(a[i]=='b' || a[i]=='B')
			sumB++;
		}
		
		if(sumA==sumB)
		s++;
		
		sumA=0; sumB=0;
	}
	
	cout<<s;
	
	return 0;
}
