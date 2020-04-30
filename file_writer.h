#include<iostream>
//#include<conio.h>
#include<fstream>
#include "game.h"
using namespace std;
class Write_Txt{
public:
int i;
Game Temp_game_data[4];
fstream File_buff;
void create_file()
{
File_buff.open("wcResult.txt",ios::out|ios::trunc);
}
bool check_file()
{
    if(File_buff.is_open())
    {
        cout<<"File created";
        return true;
    }else{
        cout<<"File Failed";
    return false;
    }
}
void insert_data(Game game_data[],int n,int t1_F,int t2_F)
{   for(i=0;i<n;i++)
{
    Temp_game_data[i]=game_data[i];
}
    create_file();
    if(cout<<check_file())
    {
        File_buff<<"Welcome to World Cup Hockey";
        File_buff<<endl<<"The 4 teams that are in semi finals are :";
        display_Teams();
        /*First semi final*/
        File_buff<<endl<<"-----------First Semi Final--------------"<<endl;
        File_buff<<endl<<"Match between Team "<<Temp_game_data[0].Nationality<<" and Team "<<Temp_game_data[1].Nationality;
        File_buff<<endl<<Temp_game_data[0].Nationality<<" = "<<Temp_game_data[0].goal<<" Goals";
        File_buff<<endl<<Temp_game_data[1].Nationality<<" = "<<Temp_game_data[1].goal<<" Goals";
        if(Temp_game_data[0].goal>Temp_game_data[1].goal)
        File_buff<<endl<<"Team "<<Temp_game_data[0].Nationality<<" Won the game";
        else
        File_buff<<endl<<"Team "<<Temp_game_data[1].Nationality<<" Won the game";
        File_buff<<endl<<"-----------Second Semi Final--------------"<<endl;
        File_buff<<endl<<"Match between Team "<<Temp_game_data[2].Nationality<<" and Team "<<Temp_game_data[3].Nationality;
        File_buff<<endl<<Temp_game_data[2].Nationality<<" = "<<Temp_game_data[2].goal<<" Goals";
        File_buff<<endl<<Temp_game_data[3].Nationality<<" = "<<Temp_game_data[3].goal<<" Goals";
        if(Temp_game_data[2].goal>Temp_game_data[3].goal)
        File_buff<<endl<<"Team "<<Temp_game_data[2].Nationality<<" Won the game";
        else
        File_buff<<endl<<"Team "<<Temp_game_data[3].Nationality<<" Won the game";
        File_buff<<endl<<"-----------Final Match--------------"<<endl;
        File_buff<<endl<<"Match between Team "<<Temp_game_data[t1_F].Nationality<<" and Team "<<Temp_game_data[t2_F].Nationality;
        File_buff<<endl<<Temp_game_data[t1_F].Nationality<<" = "<<Temp_game_data[t1_F].goal<<" Goals";
        File_buff<<endl<<Temp_game_data[t2_F].Nationality<<" = "<<Temp_game_data[t2_F].goal<<" Goals";
        if(Temp_game_data[t1_F].goal>Temp_game_data[t2_F].goal)
        {
        File_buff<<endl<<"Team "<<Temp_game_data[t1_F].Nationality<<" Won the game"<<endl;
        File_buff<<endl<<"----------------Final Result-------------------";
        File_buff<<endl<<"The Euro Cup is ended!! Team "<<Temp_game_data[t1_F].Nationality<<" is the winner";
        }
        else
        {
        File_buff<<endl<<"Team "<<Temp_game_data[t2_F].Nationality<<" Won the game"<<endl;
        File_buff<<endl<<"----------------Final Result-------------------";
        File_buff<<endl<<"The Euro Cup is ended!! Team "<<Temp_game_data[t2_F].Nationality<<" is the winner";
        }
        File_buff<<endl<<endl<<"------------Details of Teams performance and points--------------";
        File_buff<<endl<<"S.no\tTeam Name\tTotal Goals\tTotal Match Wins";
        for(i=0;i<n;i++)
        {
            File_buff<<endl<<i+1<<"\t"<<Temp_game_data[i].Nationality<<"\t"<<Temp_game_data[i].goal<<"\t"<<Temp_game_data[i].match_wins<<"\t";
        }
        File_buff.close();
    }
    else{
        cout<<"Error occured";
    }
}
void display_Teams()
{   File_buff<<endl<<"S.No\tTeams";
    for(i=0;i<4;i++)
    {
    File_buff<<endl<<i+1<<"\t"<<Temp_game_data[i].Nationality;
    }
}
};