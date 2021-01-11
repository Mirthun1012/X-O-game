#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void ask();

class C
{
	public:
	C(string key, string compkey, string a[10], string re, string name, int p)
	{
		if(key=="X")
		{	
			player(key,a,compkey,name,re,p);
		}
	
		else
		{
			computer(compkey,a,key,name,re,p);
		}
	}	
	
	
	
	private:
	void display(string a[10])
	{cout<<"\t|"<<a[1]<<"|"<<a[2]<<"|"<<a[3]<<"|\n";
	cout<<"\t|"<<a[4]<<"|"<<a[5]<<"|"<<a[6]<<"|\n";
	cout<<"\t|"<<a[7]<<"|"<<a[8]<<"|"<<a[9]<<"|\n";}

	void restart(string a[10],string compkey,string key,string name,string re,int p)
	{
		for(int i=1;i<=9;i++)
		{
			a[i]={" "};
		}
		
		if(re=="1")
		{
			player(key,a,compkey,name,re,p);
		}
			
		else 
		{
			computer(compkey,a,key,name,re,p);
		}	
		
	}		

	void again(string a[10],string compkey,string key,string name,string re,int p)
	{	
		string t;

		cout<<"If you want to try again give 't' or you want to exit give 'e' or you want to go to main menu give 'm'.\n";
	    cin>>t;
    
		if(t=="t"||t=="T")
		{
			restart(a,compkey,key,name,re,p);
		}
	
		else if(t=="e"||t=="E")
		{exit(0);}
	
		else if(t=="m"||t=="M")
		{
			cout<<"\n\nTell ";
			ask();
		}
	
		else
		{
			cout<<"\nGive only 't' or 'e'.\n";again(a,compkey,key,name,re,p);
		}
	
	exit(0);
}

int check(string a[10],string w,string compkey,string key,string name,string re,int p)
{	int times=0;

	if(a[1]==w && a[5]==w && a[9]==w)
	{display(a);
	return 1;}
	
	else if(a[3]==w && a[5]==w && a[7]==w)
	{display(a);
	return 1;}
    
	for(int out=1;out<=9;out++)
    {
    	
		
		if(out==1)
		{
			if(a[out]==w && a[out+1]==w && a[out+2]==w)
			{display(a);
	    	return 1;}
        
	        else if(a[out]==w && a[out+3]==w && a[out+6]==w)
			{display(a);
	    	return 1;}
		}
        
        else if(out==4)
        {
			if(a[out]==w && a[out+1]==w && a[out+2]==w)
			{display(a);
	    	return 1;}
		}
		
		else if(out==7)
		{
			if(a[out]==w && a[out+1]==w && a[out+2]==w)
			{display(a);
	    	return 1;}
		}
		        
        else if(out==2)
        {
			if(a[out]==w && a[out+3]==w && a[out+6]==w)
			{display(a);
	    	return 1;}
		}
		
		else if(out==3)
		{
			if(a[out]==w && a[out+3]==w && a[out+6]==w)
			{display(a);
	    	return 1;}	
		}
	}
	
	for(int index=1;index<=9;index++)															
	{	    
		if(a[index]==compkey || a[index]==key)
		{times++;}
		
		if(times==9)
		{return 2;}
	}
	
return 0;}

void player(string key,string a[10],string compkey,string name,string re,int p)
{
	int box;
	display(a);
	cout<<"\nIn which box you want to place '"<<key<<"'.\n";
	cin>>box;
	
	if(box>=1 && box<=9)
	{
		if(a[box]==" ")
		{
			a[box]=key;
			if(check(a,key,compkey,key,name,re,p)==1)
			{
				cout<<"\nYeah "<<name<<", you are won the game and\n";
				again(a,compkey,key,name,re,p);
			}
			
			else if(check(a,key,compkey,key,name,re,p)==2)
			{
				display(a);
				cout<<"\nThe game is tie "<<name<<" but you are well played.\n"<<endl;
				again(a,compkey,key,name,re,p);				
			}
			
			else
			{
				computer(compkey,a,key,name,re,p);
			}
			
		}
		
		else
		{
			cout<<"\nThat box is full try another box "<<name<<".\n\n";
			player(key,a,compkey,name,re,p);
		}
	}
	
	else
	{
		cout<<"\nGive a valid box(1,2,3,4,5,6,7,8,9).\n\n";
		player(key,a,compkey,name,re,p);
	}
}

int senses(string wkey,string a[10],string compkey,string key,string name,string re,int p)
{
	int y=0,y1=0;
		
	//for 1st row
	for(int z1=1;z1<=3;z1++)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
		
		return 1;
	}
	
	y=0,y1=0;
	
	//for 2nd row
	for(int z1=4;z1<=6;z1++)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
		
		return 1;
	}

	y=0,y1=0;
	
	//for 3rd row
	for(int z1=7;z1<=9;z1++)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
		
		return 1;
	}

	y=0,y1=0;
	
	//for 1st column
	for(int z1=1;z1<=7;z1+=3)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
		
		return 1;
	}
	
	y=0,y1=0;
	
	//for 2nd column
	for(int z1=2;z1<=8;z1+=3)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
	
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
		
		return 1;
	}
	
	y=0,y1=0;
	
	//for 3rd column
	for(int z1=3;z1<=9;z1+=3)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
		
		return 1;
	}
	
	y=0,y1=0;
	
	//for 1st dignal
	for(int z1=1;z1<=9;z1+=4)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
			
		return 1;
	}
	
	y=0,y1=0;
	
	//for 2nd dignol
	for(int z1=3;z1<=7;z1+=2)
	{	
		if(a[z1]==wkey)
		{																
			y++;
		}
		
		else if(a[z1]==" ")
		{
			y--;
			y1=z1;
		}
		
		else
		{
			y+=2;
		}
	}
	
	if(y==1)
	{
	
		a[y1]=compkey;
		if(check(a,compkey,compkey,key,name,re,p)==1)
		{
			cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
			again(a,compkey,key,name,re,p);
		}
				
		return 1;
	}	
		
return 0;}

void computer(string compkey,string a[10],string key,string name,string re,int p)
{	
	
	if(p==0)
	{
		if(senses(compkey,a,compkey,key,name,re,p)==1)
		{
			p++;			
			player(key,a,compkey,name,re,p);
		}
		
		else if(senses(key,a,compkey,key,name,re,p)==1)
		{
			p++;
			player(key,a,compkey,name,re,p);
		}
	
		else
		{
			for(int z=1;z<=9;)
			{
				if(a[z]==" ")
				{
					a[z]=compkey;
		
					if(check(a,compkey,compkey,key,name,re,p)==1)
					{
						cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
						again(a,compkey,key,name,re,p);
					}
					
					else if(check(a,compkey,compkey,key,name,re,p)==2)
					{
						display(a);
						cout<<"\nThe game is tie "<<name<<" but you are well played.\n"<<endl;
						again(a,compkey,key,name,re,p);
					}
	
					else
					{
						player(key,a,compkey,name,re,p);
					}
			
					z=10;
				}
		
				else
				{
					z++;
				}
			}
		}
	}
	
	else
	{
		for(int z=1;z<=9;)
		{
			if(a[z]==" ")
			{
				a[z]=compkey;
	
				if(check(a,compkey,compkey,key,name,re,p)==1)
				{
					cout<<"\nOhhh "<<name<<", you are lost in the game and\n";
					again(a,compkey,key,name,re,p);
				}
				
				else if(check(a,compkey,compkey,key,name,re,p)==2)
				{
					display(a);
					cout<<"\nThe game is tie "<<name<<" but you are well played.\n"<<endl;
					again(a,compkey,key,name,re,p);
				}
	
				else
				{
					player(key,a,compkey,name,re,p);
				}
			
				z=10;
			}
		
			else
			{
				z++;
			}
		}
	}
}
	
};



int normal()
{	
	string a[10]={""," "," "," "," "," "," "," "," "," "};
	string name,re;
	string key,compkey;
	int p=0;
	
	cout<<"\n\t\t*** Singleplayer Mode - Normal ***"<<"\n";
	cout<<"\nWhat is your name?\n";
	cin>>name;
	
	int y=0;
	srand(time(0));
	y=rand()%(10-1+1)+1;
	
	cout<<endl<<"And the number is:-\n\n\t\t' "<<y<<" '"<<endl;
	
	if(y%2==0)
	{	
		re="1";
		key="X";
		compkey="O";
		cout<<name<<" you are won in the toss so your key is 'X'.\n\n";
	}
	
	else
	{	
		re="2";
		key="O";
		compkey="X";
		cout<<name<<" you are lost in the toss so your key is 'O'.\n\n";
	}
	
	cout<<"And the game start now:\n\n";
	
	C c5(key,compkey,a,re,name,p);
	
	
	return 0;
}
