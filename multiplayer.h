#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void ask();

class A
{
	public:
	A(string a[10], string n1, string n2)
	{
		players(a,n1,n2);
	}
	
	private:	
	void display(string a[10])
	{	
		cout<<"\t|"<<a[1]<<"|"<<a[2]<<"|"<<a[3]<<"|\n";
		cout<<"\t|"<<a[4]<<"|"<<a[5]<<"|"<<a[6]<<"|"<<endl;
		cout<<"\t|"<<a[7]<<"|"<<a[8]<<"|"<<a[9]<<"|"<<endl;
	}

	void restart(string a[10],string p1,string p2)
	{
		for(int i=1;i<=9;i++)
		{
			a[i]={" "};
		}
	
		player1(a,p1,p2);	
	
	}

	void again(string a[10],string p1,string p2)
	{	
		string t;

		cout<<"If you want to try again give 't' or you want to exit give 'e' or you want to go to main menu give 'm'.\n";
    	cin>>t;
    	    
		if(t=="t"||t=="T")
		{
			cout<<endl;
			restart(a,p1,p2);
		}
		
		else if(t=="m"||t=="M")
		{
			cout<<"\n\nTell ";
			ask();
		}
	
		else if(t=="e"||t=="E")
		{exit(0);}
		
		
		
		else
		{
			cout<<"\nGive only 't' or 'e'.\n";again(a,p1,p2);
		}
	
		exit(0);
	}

	void check(string w,string p,string a[10],string p1,string p2,string w2)
	{	int times=0;

		if(a[1]==w && a[5]==w && a[9]==w)
		{display(a);
		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}
	
		else if(a[3]==w && a[5]==w && a[7]==w)
		{display(a);
		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}
    
		for(int out=1;out<=9;out++)
    	{
    		if(out==1)
			{
				if(a[out]==w && a[out+1]==w && a[out+2]==w)
				{display(a);
	    		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}
    
	        	else if(a[out]==w && a[out+3]==w && a[out+6]==w)
				{display(a);
	    		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}
			}
        
        	else if(out==4)
        	{
				if(a[out]==w && a[out+1]==w && a[out+2]==w)
				{display(a);
	    		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}
			}
		
			else if(out==7)
			{
				if(a[out]==w && a[out+1]==w && a[out+2]==w)
				{display(a);
	    		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}
			}
		        
        	else if(out==2)
        	{
				if(a[out]==w && a[out+3]==w && a[out+6]==w)
				{display(a);
	    		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}
			}
		
			else if(out==3)
			{
				if(a[out]==w && a[out+3]==w && a[out+6]==w)
				{display(a);
	    		cout<<"\nYeah, "<<p<<" is won the game.\n";again(a,p1,p2);}	
			}
		}
	
		for(int index=1;index<=9;index++)															
		{	    
			if(a[index]==w || a[index]==w2)
			{times++;}
		
			if(times==9)
			{display(a);
			cout<<"\nThe game is tie "<<p1<<" and "<<p2<<" and also well played.\n"<<endl;again(a,p1,p2);}
		}
	}

	void player1(string a[10],string p1,string p2)
	{	
		int box;
		display(a);
		cout<<endl<<p1<<", In which box you want to place 'X' ??\n";
		cin>>box;

		if(box<=9 && box>=1)
		{
    		if(a[box]==" ")
			{a[box]="X";cout<<endl;check("X",p1,a,p1,p2,"O");player2(a,p1,p2);}
			else
			{cout<<"\nHey "<<p1<<" that box is full try another box.\n\n";player1(a,p1,p2);}
		}

		else
		cout<<"\nGive a valid box (1,2,3,4,5,6,7,8,9).\n";player1(a,p1,p2);
	}

	void player2(string a[10],string p1,string p2)
	{	
		int box;
		display(a);
	
		cout<<endl<<p2<<", In which box you want to place 'O' ??\n";
		cin>>box;
	
		if(box<=9 && box>=1)
		{
    		if(a[box]==" ")
			{a[box]="O";cout<<endl;check("O",p2,a,p1,p2,"X");player1(a,p1,p2);}
			else
			{cout<<"\nHey "<<p2<<" that box is full try another box.\n\n";player2(a,p1,p2);}
		}

		else
		{cout<<"\nGive a valid box (1,2,3,4,5,6,7,8,9).\n";player2(a,p1,p2);}
	}

	void players(string a[10],string n1,string n2)
	{
		string p1,p2;
	
		int y;
		srand(time(0));
		y=rand()%(10-1+1)+1;
		cout<<endl<<"And the number is:-\n\n\t\t' "<<y<<" '"<<endl;
	
		if(y%2==0)
		{p1=n1;p2=n2;
		cout<<"\nHey hey, "<<p1<<" was won the toss so he is prefer X.\n"<<"\nAnd the game start now:\n\n";player1(a,p1,p2);}
	
		else
		{p1=n2;p2=n1;
		cout<<"\nHey hey, "<<p1<<" was won the toss so he is prefer X.\n"<<"\nAnd the game start now:\n\n";player1(a,p1,p2);}
	}
};

int multiplayer()
{
	cout<<"\n\t\t*** Multiplayer Mode ***"<<"\n";	
	cout<<"\nThere is a toss to decide who is going to chosse X,\n\nIf it is even number first player is X and if it is odd number second player is X,\n";
	cout<<"if you don't understand this leave it you will understand later.\n\n";

	string a[10]={""," "," "," "," "," "," "," "," "," "};
	string n1,n2;

	cout<<"What is the name of player one??\n";
	cin>>n1;

	cout<<"\nand what is the name of player two??\n";
	cin>>n2;
	
	A a5(a,n1,n2);

return 0;}
