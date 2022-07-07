#include<bits/stdc++.h>
#define mod 1000000007
#define p 31

#define mod2 1000696969
#define p2 43
 
using namespace std;

string s; 
long long pN[3005], hasz[3005], pN2[3005], hasz2[3005];
set<pair<long long, long long>> hsz;

void init() 
{
	pN[0]=1;
	
	for(int i=1; i<=s.size(); i++)
	pN[i]=(pN[i-1]*p)%mod;
	
	for(int i=s.size(); i>0; i--)
	hasz[i]=(s[i-1]*pN[1]+hasz[i+1]*pN[1])%mod;
}

long long get_hash(int pos, int len) 
{
	long long w;
	w=(hasz[pos]-hasz[pos+len]*pN[len])%mod;
	if(w<0)
	w+=mod;
	
	return w;
}

void init2() 
{
	pN2[0]=1;
	
	for(int i=1; i<=s.size(); i++)
	pN2[i]=(pN2[i-1]*p2)%mod2;
	
	for(int i=s.size(); i>0; i--)
	hasz2[i]=(s[i-1]*pN2[1]+hasz2[i+1]*pN2[1])%mod2;
}

long long get_hash2(int pos, int len) 
{
	long long w;
	w=(hasz2[pos]-hasz2[pos+len]*pN2[len])%mod2;
	if(w<0)
	w+=mod2;
	
	return w;
}

int main()
{
	cin>>s;
	
	init();
	init2();
	
	for(int i=1; i<=s.size(); i++)
	for(int j=1; i+j-1<=s.size(); j++)
	hsz.insert({get_hash(i,j),get_hash2(i,j)});
	
	cout<<hsz.size();
}
