#include<iostream>
#include"multiplayer.h"
#include"easy.h"
#include"normal.h"
#include"hard.h"
using namespace std;

void singleplayer()
{
	string op1;
	cout<<"\nIn single player mode there are three option:\n\na) Easy\nb) Normal\nc) Hard\n\nWhich mode you want to play?\nGive 'a' or 'b' or 'c',\n";
	cin>>op1;
	
	if(op1=="a"||op1=="A") 
	{
		easy();
	}
	
	else if(op1=="b"||op1=="B")
	{
		normal();
	}
	
	else if(op1=="c"||op1=="C")
	{
		hard();		
	}
}

void ask()
{
	string op;
	cout<<"me, which mode you want to play.\n\na) Multiplayer mode\nb) Singleplayer mode\n\nGive 'a' or 'b',\n";
	cin>>op;
	
	if(op=="a"||op=="A")
	{
		multiplayer();
	}
	
	else if(op=="b"||op=="B")
	{
		singleplayer();	
	}
	
	else
	{
		cout<<"\nGive only 'a' or 'b'.\n\n";
		ask();
	}
}

int main()
{
	cout<<"\n\n\t\t*** Tic Tac Toe ***"<<"\n";
	cout<<"\t\t\t\t-Done by K.S.Mirthun.\n\n";
	cout<<"Hi,\nI make a game called tic tac toe (X and O) and i think you would like it.\n\n";
	cout<<"And Rules are simple:\n\tyou want to give the number of the empty box to place your key(X or O).\n\t";
	cout<<"For example,\n\n\tIf you are X and you give the box number 5\n\tIt will out like this:\n\n"; 
	cout<<"\t\t| | | |\n\t\t| |X| |\n\t\t| | | |\n\nAnd tell ";
	ask();
	
	
	
	
	
	return 0;
}
