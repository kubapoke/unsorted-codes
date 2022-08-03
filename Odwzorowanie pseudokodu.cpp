//Jakub Pπczka
//Odwzrorowanie pseudokodu
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;							//wprowadü n, A[1..n]
	cout<<"wprowadz n:\n";
	cin>>n;
	int A[n+1];
	cout<<"wprowadz A[1..n]:\n";
	for(int i=1; i<=n; i++)
	cin>>A[i];

	int B[n+1];						//B[1..n]
	for(int i=1; i<=n; i++)			//dla i od 1 do n
		B[i]=0;							//B[i]=0
		
	for(int i=1; i<=n; i++)			//dla i od 1 do n
		if(A[i]<=n)						//jeúli A[i]<=n
			B[A[i]]++;						//B[A[i]]++
			
	int k=0;						//k=0
	for(int i=1; i<=n; i++)			//dla i od 1 do n
		if(B[i]==0)						//jeúli B[i]==0
			k++;							//k++
	cout<<"k = "<<k;				//zwrÛÊ k
}
