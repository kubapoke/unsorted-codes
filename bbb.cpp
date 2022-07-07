#include<iostream>
using namespace std;

void wordPosition(int n, int k, char result[])
{
    int a=1, c, l=0, j=0, x;
    
    int tab[26];
    
    for(int i=0; i<26; i++)
    tab[i]=1;
    
    for(int i=1; i<n; i++)
    {
        a*=i;
        x=i;
    }
    
    
    
    for(int i=0; i<n; i++)
    {
        c=(k-1)/a;
        
        
        while(l!=c)
        {
            if(tab[j]==1)
            l++;
            
            j++;
        }
        
        tab[l]=0;
        
        result[i]=j+65;
        
        a/=x;
        x--;
        
        l=0; j=0;
    }
    
    
}


int main()
{
	wordPosition(3, 4, char result[]);
	return 0;
}
