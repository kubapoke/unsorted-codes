#include<bits/stdc++.h>
using namespace std;

int n, c, curr;
vector<int> A;

int main()
{
	cin>>n>>c;
	
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	
	for(int i=0; i<c; i++)
	{
		curr=A[0];
		
		for(int j=1; j<n; j++)
		{
			curr^=A[j];
			A[j]=curr;
		}
		
		for(int j=0; j<n; j++)
		cout<<A[j]<<" ";
		cout<<"\n";
	}
	
}
