#include <bits/stdc++.h> //z jakiegoœ powodu nie dzia³a na internetowym kompilatorze :(
using namespace std;

vector<string> v;

int main() 
{
   	for(int i=1; i<=999; i++)
    v.push_back(to_string(i));
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++)
    cout<<i+1<<": "<<v[i]<<"\n";
	
	return 0;
}
