#include<bits/stdc++.h>
using namespace std;

long long A, B, C, w;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>A>>B>>C;
	
	while(A*B<=C)
	{
		if((A*(B+3)>C&&(A+1)*(B+2)>C)||((A+2)*(B+1)>C&&(A+1)*(B+2)>C)||((A+3)*B>C&&(A+2)*(B+1)>C))
		{
			w+=3;
			A+=3;
			B+=3;
		}
		else if(A*(B+1)<=C&&B*(A+1)<=C)
		{
			if(A<=B)
			A++;
			else
			B++;
			w++;
		}
		else if(A*(B+1)>C)
		{
			B++;
			w++;
		}
		else if(B*(A+1)>C)
		{
			A++;
			w++;
		}
		
	}
	
	if(w%2==1)
	cout<<"Tomek";
	else
	cout<<"Michal";
}
