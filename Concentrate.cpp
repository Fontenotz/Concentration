#include <iostream.h>
#include <stdlib.h>
#include <time.h>

char Back[6][5]=
	{
		' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' '
	};

int Front[6][5]=
	{
		1,2,3,4,5,
		6,7,8,9,10,
		11,12,13,14,15,
		16,17,18,19,20,
		21,22,23,24,25,
		26,27,28,29,30
	};

char Third[6][5]=
	{
		'*','*','*','*','*',
		'*','*','*','*','*',
		'*','*','*','*','*',
		'*','*','*','*','*',
		'*','*','*','*','*',
		'*','*','*','*','*'
	};

class Concentrate
{
private:
	int matches;
	int guess[2];
public:
	void Intro();
	void Placeletters();
	void PlayeronePlay();
	void PlayertwoPlay();
	void Showboard_Front();
	void Showboard_Third();
	void Blankboard_Third();
	void Outro();
	void Wait();
}player1,player2;


void Concentrate::Intro()
{
	srand(time(0));
	cout<<" ________________________________________________________ "<<endl;
	cout<<"| Welcome to Concentration                               |"<<endl;
	cout<<"|--------------------------------------------------------|"<<endl;
	cout<<"|  * Pick numbered tiles when promted                    |"<<endl;
	cout<<"|  * Please, do not chose numbers 'zeroed' out           |"<<endl;
	cout<<"|  * Slashes represent a matched letter                  |"<<endl;
	cout<<"|  * There are 15 matches to be made                     |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"| Good luck                                              |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	
}



void Concentrate::Placeletters()
{
	int a=0;
	char letters[15]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};


	while (a<15)
	{

		int place_x=rand()%5;
		int place_y=rand()%6;
		int place_xx=rand()%5;
		int place_yy=rand()%6;

		if (Back[place_y][place_x]==' ' && Back[place_yy][place_xx]==' ' && place_y!=place_yy && place_x!=place_xx)
		{
			Back[place_y][place_x]=letters[a];
			Back[place_yy][place_xx]=letters[a];
			a++;
		}
	}
}


void Concentrate::PlayeronePlay()
{
	player1.guess[0]=0;
	player1.guess[1]=0;

	cout<<"Player One -- Score: "<<player1.matches<<endl;
	Showboard_Front();

	cout<<"Enter guess one ";
	cin>>player1.guess[0];
	cout<<"Enter guess two ";
	cin>>player1.guess[1];



	if (player1.guess[1]==player1.guess[0])
	{
		cout<<"Please choose different spaces"<<endl;
		system("pause");
		system("cls");
		PlayeronePlay();
	}
	else
	{

	for (int x=0;x<2;x++)
	{
		if (player1.guess[x]==1)
			Third[0][0]=Back[0][0];
		else if (player1.guess[x]==2)
			Third[0][1]=Back[0][1];
		else if (player1.guess[x]==3)
			Third[0][2]=Back[0][2];
		else if (player1.guess[x]==4)
			Third[0][3]=Back[0][3];
		else if (player1.guess[x]==5)
			Third[0][4]=Back[0][4];
		else if (player1.guess[x]==6)
			Third[1][0]=Back[1][0];
		else if (player1.guess[x]==7)
			Third[1][1]=Back[1][1];
		else if (player1.guess[x]==8)
			Third[1][2]=Back[1][2];
		else if (player1.guess[x]==9)
			Third[1][3]=Back[1][3];
		else if (player1.guess[x]==10)
			Third[1][4]=Back[1][4];
		else if (player1.guess[x]==11)
			Third[2][0]=Back[2][0];
		else if (player1.guess[x]==12)
			Third[2][1]=Back[2][1];
		else if (player1.guess[x]==13)
			Third[2][2]=Back[2][2];
		else if (player1.guess[x]==14)
			Third[2][3]=Back[2][3];
		else if (player1.guess[x]==15)
			Third[2][4]=Back[2][4];
		else if (player1.guess[x]==16)
			Third[3][0]=Back[3][0];
		else if (player1.guess[x]==17)
			Third[3][1]=Back[3][1];
		else if (player1.guess[x]==18)
			Third[3][2]=Back[3][2];
		else if (player1.guess[x]==19)
			Third[3][3]=Back[3][3];
		else if (player1.guess[x]==20)
			Third[3][4]=Back[3][4];
		else if (player1.guess[x]==21)
			Third[4][0]=Back[4][0];
		else if (player1.guess[x]==22)
			Third[4][1]=Back[4][1];
		else if (player1.guess[x]==23)
			Third[4][2]=Back[4][2];
		else if (player1.guess[x]==24)
			Third[4][3]=Back[4][3];
		else if (player1.guess[x]==25)
			Third[4][4]=Back[4][4];
		else if (player1.guess[x]==26)
			Third[5][0]=Back[5][0];
		else if (player1.guess[x]==27)
			Third[5][1]=Back[5][1];
		else if (player1.guess[x]==28)
			Third[5][2]=Back[5][2];
		else if (player1.guess[x]==29)
			Third[5][3]=Back[5][3];
		else if (player1.guess[x]==30)
			Third[5][4]=Back[5][4];
		else
		{
			cout<<"Please choose numbers between 1 and 30"<<endl;
			system("pause");
			system("cls");
			PlayeronePlay();
		}
	}

	system("cls");
	Showboard_Third();
	
	for (int w=0;w<6;w++)
	{
		for (int x=0;x<5;x++)
		{
			for (int y=0;y<6;y++)
			{
				for (int z=0;z<5;z++)
				{
					if (Third[w][x]==Third[y][z] && Third[w][x]!='*' && Third[y][z]!='*' && w!=y && x!=z && Third[w][x]!='/')
					{
						cout<<"You have a match"<<endl;
						Third[w][x]='/';
						Third[y][z]='/';
						Back[w][x]='/';
						Back[y][z]='/';
						Front[w][x]=0;
						Front[y][z]=0;
						player1.matches++;
							if (player1.matches>=7  && player1.matches+player2.matches==15)
							{
								Outro();
							}
							else
							{
								system("pause");
								system("cls");
								PlayeronePlay();
							}
					}		
	
					
				}
			}
		}
	}


	}

	system("pause");
	Blankboard_Third();
	system("cls");
	PlayertwoPlay();
}

void Concentrate::PlayertwoPlay()
{
	player2.guess[0]=0;
	player2.guess[1]=0;
	cout<<"Player Two -- Score: "<<player2.matches<<endl;
	Showboard_Front();

	cout<<"Enter guess one ";
	cin>>player2.guess[0];
	cout<<"Enter guess two ";
	cin>>player2.guess[1];


	if (player2.guess[1]==player2.guess[0])
	{
		cout<<"Please choose different spaces"<<endl;
		system("pause");
		system("cls");
		PlayertwoPlay();
	}
	else
	{

	for (int x=0;x<2;x++)
	{
		if (player2.guess[x]==1)
			Third[0][0]=Back[0][0];
		else if (player2.guess[x]==2)
			Third[0][1]=Back[0][1];
		else if (player2.guess[x]==3)
			Third[0][2]=Back[0][2];
		else if (player2.guess[x]==4)
			Third[0][3]=Back[0][3];
		else if (player2.guess[x]==5)
			Third[0][4]=Back[0][4];
		else if (player2.guess[x]==6)
			Third[1][0]=Back[1][0];
		else if (player2.guess[x]==7)
			Third[1][1]=Back[1][1];
		else if (player2.guess[x]==8)
			Third[1][2]=Back[1][2];
		else if (player2.guess[x]==9)
			Third[1][3]=Back[1][3];
		else if (player2.guess[x]==10)
			Third[1][4]=Back[1][4];
		else if (player2.guess[x]==11)
			Third[2][0]=Back[2][0];
		else if (player2.guess[x]==12)
			Third[2][1]=Back[2][1];
		else if (player2.guess[x]==13)
			Third[2][2]=Back[2][2];
		else if (player2.guess[x]==14)
			Third[2][3]=Back[2][3];
		else if (player2.guess[x]==15)
			Third[2][4]=Back[2][4];
		else if (player2.guess[x]==16)
			Third[3][0]=Back[3][0];
		else if (player2.guess[x]==17)
			Third[3][1]=Back[3][1];
		else if (player2.guess[x]==18)
			Third[3][2]=Back[3][2];
		else if (player2.guess[x]==19)
			Third[3][3]=Back[3][3];
		else if (player2.guess[x]==20)
			Third[3][4]=Back[3][4];
		else if (player2.guess[x]==21)
			Third[4][0]=Back[4][0];
		else if (player2.guess[x]==22)
			Third[4][1]=Back[4][1];
		else if (player2.guess[x]==23)
			Third[4][2]=Back[4][2];
		else if (player2.guess[x]==24)
			Third[4][3]=Back[4][3];
		else if (player2.guess[x]==25)
			Third[4][4]=Back[4][4];
		else if (player2.guess[x]==26)
			Third[5][0]=Back[5][0];
		else if (player2.guess[x]==27)
			Third[5][1]=Back[5][1];
		else if (player2.guess[x]==28)
			Third[5][2]=Back[5][2];
		else if (player2.guess[x]==29)
			Third[5][3]=Back[5][3];
		else if (player2.guess[x]==30)
			Third[5][4]=Back[5][4];
		else
		{
			cout<<"Please choose numbers between 1 and 30"<<endl;
			system("pause");
			system("cls");
			PlayertwoPlay();
		}
	}

	system("cls");
	Showboard_Third();
	
	for (int w=0;w<6;w++)
	{
		for (int x=0;x<5;x++)
		{
			for (int y=0;y<6;y++)
			{
				for (int z=0;z<5;z++)
				{
					if (Third[w][x]==Third[y][z] && Third[w][x]!='*' && Third[y][z]!='*' && w!=y && x!=z && Third[w][x]!='/')
					{
						player2.matches++;
						cout<<"You have a match"<<endl;
						Third[w][x]='/';
						Third[y][z]='/';
						Back[w][x]='/';
						Back[y][z]='/';
						Front[w][x]=0;
						Front[y][z]=0;
							if (player2.matches>=7 && player1.matches+player2.matches==15)
							{
								Outro();
							}
							else
							{
								system("pause");
								system("cls");
								PlayertwoPlay();
							}
					}
	
					
				}
			}
		}
	}


	}


		system("pause");
		Blankboard_Third();
		system("cls");
		PlayeronePlay();

}

void Concentrate::Showboard_Front()
{
	for (int a=0;a<2;a++)
	{
		for (int b=0;b<5;b++)
		{
			cout<<Front[a][b]<<"    ";
		}
		cout<<endl;
		cout<<endl;
	}

	for (int c=2;c<6;c++)
	{
		for (int b=0;b<5;b++)
		{
			cout<<Front[c][b]<<"   ";
		}
		cout<<endl;
		cout<<endl;
	}

}


void Concentrate::Showboard_Third()
{
	for (int a=0;a<6;a++)
	{
		for (int b=0;b<5;b++)
		{
			cout<<Third[a][b]<<"     ";
		}
		cout<<endl;
		cout<<endl;
	}

	
}

void Concentrate::Blankboard_Third()
{
	for (int a=0;a<6;a++)
	{
		for (int b=0;b<5;b++)
		{
			if (Third[a][b]!='/')
			{
				Third[a][b]='*';
			}
		}
		cout<<endl;
	}

	
}

void Concentrate::Outro()
{
	system("cls");
	cout<<"Player One Score: "<<player1.matches<<endl;
	cout<<"Player Two Score: "<<player2.matches<<endl;
	if (player1.matches>player2.matches)
		cout<<"PLAYER ONE WINS"<<endl;
	else if (player2.matches>player1.matches)
		cout<<"PlAYER TWO WINS"<<endl;
	else
		cout<<"TIE"<<endl;
}

void Concentrate::Wait()
{
	clock_t endwait;
	endwait=clock()+3*CLK_TCK;
	while (clock()<endwait){}
}

int main()
{
	//srand(time(0));
	Concentrate game;
	game.Intro();
	game.Placeletters();
	game.PlayeronePlay();
	game.Outro();

	return 0;
}