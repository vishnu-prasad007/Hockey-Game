#include <iostream>
//#include <conio.h>
#include <string.h>
#include "file_writer.h"
using namespace std;
int main()
{
    int i, j, total_team, _gamechoice_;string t1,t2;
    int t1_index,t2_index;
    Write_Txt file_obj;
    Game T_eam[4] = {Game("Canada"), Game("India"), Game("USA"), Game("UK")};
    T_eam[0].players[0] = "Sidney Crosby";
    T_eam[0].players[1] = "Robereto Luoungo";
    T_eam[0].players[2] = "Jhon Taveres";
    T_eam[0].players[3] = "Wayne Gretzky";
    T_eam[1].players[0] = "Alexender Ovechkin";
    T_eam[1].players[1] = "Evgeni Malkin";
    T_eam[1].players[2] = "Pavel Datsyuk";
    T_eam[1].players[3] = "Pavel Bure";
    T_eam[2].players[0] = "Ryan Kesler";
    T_eam[2].players[1] = "Patrick Kane";
    T_eam[2].players[2] = "Joe Pavelski";
    T_eam[2].players[3] = "Phil Kessel";
    T_eam[3].players[0] = "Henryk Gruth";
    T_eam[3].players[1] = "Krzysztof Oliwa";
    T_eam[3].players[2] = "Peter Sidokiewicz";
    T_eam[3].players[3] = "Mariusz Czerkawaki";

    //cout<<T_eam[0].Nationality;
    total_team = sizeof(T_eam) / sizeof(T_eam[0]);
    cout << "-----------Welcome to World Cup Hockey 2019 -----------" << endl;
    for (i = 0; i < total_team; i++)
    {
        cout << "Set Team " << T_eam[i].Nationality << "\'s "
             << "skill level from (1-5)  : ";
        cout << endl;
        cin >> T_eam[i].Team_skill_level;
    }
   // cout << "Wanna play shootout round or game";
   cout<<"Wanna play Shootout"<< endl<<"1. Game";
   // cout << endl<< "2. Game";
    cin >> _gamechoice_;
    if (_gamechoice_ == 2)
    {
         /**
          * Yet to be done
         */
    }
    else if (_gamechoice_ == 1)
    {
        for (i = 0; i < total_team; i++)
        {
            T_eam[i].get_players_skill();
        }

        system("cls");
        cout << "Welcome to World Cup Hockey 2019 " << endl;
        cout << "----------------------------------" << endl;
        cout << "The 4 teams that are in Semi finals are : " << endl;
        for (i = 0; i < total_team; i++)
            cout << i + 1 << "."
                 << " " << T_eam[i].Nationality << endl;
        cout << "----------Each Team with Member Details------------" << endl
             << endl;
        for (i = 0; i < total_team; i++)
        {
            cout << "-----------" << T_eam[i].Nationality << " "
                 << "----------------" << endl;
            cout << "S No.\tName\t\t\t"
                 << "  "
                 << "Skill\tPower\tSpeed\tTeam Work\tPerformance" << endl;
            T_eam[i].get_team_details();
        }
        //system("cls");
        char choice_game_Start;
        cout << "-----------First Semi Final-----------------" << endl;
        cout << "Match Between Team Canada and Team India" << endl;
        cout << "Teams are ready Enter [S] to  start : ";
        cin >> choice_game_Start;
        if (choice_game_Start == 'S' || choice_game_Start == 's')
        {
            cout << "Team Canada is attacking India";
            T_eam[0].analyze_team(&T_eam[1]);
            //cout<<endl<<T_eam[0].Nationality<<"="<<T_eam[0].goal;
        }
        else
        {
            cout << endl
                 << "Match Cancelled";
        }
        cout << endl
             << "----------------Second Semi Final -----------------";
        cout << endl
             << "Match between Team USA and UK";
        cout << "Teams are ready Enter [S] to  start : ";
        cin >> choice_game_Start;
        if (choice_game_Start == 'S' || choice_game_Start == 's')
        {
            T_eam[2].analyze_team(&T_eam[3]);
        }
        
        else
            cout << endl
                 << "Match cancelled";
                     cout<<endl<<"--------------Final Match -----------------";
                     if(T_eam[0].goal>T_eam[1].goal)
                     {
                          t1=T_eam[0].Nationality; t1_index=0;
                     }
                         else
                         {
                         t1=T_eam[1].Nationality; t1_index=1;
                         }
                     if(T_eam[2].goal>T_eam[3].goal)
                     {
                          t2=T_eam[2].Nationality; t2_index=2;
                     }
                          else
                          {
                            t2=T_eam[3].Nationality; t2_index=3;
                          }
                            cout<<endl<<"Match between Team "<<t1<<" and "<<"team "<<t2;
                                    cout <<endl<< "Teams are ready Enter [S] to  start : ";
                                    cin>>choice_game_Start;
                                    if(choice_game_Start=='S'||choice_game_Start=='s')
                                    {
                                     T_eam[t1_index].analyze_team_final(& T_eam[t2_index]);
                                    }else
                                    cout<<"Match Cancelled";

                                    cout<<endl<<endl<<"----------Details of Teams Performance and points -----------------";
                                    cout<<endl<<"S.No\tTeam Name\t\tTotal Goals\tTotal Match Wins";
                                    for(i=0;i<4;i++)
                                    {
                                        cout<<endl<<i+1<<"\t"<<T_eam[i].Nationality<<"\t"<<T_eam[i].goal<<"\t"<<T_eam[i].match_wins;
                                    }
                                    file_obj.insert_data(T_eam,4,t1_index,t2_index);
                                    
    }
    else
    {
        cout << "Invalid Option ";
    }
    //getch();
    return 0;
}