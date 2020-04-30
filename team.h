#include <iostream>
//#include <conio.h>
#include <vector>
#include<string.h>
#include<algorithm>
using namespace std;
class Team
{  
public:
    int i,j,k;
    int goal=0;
    int match_wins=0;
    string Nationality;
    string players[4];
    int Team_skill_level;
    vector<int> skill_level_players; 
    vector<int> speed;
    vector<int> power;
    vector<int> injury;
    vector<int> team_work;
    vector<int> performance;
    Team(){}
    Team(string Nation){
        Nationality=Nation;
        skill_level_players.reserve(4);
        speed.reserve(4);
        power.reserve(4);
        team_work.reserve(4);
        performance.reserve(4);
    }
    ~Team()
    {

    }
/*
Initialize player skills
*/
    void get_players_skill(){
        for(i=0;i<4;i++)
        {
             cout << "Enter Player's skill level in scale of (1-5) for " <<players[i]<< " : ";
             cin>>skill_level_players[i];
             cout<<"Enter player "<<players[i]<<""<<" Power in scale (1-5) : ";
             cin>>power[i];
             cout<<"Enter player "<<players[i]<<""<<" Speed in scale (1-5):";
             cin>>speed[i];
             cout<<"Enter player "<<players[i]<<""<<" Team Work in scale (1-5):";
             cin>>team_work[i];
             cout<<endl;
        }
    }
/*
Display Team details
*/
    void get_team_details(){
        for(i=0;i<4;i++){
            performance[i]=2*skill_level_players[i]+power[i]+speed[i]+team_work[i];
            cout<<i+1<<".\t"<<players[i]<<"\t\t"<<skill_level_players[i]<<"\t"<<power[i]<<"\t"<<speed[i]<<"\t"<<team_work[i]<<"\t"<<performance[i];
            cout<<endl;
        }
    }
};