#include<bits/stdc++.h>
#include "dlulib.h"
using namespace std;

int n, l, r, l2, r2, p, k, s, w, ob, obm;

int main()
{
	n=daj_n();
	l=sprawdz(1); r=sprawdz(n);
	
	if(n==1) //wyj¹tki, ¿eby potem siê z tym nie babraæ
	{
		odpowiedz(l);
		return 0;	
	}
	if(n==2)
	{
		odpowiedz(max(l,r));
		return 0;
	}
	
	l2=sprawdz(2); r2=sprawdz(n-1);
	
	if(l2<l&&r2<r)
	{
		odpowiedz(max(l,r));
		return 0;
	}
	
	if(l2>l&&r2>r)
	{
		p=1; k=n; s=(p+k)/2;
		
		while(p!=k)
		{
			ob=sprawdz(s);
			obm=sprawdz(s-1);
			w=max(w, ob);
			
			if(obm<=ob)
			p=s; 
			else
			k=s;
			s=(p+k)/2;
		}
		
		odpowiedz(sprawdz(s));
		return 0;
	}
	
	p=1; k=n; s=(p+k)/2;
	while(p!=k)
	{
		ob=sprawdz(s);
		obm=sprawdz(s-1);
		
		if(obm>ob)
		p=s; 
		else
		k=s;
		s=(p+k)/2;
	}
	
	int sr=s;
	
	p=1; k=sr-1; s=(p+k)/2;
		
	while(p!=k)
	{
		ob=sprawdz(s);
		obm=sprawdz(s-1);
		w=max(w, ob);
		
		if(obm<=ob)
		p=s; 
		else
		k=s;
		s=(p+k)/2;
	}
	
	w=max(w,sprawdz(s));
	
	p=sr+1; k=n; s=(p+k)/2;
		
	while(p!=k)
	{
		ob=sprawdz(s);
		obm=sprawdz(s-1);
		w=max(w, ob);
		
		if(obm<=ob)
		p=s; 
		else
		k=s;
		s=(p+k)/2;
	}
	
	w=max(w,sprawdz(s));
	
	odpowiedz(w);
	return 0;
}
