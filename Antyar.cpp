#include<bits/stdc++.h>
using namespace std;

int S, pwr;
int ad[8001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>S;
	
	int curr=1;
	for(int i=1; i<=S; i++)
	{
		curr+=ad[i];
		cout<<curr<<" ";
		
		if(i==pow(2,pwr))
		{
			for(int j=i+1; j<=8000; j+=pow(2,pwr))
			ad[j]=curr;
			
			pwr++;
		}
	}
}
