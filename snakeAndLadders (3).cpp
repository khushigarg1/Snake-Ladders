#include<bits/stdc++.h>
#include <conio.h>
#include<ctime>

using namespace std;

    
    


//----------------------------------------------CLASSES-------------------------------------------- 
//----------------------------------------------CLASSES-------------------------------------------- 
//----------------------------------------------CLASSES-------------------------------------------- 
void winnerList(string str);
//---------------------------CLASS PLAYER - defines attributes of each player
class player
{

    int pIndex;              //PLAYER NUMBER
    string name;             //PLAYER NAME
    bool victory = false;    //IF PLAYER REACHED 100

public:
    int position = 0;        //PLAYER ONBOARD POSITION
    
    int r;
    bool Act_Status = false; //IF PLAYER IS IN THE GAME
    //----------------------------------ASSIGNS NUMBER TO PLAYER
    player(int i)
    {
        pIndex = i;
    }
    //----------------------------------INPUT NAME
    void setName()
    {
        cout << endl
             << "Enter name for the player " << pIndex + 1 << " :\n ";
    
        getline(cin >> ws, name); // to enter the name, ws prevents any white space or line change problems
    }
    //----------------------------------PRINT NAME
    inline string getname()
    {
        return name;
    }
    //----------------------------------ROLLING A DICE
    void DiceRoll()
    {
        // srand((unsigned)time(NULL)); //RANDOM SEED
        r = 1 + rand() % 6;        //DICE
        if (position + r <= 100)       //CANT GO BEYOND 100
        {
            
            position += r;
            
        }
        if (r == 6)
        {
            cout<<endl<<"you rolled 6 you will roll again"<<endl;
            DiceRoll();
        }
        

        if (position == 100) //VICTORY AT 100
        {
            setVictory_true();
            
        }
    }
    //----------------------------------PLAYER IS ACTIVE
    void setVictory_true(){
        victory = true;
        cout<<name<<" reached 100!\n";
        Act_Status = false;
        winnerList(name);
    }
    void setAct_statusTrue()
    {
        Act_Status = true;
    
    }
    void setAct_statusFalse(){
        Act_Status = false;
    
    }
};
//-----------------------------CLASS SQAR - defines attributes of each sqar

//---------------------------------FUNCTIONS-------------------------------------
//---------------------------------FUNCTIONS-------------------------------------
//---------------------------------FUNCTIONS-------------------------------------

//--------------------------------NUMBER OF PLAYERS

void NumberOfPlayers(int &NOP)
{

    do
    {
        system("cls");
        cout << "Enter number of players(less than 6) : ";
        cin >> NOP;
    } while (NOP > 5 || NOP <= 1); //to prevent user from entering numbers other than 1-5
}

//----------------------------------INSTRUCTIONS
void howToPlay()
{
    cout << "First player to reach 100 wins!!\n";
    cout << "Rest of the players will be ranked followingly\n";
    cout << "If you roll a 6, you be awarded one more turn\n";
    cout << "Step 1: Enter Number of players\n";
    cout << "Step 2: Give name to each player according to your choice\n";
    cout << "Step 3: Now the game will start, Press enter to roll the dice at your turn\n";

    cout << endl
         << endl
         << "PRESS ANY KEY.........";
    getch();
    system("cls");
}
//---------------------------------Active PLAYER FUNCTION;
int ActivePlayers(player Players[]){
    int run = 0;
    for (int i = 0; i < 5; i++)
    {
        run += Players[i].Act_Status;
    }
    return run;
    
}
//-----------------------------------------
void SnakeorLadder(int &num){
    int ladder[100] = {0};
    ladder[97] = -88;
    ladder[3] = 10 ;
    ladder[8] = 22 ;
    ladder[16] = -10 ;
    ladder[20] = 21  ;
    ladder[27] = 56 ;
    ladder[53] = -20  ;
    ladder[50] = 16 ;
    ladder[61] = -43;
    ladder[63] = -4 ;
    ladder[71] = 19;
    ladder[79] = 19;
    ladder[86] = -51;
    ladder[92] = -20 ;
    ladder[94] = -20;

    if (ladder[num - 1] > 0)
    {
        cout<<endl<<"you found a ladder and you position increased by "<<ladder[num - 1]<<" places"<<endl;
    }
    else if(ladder[num - 1] < 0)
    {
        cout<<endl<<"you found a snake and you position decreased by "<<ladder[num - 1]<<" places"<<endl;
    }
    
    num += ladder[num - 1];
}
//------------------------------------WINNER LIST
vector<string> v;
void winnerList(string str){
    v.push_back(str);
}


//------------------------------------------MAIN--------------------------------------------------------
//------------------------------------------MAIN--------------------------------------------------------
//------------------------------------------MAIN--------------------------------------------------------

int main()
{
    srand((unsigned)time(NULL));
    system("cls");
    //instructions-------------------------------------------------------------------
    int game[100] = {0};
    
    
    howToPlay();

    ///get players and assign name----------------------------------------------------
    player Player[5] = {0, 1, 2, 3, 4};

    int NOP;
    NumberOfPlayers(NOP);
    

    for (int i = 0; i < NOP; i++) // sets the required number of players as active
    {
        Player[i].Act_Status = true;
    }
        for (int i = 0; i < 5; i++) // sets name to active players using setName from  the class
        {
            if (Player[i].Act_Status)
            {
                Player[i].setName();
            }
        }
        system("cls");
        cout << endl
             << "The players are:\n"; // print the name of the players
        for (int i = 0; i < NOP; i++)
        {
            cout << "Player " << i + 1 << ": " << Player[i].getname() << endl;
        }

        cout << "\nPress any key........";
        getch();
        system("cls");

        //--------------------------------------------------------------------------------

        //number of squares on the board
            int block = 100;
        int temp;
        int run = ActivePlayers(Player);
        while(run >= 2){
        
        

        for (int j = 0; j < NOP; j++)
        {
            block = 100;
            if (!(Player[j].Act_Status))
            {
                continue;
            }
            
            
            for (int i = 10; i > 0; i--) // 10 rows
            {
                if (block == 10) // for the row 1 - 10
                {
                    temp = block;
                    temp -= 9;

                    for (int l = 10; l > 0; l--)
                    {
                        if (temp == 10)
                        {
                            cout << temp << " |";
                        }
                        else
                            cout << temp << "  |";
                        //code
                        for (int k = 0; k < game[temp-1]; k++)
                        {
                            cout<<";";
                        }
                        cout<<setw(5 - game[temp - 1]);
                        //code
                        cout << "|";
                        temp++;
                    }
                }
                else if (block % 20 == 0) // for rows ending in even
                {
                    for (int l = 10; l > 0; l--)
                    {
                        if (block == 100) // to give appropriate space
                        {
                            cout << block << "|";
                        }
                        else
                            cout << block << " |";
                        //code
                        for (int k = 0; k < game[block-1]; k++)
                        {
                            cout<<";";
                        }
                        cout<<setw(5 - game[block-1]);
                        // code
                        cout << "|";
                        block--;
                    }
                }
                else // for rows ending in odd
                {
                    temp = block;
                    temp -= 9;

                    for (int l = 10; l > 0; l--)
                    {
                        cout << temp << " |";
                        //code
                        for (int k = 0; k < game[temp-1]; k++)
                        {

                            cout<<";";
                        }
                        cout<<setw(5 - game[temp-1]);
                        //code
                        cout << "|";
                        temp++;
                    }
                    block -= 10;

                }
                cout << endl;

            }
            cout<<endl<<"press enter to play next turn";
            getch();
            system("cls");
            cout<<Player[j].getname()<<" Press enter to roll dice \n";
            getch();
            game[Player[j].position - 1]--;
            Player[j].DiceRoll();
            cout<<"you rolled a "<<Player[j].r<<endl;
            SnakeorLadder(Player[j].position);
            game[Player[j].position - 1]++;
            
            // if(Player[j].r == 6 && Player[j].Act_Status){
            //     cout<<"You rolled a 6, another turn\n";
            //     j--;
            // }
           
        }
        run = ActivePlayers(Player);
        
    }
    for (int i = 0; i < NOP; i++)
    {
        cout<<"|| "<<v[i]<<setw(30 - v[i].length())<<"| "<<i + 1<<" Place ||\n";
    }
    

    return 0;
}




