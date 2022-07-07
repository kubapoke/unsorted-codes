#include<iostream>
using namespace std;

int main()
{
	int a;
	bool czy=false;
	
	cin>>a;
	
	while(1)
	{
		a++;
		
		for(int i=2; i*i<=a; i++)
		{
			if(a%i==0)
			{
				czy=true;
				break;
			}
		}
		
		if(czy==false)
		break;
		
		czy=false;
	}
	
	cout<<a;
	
}
