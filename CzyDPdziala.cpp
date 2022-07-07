#include<bits/stdc++.h>
using namespace std;

int ct=0;

int main()
{
	for(int a=1; a<=9; a++)
	for(int b=1; b<=9; b++)
	{
		if(a*b==30)
		{
			cout<<a<<" "<<b<<"\n";
			ct++;
		}	
	}
	
	for(int a=1; a<=9; a++)
	for(int b=1; b<=9; b++)
	for(int c=1; c<=9; c++)
	{
		if(a*b*c==30)
		{
			cout<<a<<" "<<b<<" "<<c<<"\n";
			ct++;
		}	
	}
	
	for(int a=1; a<=9; a++)
	for(int b=1; b<=9; b++)
	for(int c=1; c<=9; c++)
	for(int d=1; d<=9; d++)
	{
		if(a*b*c*d==30)
		{
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
			ct++;
		}	
	}
	
	cout<<ct;
}
