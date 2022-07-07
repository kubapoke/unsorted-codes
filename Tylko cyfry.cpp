#include<iostream>
using namespace std;

int main()
{
	int k, w=0;
	cin>>k;
	string s;
	bool cyf=true;
	
	for(int i=0; i<k; i++)
	{
		cin>>s;
		for(int j=0; j<s.length(); j++)
		{
			if(s[j]<48 || s[j]>57)
			cyf=false;
		}	
		if(cyf==true)
		w++;
		
		cyf=true;
	}
	
	cout<<w;
	
	return 0;
}
