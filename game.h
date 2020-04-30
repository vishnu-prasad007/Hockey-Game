#include <iostream>
//#include <conio.h>
#include "team.h"
using namespace std;
class Game : public Team
{
public:
    int predict_attack = 0, predict_lose = 0, start = 5;
    vector<int> opp_team_player_skill;
    vector<int> opp_team_player_power;
    vector<int> opp_team_player_speed;
    vector<int> opp_team_player_team_work;
    Game *temp_obj;
    Game(){
        

    }
    Game(string Nation)
        : Team(Nation)
    {
        opp_team_player_skill.reserve(4);
        opp_team_player_power.reserve(4);
        opp_team_player_speed.reserve(4);
        opp_team_player_team_work.reserve(4);
    }
    void analyze_team(Game * opp_team)
    { 
        if (/*Team_skill_level < opp_team->Team_skill_level*/ true)
        {

            player_strength_fun(opp_team);
            attack(start, 'c',opp_team);
            switch_team_lose(opp_team);
            display_goal(opp_team);
            
        }
        else
        {
            cout << "termin";
        }
    }
    void player_strength_fun(Game * opp_team_)
    {
        for (i = 0; i < 4; i++)
        {
            opp_team_player_skill[i] = opp_team_->skill_level_players[i];
            opp_team_player_power[i] = opp_team_->power[i];
            opp_team_player_speed[i] = opp_team_->speed[i];
            opp_team_player_team_work[i] = opp_team_->team_work[i];
        }
    }

    void attack(int n, char c,Game *op_team)
    {
        n--;
        if (c == 'c')
        {
            if ((skill_level_players[n] >= opp_team_player_skill[n]))
            {
                predict_attack++;
                cout << endl
                     << "Attacking";
                if (power[n] > opp_team_player_power[n] || speed[n] > opp_team_player_speed[n])
                {
                    goal++;
                    cout << endl
                         << "Team " << Nationality <<" score a Goal";
                }
                attack(n, c,op_team);
            }
            else if (n > 0)
            {
                predict_lose++;
                attack(n, c,op_team);
            }
        }
        else
        {
            if ((skill_level_players[n] <= opp_team_player_skill[n]))
            {
                //opp_predict_attack++;
                op_team->predict_attack++;
                cout << endl
                     << "Attacking";
                if (power[n] < opp_team_player_power[n] || speed[n] < opp_team_player_speed[n])
                {   op_team->goal++;
                    cout << endl<< "Team " <<op_team->Nationality<<" score a Goal";
                }
                attack(n, c,op_team);
            }
            else if (n > 0)
            {   op_team->predict_lose++;
                attack(n, c,op_team);
            }
        }
    }
    void switch_team_lose(Game *opp_team)
    {
        if (predict_lose >= 0)
        {
            cout << endl<< "Foul from " << Nationality <<" player";
            attack(start, 'o',opp_team);
        }
    }
    void display_goal(Game *opp_team)
    {
        cout<<endl<<Nationality<<"= "<<goal<<" Goals";
        cout<<endl<<opp_team->Nationality<<"= "<<opp_team->goal<<" Goals";
        if(goal>opp_team->goal) { match_wins++;
        cout<<endl<<"Team "<<Nationality<<" won the game";}
        else{ opp_team->match_wins++;
        cout<<endl<<"Team "<<opp_team->Nationality<<" won the game";
        }
    }

    /*Final teams analyzer*/
    void analyze_team_final(Game * opp_team)
    { 
        if (/*Team_skill_level < opp_team->Team_skill_level*/ true)
        {

            player_strength_fun(opp_team);
            attack(start, 'c',opp_team);
            switch_team_lose(opp_team);
            display_goal_final(opp_team);
            
        }
        else
        {
            cout << "termin";
        }
    }
    void display_goal_final(Game *opp_team)
    {
        cout<<endl<<Nationality<<"= "<<goal<<" Goals";
        cout<<endl<<opp_team->Nationality<<"= "<<opp_team->goal<<" Goals";
        if(goal>opp_team->goal)
        {   match_wins++;
        cout<<endl<<"Team "<<Nationality<<" won the game";
        cout<<endl<<endl<<"----------Final Result--------------------";
        cout<<endl<<"The Euro Cup is ended!! Team "<<Nationality<<" is the winner";
        }
        else
        {   opp_team->match_wins++;
        cout<<endl<<"Team "<<opp_team->Nationality<<" won the game";
        cout<<endl<<endl<<"----------Final Result--------------------";
        cout<<endl<<"The Euro Cup is ended!! Team "<<opp_team->Nationality<<" is the winner";
    }
    }
};