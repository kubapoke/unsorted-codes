#include<iostream>
using namespace std;

int main()
{
	string s;
	int a, k, j;
	char c;

	cin>>s>>k;
	
	int zmi[k];
	
	for(int i=0; i<k; i++)	
	{
		cin>>zmi[i];
	}
	
	for(int i=0; i<s.length(); i++)
	{
		j=i;
		
		while(j>=k)
		j=j-k;
		
		
	
		//else
		//{
			s[i]=s[i]+zmi[j];
			
			if(s[i]>122)
			{
				s[i]=s[i]-26;
			//	c=s[i]+zmi[j]-26;
			//	cout<<c;
			}
			
			c=s[i];
			
			cout<<c;
		//}
		
	}
	
	
	return 0;
}
