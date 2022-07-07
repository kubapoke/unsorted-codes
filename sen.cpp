#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string sen;
	
	cin>>sen;
	
	register int c=sen.length()-1, s=0, l=0, z=0;
	
	for(int i=c; i>=0; i--)
	{	
		if(sen[i]!='0')
		break;
		z++;
	}
	
	
	for(int i=0; i<=c-z; i++)
	{
		for(int j=i; j<=c; j++)
		{
			if(sen[j]=='1')
			l++;
			
			if(l==j-i+1)
			s++;
			
			if(l>j-i+1)	
			break;		
		
			l*=2;	
		}
		
		l=0;
	}
	cout<<s;
	
	return 0;
}
