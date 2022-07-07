#include<bits/stdc++.h>
using namespace std;

int nal(string &s)
{
	if(s=="A")
	return 0;
	if(s=="A#")
	return 1;
	if(s=="B")
	return 2;
	if(s=="C")
	return 3;
	if(s=="C#")
	return 4;
	if(s=="D")
	return 5;
	if(s=="D#")
	return 6;
	if(s=="E")
	return 7;
	if(s=="F")
	return 8;
	if(s=="F#")
	return 9;
	if(s=="G")
	return 10;
	if(s=="G#")
	return 11;
}

string s1,s2,s3;
int w1, w2, w3;

int main()
{
	cin>>s1>>s2>>s3;
	
	w1=nal(s1); w2=nal(s2); w3=nal(s3);
	
	if(w1>w2)
	{
		swap(w1,w2);
		swap(s1,s2);
	}
	if(w2>w3)
	{
		swap(w2,w3);
		swap(s2,s3);
	}
	if(w1>w2)
	{
		swap(w1,w2);
		swap(s1,s2);
	}
	if(w2>w3)
	{
		swap(w2,w3);
		swap(s2,s3);
	}
	
	if((w1+4)%12==w2&&(w1+7)%12==w3)
	{
		cout<<"Akord "<<s1;
	}
	else if((w2+4)%12==w3&&(w2+7)%12==w1)
	{
		cout<<"Akord "<<s2;
	}
	else if((w3+4)%12==w1&&(w3+7)%12==w2)
	{
		cout<<"Akord "<<s3;
	}
	else if((w1+3)%12==w2&&(w1+7)%12==w3)
	{
		cout<<"Akord "<<s1<<"m";
	}
	else if((w2+3)%12==w3&&(w2+7)%12==w1)
	{
		cout<<"Akord "<<s2<<"m";
	}
	else if((w3+3)%12==w1&&(w3+7)%12==w2)
	{
		cout<<"Akord "<<s3<<"m";
	}
	else cout<<"Brak";
}
