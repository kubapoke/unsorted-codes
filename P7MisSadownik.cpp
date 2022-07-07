#include<bits/stdc++.h>
using namespace std;

string keys[10]={"00111011100", "01011011010", "01101010110", "01110001110", "10011011001", "10101010101", "10110001101", "11001010011", "11010001011", "11100000111"};
int val[8][13];

int main()
{
	for(int i=0; i<10; i++)
	{
		string klucz=keys[i];
		
		int h=7;
		
		for(int d=1; d<=12; d++)
		{
			val[h][d]++;
			
			if(klucz[d-1] == '1')
			h--;
		}
	}	
	
	int a,b;
	
	cin>>a>>b;
	
	cout<<val[a][b];
}
