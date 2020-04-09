#include<iostream>////////////////////////////////////////Libraeies
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
using namespace std;
//*********************************************************Functions
void style();							//for front style
void instruction();       			    //for showing instructions
int position(int x);		 	        //for checking for snake and ladders 
void dice(int);					       //for dice printing
void rules();							//for printing rules
void board(int x,int y);				//for printing number board
void image(int score);					//for image of snake and ladder after dice rolling
void location(int,int);					//for the location of things on screen
//********************************************************Main function
int main (){ 
	string player;
	char mode,select;
	start:
	system("cls");
	style();
	cout<<"Press 1 to Read the Instructions \n";
	cout<<"Press 2 to Select the Game Mode \n";
	cout<<"Press 3 to Quit : ";
	cin>>select;
	system("cls");
	//******************************************************setection mode start
	if(select=='1'){// ********************************************************************for instruction
		style();
		cout<<"INSTRUCTIONS"<<endl;
		cout<<"------------"<<endl;
		instruction();
		 cout<<"Enter Any key To Go Back";
		 getch();
		 goto start;
	}
	else if(select=='2'){//**************************for seiecing game modes
			style();
		cout<<"Enter 1 to Play Single Player Mode:"<<endl;
		cout<<"Enter 2 to Play Double Players Mode:"<<endl;
		cout<<"Enter Any other key to go back:";
		cin>>mode;
		if(mode=='1'){//**************************************************************single user or player start
	    system("cls");
	    style();
		cout<<"Enter Your Name:";
		cin>>player;
		int score=0;
		while(score<=100){
		system("cls");
		style();
		board(score,0);
		rules();
		int dice1=((rand()+time(0))%6)+1;//for random number
	cout<<"\n\n \n\n\n\n\n\n\n\n\n\n\n"<<player<<" your Position is on "<<position(score);
		dice(dice1);
		score=position(score)+dice1;
		image(score);//calling snake or ladder printing funtion
			cout<<endl<<endl<<endl<<endl<<endl<<player<< " roll your Dice:";
		getch();
	}
	cout<<"\n\nCONGRATULATIONS...! "<<player<<" you WIN.";//Giving congratulation wining player
	getch();
	goto start;//back to main menu
		
		}
		//*********************************************************************single user end 
		else if(mode=='2'){	//************************************************two player mode start
		  system("cls");
	      style();
	   	string player1,player2;
		cout<<"Enter Your Name(Player 1) :";
		cin>>player1;
		cout<<"Enter Your Name(Player 2) :";
		cin>>player2;
			int score1=0;
				int score2=0;
		while(score1<=100&&score2<=100){
		system("cls");
		style();
		board(score1,score2);
		rules();
		int dice1=((rand()+time(0))%6)+1;//random no for player 1
		location(50,30);
			cout<<"\n\n\n\n  "<<player2<<" ("<<char(248)<<") your Position is on :"<<position(score2);//position of player 2
		 cout<<"\n\n  "<<player1<<" (*) your Position is on :"<<position(score1);//position of player 1
		cout<<endl<<endl<<"  "<<player2<< " roll your Dice:";
		dice(dice1);
		score1=position(score1)+dice1;//score of player1 
		int x=position(score1);//score of player 1 after snake ledder
		image(score1);
		location(23,38);
		getch();
		system("cls");
		style();
		board(score1,score2);
		rules();
		int dice2=((rand()+time(0))%6)+1;
		location(50,30);
		 cout<<"\n\n\n\n  "<<player1<<" (*) your Position is on :"<<position(score1);
		cout<<"\n\n  "<<player2<<" ("<<char(248)<<") your Position is on :"<<position(score2);
		cout<<endl<<endl<<"  "<<player1<< " roll your Dice:";
		  dice(dice2);
		   score2=position(score2)+dice2;//score of player 2
			int y=position(score2);//score after snake or ladder
			image(score2);
			location(23,38);
			getch();
	} 
	//for congratulating the wining player
	if(score1>=100){
			cout<<"\n\n\n\n\nCONGRATULATIONS...! "<<player1<<" you WIN.\n\n Enter any key to to backe to Main Menu";
			getch();
			goto start;
			
	}
	else	if(score2>=100){
			cout<<"\n\n\n\n\nCONGRATULATIONS...! "<<player2<<" you WIN.\n\n Enter any key to to backe to Main Menu";
				getch();
			goto start;
			
	}
		
	}//player two mode end
	else{ //for wrong input in mode selection
		cout<<"Wrong input\n Enter any key to go back to main menu"<<endl;
		getch();
		goto start;//back to main menu
	}
	
}//**************************************************************************************************selecting game mode end
    else if(select=='3'){//for quiting game
		exit(1);
	}
	else{// for inputing wrong value in setction
	    cout<<"Wrong Input....!"<<endl;
	    cout<<"Enter any key to go bcak";
	    getch();
	  goto start;//back to main menu
	}
	
	
	return 0;
	//*************************************************************************************MAIN Function end
}
//******************************************************************************************Functions definations
	//*********************************************************function for printing front screen style
	void style(){
	cout<<"    	                   ___                ______             "<<endl;
	cout<<" ____ |\\    |   /^\\   | / |                  /  __  \\    ,.````o\\...  "<<endl;
	cout<<"(___  |  \\  |  /---\\  |<  |---              /  /  \\  \\  /       /```"<<endl;
	cout<<"____) |    \\| /     \\ | \\ |___   	   /  /    \\  \\/  /``~~ "<<endl;
	cout<<"                                 AND       \\;/      \\___,/       "<<endl;
	cout<<"\n                                                   __     __     __   ___"<<endl;
	cout<<"   =========================       |        /^\\   |   \\  |   \\  |    |___)"<<endl;
    cout<<"    |  |  |  |  |  |  |  |         |       /---\\  |    | |    | |--  |  \\  "<<endl;
	cout<<"   =========================       |____  /     \\ |__ /  |__ /  |__  |   \\  \n "<<endl;
	cout<<"================================================================================\n";
}
//******************************************************************************************************function for printing instruction
void instruction(){
    cout<<"1-Press 2 to paly Game:\n   a)there are two Modes in Game 1) Single Player 2) Double Player.\n2-There are 100 boxes in the Game (1 to 100) by rolling Dice you have Reach to 100th Possition to Win.\n3-In Single Player can you can Play Alone.\n4-In Double Players Mode You can play with Your Friend.\n5-To Make a Game Challanging There are some Snake and ladders on Different Possitions.\n   a)If Your possition rolls on snake mouth then you have to go to the tail possition of the snake.\n   b)If your possition rolls on the ladder than you will to go to the top go ladder. "<<endl<<endl;
	}
	

void board(int x,int y){
	int array[10][10];
	int num=100;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			array[i][j]=num--;
			
			
		}
	}   
cout<<"\b";
		for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<"  "<<array[i][j];
			if(array[i][j]==x){
				cout<<"*";
			}
				if(array[i][j]==y){
				cout<<char(248);
			}
		}
		cout<<"\b"<<endl<<endl;
	}

	cout<<endl<<endl;
	
}	
void dice(int x){///*****************************************************************function for printing dice on screen
	cout<<endl<<endl;
		if(x==1)
		{
			// for dice 1
			location(57,25);
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
	location(57,26);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186)<<endl;
	location(57,27);
	cout<<char(186)<<char(32)<<char(32)<<char(220)<<char(32)<<char(32)<<char(186)<<endl;
	location(57,28);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186)<<endl;
	location(57,29);
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl<<endl<<endl;
	}else if(x==2)
	{
		//for dice 2
			location(57,25);
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
		location(57,26);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186)<<endl;
		location(57,27);
	cout<<char(186)<<char(32)<<char(220)<<char()<<char(220)<<char()<<char(186)<<endl;
		location(57,28);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186)<<endl;
		location(57,29);
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl<<endl<<endl;
	}else	if(x==3)
	{
		//for dice 3
	location(57,25);
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
	location(57,26);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(32)<<char(32)<<char(186)<<endl;
	location(57,27);
	cout<<char(186)<<char(32)<<char(32)<<char(220)<<char(32)<<char(32)<<char(186)<<endl;
	location(57,28);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,29);
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl<<endl<<endl;

	}else	if(x==4)
	//for dice 4
	{location(57,25);
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
	location(57,26);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,27);
	cout<<char(186)<<char(32)<<char(32)<<char(32)<<char(32)<<char(32)<<char(186)<<endl;
	location(57,28);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,29);
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl<<endl<<endl;
	}	else if(x==5)
	{//for dice 5
		location(57,25);
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
	location(57,26);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,27);
	cout<<char(186)<<char(32)<<char(32)<<char(220)<<char(32)<<char(32)<<char(186)<<endl;
	location(57,28);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,29);
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl<<endl<<endl;
	}else	if(x==6)
	{
		//for dice 6
		location(57,25);
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
	location(57,26);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,27);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,28);
	cout<<char(186)<<char(32)<<char(220)<<char(32)<<char(220)<<char(32)<<char(186)<<endl;
	location(57,29);
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl<<endl<<endl;
}
}
//******************************************************************Function for returnng positon after snake and ladder
int position(int score){
	//****************************************************************return position after SNAKES
	if(score==34){
		return   score-4;
	}
		else if(score==59){
		 return  score-25;
	}
		else if(score==99){
		  return score-34;
	}
		else if(score==69){
		  return score-15;}
		 if(score==95){
		  score-88;
		//***************************************return position after LADDERS
	}	else if(score==4){
		return score+23;
	}	else if(score==38){
		return score+4;
	}	else if(score==49){
		  return score+4;
	}   else if(score==66){
		 return score+23;
	}
	    else if(score==85){
		 return score+12;
		}
		else{
		  return score;
		}
	
}

void rules(){//***********************************************function for printing the rulrs of game
location(50,13);
	cout<<"  ========RULES=========";
	location(50,14);
	cout<<"  =Snakes=    =Ladders="<<endl<<endl;
	location(50,15);
	cout<<"  34 > 30	04 > 27  \n"<<endl;
	location(50,16);
	cout<<"  69 > 54	38 > 42 \n"<<endl;
	location(50,17);
	cout<<"  59 > 34	49 > 53 \n"<<endl;
	location(50,18);
	cout<<"  95 > 88	66 > 89 \n"<<endl;
	location(50,19);
	cout<<"  99 > 65	85 > 97 \n"<<endl;
}
//*******************************************************************function for location in screen
void location(int x,int y){
	COORD cordinate;
	cordinate.X=x;
		cordinate.Y=y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cordinate);
	
}
void snake(){//****************************************************************************************************************snake print
	cout<<"          						 ____"<<endl;
	cout<<"         						/  ..\\"<<endl;
	cout<<"         						\\    --<"<<endl;
	cout<<"          						 \\   /"<<endl;
	cout<<"  						 _________\\  \\"<<endl;
	cout<<"						-:__________\\ \\"<<endl;
}
void ladder(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////LADER Print
	cout<<"     						     /====/"<<endl;
	cout<<"    						    /====/"<<endl;
	cout<<"   						   /====/"<<endl;
	cout<<"  						  /====/"<<endl;
	cout<<" 					  	 /====/"<<endl;
	cout<<"			                	/====/"<<endl;
}

void image(int score){
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////for printing SNAKES
	if(score==34){
		snake();
	}
		else if(score==59){
     		snake();
	}
		else if(score==99){
			snake();
	}
		else if(score==69){
			snake();
	}
		 else if(score==95){
		 	snake();
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////for printing LADDERS
	}	else if(score==4){
		ladder();
	}	else if(score==38){
		ladder();
	}	else if(score==49){
		ladder();
	}   else if(score==66){
		ladder();
	}
	    else if(score==85){
		ladder();
		}
	
}
//********************************************************************************************************************************Functions Definations end
