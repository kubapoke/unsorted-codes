#include<iostream>
using namespace std;

int main()
{
	int k, w=0;
	string s;
	cin>>k;
	bool idk=true;
	
	for(int i=0; i<k; i++)
	{
		cin>>s;
		
		for(int j=0; j<s.length()-1; j++)
		{
			if(s[j]>s[j+1])
			idk=false;
		}
		
		if(idk==true)
		w++;
		
		idk=true;	
	}
	
	cout<<w;
	
	return 0;
}
