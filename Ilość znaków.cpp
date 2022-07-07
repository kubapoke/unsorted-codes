#include<iostream>
using namespace std;

//wystêpuje tylko cykl

int main()
{
	int n, parz=0, nparz=0;
	string s;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>s;
		
		if(s.length()%2==0)
		{
			parz++;
		}
		else
		{
			nparz++;
		}
	}
	
	cout<<parz<<" "<<nparz;
	
	return 0;
}
