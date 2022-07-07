#include<iostream>
using namespace std;

int main()
{
	int k, w=0, z;
	string a;
	string s;
	bool czy=true;
	
	cin>>a>>k;
	
	for(int i=0; i<k; i++)
	{
		cin>>s;
		z=s.length()-1;
		
		if(a.length()==s.length())
		{
			for(int j=0; j<s.length(); j++)
			{
				if(a[j]!=s[z])
				czy=false;
				
				z--;
			}
		}
		else
		czy=false;
		
		if(czy==true)
		w++;
		
		czy=true;
		
	}
	
	cout<<w;
	
	return 0;
}
