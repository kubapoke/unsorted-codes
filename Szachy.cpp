#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a=0, b=0, c=0, d=0;
	char f;
	
	bool czar=false;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		if(n%2==0)
		{
			if(czar==false)
			czar=true;
			else
			czar=false;
		}
		
		
		for(int j=0; j<n; j++)
		{
			cin>>f;
			
			if(f=='X')
			{
				if(czar==false)
				a++;
				else
				b++;
			}
			
			if(czar==false)
			czar=true;
			else
			czar=false;
		}
	}
	
	czar=false;
	
	for(int i=0; i<n; i++)
	{
		if(n%2==0)
		{
			if(czar==false)
			czar=true;
			else
			czar=false;
		}
		
		
		for(int j=0; j<n; j++)
		{
			cin>>f;
			
			if(f=='X')
			{
				if(czar==false)
				c++;
				else
				d++;
			}
			
			if(czar==false)
			czar=true;
			else
			czar=false;
		}
	}
	
	if(a==c&&b==d)
	cout<<"TAK";
	else
	cout<<"NIE";
}
