// monopoly

#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;

/*struct board_spot
{
    int number;
    string name;
    double cost;
    double rent;
    string occupied;
};

struct player
{
    int turn;
    int spaces_moved;
    string player_name;
    vector<string> properties;
    double money;
    double net_worth;
    int spot;
};*/

// can we replace the structs with these?
struct player
{
    string player_name;
    int spaces_moved; // keep track of player's current position
    int net_worth;
    bool in_jail = false;
    int num_turns = 3; // keep track of how many turns player has left if in jail
    vector<string> occupied; // list of properties player owns
};

struct board_spot
{
    string name;
    int cost;
    int rent;
    int number; // do we stil need this?
    bool is_owned = false;
    player owner;

    // for chance and community cards (assumes action will be either one of these three)
    /*int give_money;
    int take_money;*/
    int move_to; // board space to move to
    string occupied;
};

vector<board_spot> board_setup ()
{
    board_spot chesapeake;
    chesapeake.number=22;
    chesapeake.name="Chesapeake";
    chesapeake.cost=60;
    chesapeake.rent=40;
    chesapeake.occupied = "open";

    board_spot question_1;
    question_1.name="?";

    board_spot waconia;
    waconia.number=21;
    waconia.name="Waconia";
    waconia.cost=60;
    waconia.rent=40;
    waconia.occupied = "open";

    board_spot airport_1;
    airport_1.name="AIRPORT";

    board_spot monopoly_1;
    monopoly_1.name="MONOPOLY CARD";

    board_spot dallas;
    dallas.number=20;
    dallas.name="Dallas";
    dallas.cost=100;
    dallas.rent=60;
    dallas.occupied = "open";

    board_spot first_class_1;
    first_class_1.name="FIRST CLASS";

    board_spot charlotte;
    charlotte.number=19;
    charlotte.name="Charlotte";
    charlotte.cost=100;
    charlotte.rent=60;
    charlotte.occupied = "open";

    board_spot portsmouth;
    portsmouth.number=18;
    portsmouth.name="Portsmouth";
    portsmouth.cost=100;
    portsmouth.rent=60;
    portsmouth.occupied = "open";
    
    board_spot jail_visiting;
    jail_visiting.name="JAIL: Just Visiting";

    board_spot seattle;
    seattle.number=17;
    seattle.name="Seattle";
    seattle.cost=160;
    seattle.rent=100;
    seattle.occupied = "open";

    board_spot question_2;
    question_2.name="?";

    board_spot little_rock;
    little_rock.number=16;
    little_rock.name="Little Rock";
    little_rock.cost=160;
    little_rock.rent=100;
    little_rock.occupied = "open";

    board_spot atlanta;
    atlanta.number=15;
    atlanta.name="Atlanta";
    atlanta.cost=160;
    atlanta.rent=100;
    atlanta.occupied = "open";

    board_spot monopoly_2;
    monopoly_2.name="MONOPOLY CARD";

    board_spot denver;
    denver.number=14;
    denver.name="Denver";
    denver.cost=200;
    denver.rent=120;
    denver.occupied = "open";

    board_spot first_class_2;
    first_class_2.name="FIRST CLASS";

    board_spot asheville;
    asheville.number=13;
    asheville.name="Asheville";
    asheville.cost=200;
    asheville.rent=120;
    asheville.occupied = "open";

    board_spot cleveland;
    cleveland.number=12;
    cleveland.name="Cleveland";
    cleveland.cost=200;
    cleveland.rent=120;
    cleveland.occupied = "open";

    board_spot free_parking;
    free_parking.name="FREE PARKING";

    board_spot milwaukee;
    milwaukee.number=11;
    milwaukee.name="Milwaukee";
    milwaukee.cost=260;
    milwaukee.rent=140;
    milwaukee.occupied = "open";

    board_spot question_3;
    question_3.name="?";

    board_spot boston;
    boston.number=10;
    boston.name="Boston";
    boston.cost=260;
    boston.rent=140;
    boston.occupied = "open";

    board_spot detroit;
    detroit.number=9;
    detroit.name="Detroit";
    detroit.cost=260;
    detroit.rent=140;
    detroit.occupied = "open";

    board_spot monopoly_3;
    monopoly_3.name="MONOPOLY CARD";

    board_spot charleston;
    charleston.number=8;
    charleston.name="Charleston";
    charleston.cost=300;
    charleston.rent=180;
    charleston.occupied = "open";

    board_spot indianapolis;
    indianapolis.number=7;
    indianapolis.name="Indianapolis";
    indianapolis.cost=300;
    indianapolis.rent=180;
    indianapolis.occupied = "open";

    board_spot first_class_3;
    first_class_3.name="FIRST CLASS";

    board_spot chicago;
    chicago.number=6;
    chicago.name="Chicago";
    chicago.cost=300;
    chicago.rent=180;
    chicago.occupied = "open";

    board_spot jail;
    jail.name="GO TO JAIL";

    board_spot los_angeles;
    los_angeles.number=5;
    los_angeles.name="Los Angeles";
    los_angeles.cost=360;
    los_angeles.rent=200;
    los_angeles.occupied = "open";

    board_spot virginia_beach;
    virginia_beach.number=4;
    virginia_beach.name="Virginia Beach";
    virginia_beach.cost=360;
    virginia_beach.rent=200;
    virginia_beach.occupied = "open";

    board_spot question_4;
    question_4.name="?";

    board_spot new_york;
    new_york.number=3;
    new_york.name="New York";
    new_york.cost=360;
    new_york.rent=200;
    new_york.occupied = "open";

    board_spot monopoly_4;
    monopoly_4.name="MONOPOLY CARD";

    board_spot airport_2;
    airport_2.name="AIRPORT";

    board_spot minneapolis;
    minneapolis.number=2;
    minneapolis.name="Minneapolis";
    minneapolis.cost=400;
    minneapolis.rent=240;
    minneapolis.occupied = "open";

    board_spot first_class_4;
    first_class_4.name="FIRST CLASS";

    board_spot pierce;
    pierce.number=1;
    pierce.name="Pierce";
    pierce.cost=400;
    pierce.rent=240;
    pierce.occupied = "open";

    board_spot GO;
    GO.name="GO";

    vector<board_spot> board;
    board.push_back(chesapeake);
    board.push_back(question_1);
    board.push_back(waconia);
    board.push_back(airport_1);
    board.push_back(monopoly_1);
    board.push_back(dallas);
    board.push_back(first_class_1);
    board.push_back(charlotte);
    board.push_back(portsmouth);
    board.push_back(jail_visiting);
    board.push_back(seattle);
    board.push_back(question_2);
    board.push_back(little_rock);
    board.push_back(atlanta);
    board.push_back(monopoly_2);
    board.push_back(denver);
    board.push_back(first_class_2);
    board.push_back(asheville);
    board.push_back(cleveland);
    board.push_back(free_parking);
    board.push_back(milwaukee);
    board.push_back(question_3);
    board.push_back(boston);
    board.push_back(detroit);
    board.push_back(monopoly_3);
    board.push_back(charleston);
    board.push_back(indianapolis);
    board.push_back(first_class_3);
    board.push_back(chicago);
    board.push_back(jail);
    board.push_back(los_angeles);
    board.push_back(virginia_beach);
    board.push_back(question_4);
    board.push_back(new_york);
    board.push_back(monopoly_4);
    board.push_back(airport_2);
    board.push_back(minneapolis);
    board.push_back(first_class_4);
    board.push_back(pierce);
    board.push_back(GO);
    return board;


}

player player_setup (int num)
{
    string name;
    cout<<"Enter the name for the player"<<endl;
    cout<<"(the order in which you enter the names is the order of turns)"<<endl;
    cin>>name;
    player player1;
    player1.player_name = name;
    player1.spaces_moved = num;
    player1.net_worth = 700;
    return player1;
    
}

void board_display (vector<board_spot> board)
{
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|             |      "<<board[20].number<<"      |             |      "<<board[22].number<<"      |       "<<board[23].number<<"      |              |     "<<board[25].number<<"        |      "<<board[26].number<<"       |              |      "<<board[28].number<<"       |              |"<<endl;
    cout<<"|             |   "<<board[20].name<<"  |             |     "<<board[22].name<<"   |    "<<board[23].name<<"   |              |  "<<board[25].name<<"  | "<<board[26].name<<" |              |    "<<board[28].name<<"   |              |"<<endl;
    cout<<"|             |  cost: $"<<board[20].cost<<"  |             |  cost: $"<<board[22].cost<<"  |  cost: $"<<board[23].cost<<"  |              |  cost: $"<<board[25].cost<<"  |  cost: $"<<board[26].cost<<"  |              |  cost: $"<<board[28].cost<<"  |              |"<<endl;
    cout<<"|             |  rent: $"<<board[20].cost<<"  |             |  rent: $"<<board[22].cost<<"  |  rent: $"<<board[23].cost<<"  |              |  rent: $"<<board[25].cost<<"  |  rent: $"<<board[26].cost<<"  |              |  rent: $"<<board[28].cost<<"  |              |"<<endl;
    cout<<"|             |     "<<board[20].occupied<<"     |             |     "<<board[22].occupied<<"     |     "<<board[23].occupied<<"     |              |     "<<board[25].occupied<<"     |     "<<board[26].occupied<<"     |              |     "<<board[28].occupied<<"     |              |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|     "<<board[18].number<<"      |                                                                                                                                     |       "<<board[30].number<<"      |"<<endl;
    cout<<"|  "<<board[18].name<<"  |                                                                                                                                     |  "<<board[30].name<<" |"<<endl;
    cout<<"| cost: $"<<board[18].cost<<"  |                                                                                                                                     |  cost: $"<<board[30].cost<<"  |"<<endl;
    cout<<"| rent: $"<<board[18].cost<<"  |                                                                                                                                     |  rent: $"<<board[30].cost<<"  |"<<endl;
    cout<<"|    "<<board[18].occupied<<"     |                                                                                                                                     |     "<<board[30].occupied<<"     |"<<endl;
    cout<<"---------------                                                                                                                                     ----------------"<<endl;
    cout<<"|     "<<board[17].number<<"      |                                                                                                                                     |     "<<board[31].number<<"        |"<<endl;
    cout<<"| "<<board[17].name<<"   |                                                                                                                                     |"<<board[31].name<<"|"<<endl;
    cout<<"| cost: $"<<board[17].cost<<"  |                                                                                                                                     |  cost: $"<<board[31].cost<<"  |"<<endl;
    cout<<"| rent: $"<<board[17].cost<<"  |                                                                                                                                     |  rent: $"<<board[31].cost<<"  |"<<endl;
    cout<<"|    "<<board[17].occupied<<"     |                                                                                                                                     |    "<<board[31].occupied<<"      |"<<endl;
    cout<<"---------------                                                                                                                                     ----------------"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"---------------                                                                                                                                     ----------------"<<endl;
    cout<<"|     "<<board[15].number<<"      |                                                                                                                                     |      "<<board[33].number<<"       |"<<endl;
    cout<<"|   "<<board[15].name<<"    |                                                                                                                                     |   "<<board[33].name<<"   |"<<endl;
    cout<<"| cost: $"<<board[15].cost<<"  |                                                                                                                                     |  cost: $"<<board[33].cost<<"  |"<<endl;
    cout<<"| rent: $"<<board[15].cost<<"  |                                                                                                                                     |  rent: $"<<board[33].cost<<"  |"<<endl;
    cout<<"|    "<<board[15].occupied<<"     |                                                                                                                                     |     "<<board[33].occupied<<"     |"<<endl;
    cout<<"---------------                                                                                                                                     ----------------"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"---------------                                                                                                                                     ---------------"<<endl;
    cout<<"|     "<<board[13].number<<"      |                                                                                                                                     |              |"<<endl;
    cout<<"|   "<<board[13].name<<"   |                                                                                                                                     |              |"<<endl;
    cout<<"| cost: $"<<board[13].cost<<"  |                                                                                                                                     |              |"<<endl;
    cout<<"| rent: $"<<board[13].cost<<"  |                                                                                                                                     |              |"<<endl;
    cout<<"|    "<<board[13].occupied<<"     |                                                                                                                                     |              |"<<endl;
    cout<<"---------------                                                                                                                                     ----------------"<<endl;
    cout<<"|     "<<board[12].number<<"      |                                                                                                                                     |      "<<board[36].number<<"       |"<<endl;
    cout<<"| "<<board[12].name<<" |                                                                                                                                     |  "<<board[36].name<<" |"<<endl;
    cout<<"| cost: $"<<board[12].cost<<"  |                                                                                                                                     |  cost: $"<<board[36].cost<<"  |"<<endl;
    cout<<"| rent: $"<<board[12].cost<<"  |                                                                                                                                     |  rent: $"<<board[36].cost<<"  |"<<endl;
    cout<<"|    "<<board[12].occupied<<"     |                                                                                                                                     |     "<<board[36].occupied<<"     |"<<endl;
    cout<<"---------------                                                                                                                                     ----------------"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"|             |                                                                                                                                     |              |"<<endl;
    cout<<"---------------                                                                                                                                     ----------------"<<endl;
    cout<<"|    "<<board[10].number<<"       |                                                                                                                                     |      "<<board[38].number<<"       |"<<endl;
    cout<<"|  "<<board[10].name<<"    |                                                                                                                                     |    "<<board[38].name<<"    |"<<endl;
    cout<<"| cost: $"<<board[10].cost<<"  |                                                                                                                                     |  cost: $"<<board[38].cost<<"  |"<<endl;
    cout<<"| rent: $"<<board[10].cost<<"  |                                                                                                                                     |  rent: $"<<board[38].cost<<"  |"<<endl;
    cout<<"|    "<<board[10].occupied<<"     |                                                                                                                                     |     "<<board[38].occupied<<"     |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|             |      "<<board[8].number<<"      |      "<<board[7].number<<"     |              |      "<<board[5].number<<"      |              |              |      "<<board[2].number<<"      |              |     "<<board[0].number<<"       |              |"<<endl;
    cout<<"|             | "<<board[8].name<<"   |  "<<board[7].name<<"  |              |     "<<board[5].name<<"   |              |              |    "<<board[2].name<<"   |              |   "<<board[0].name<<" |              |"<<endl;
    cout<<"|             |  cost: $"<<board[8].cost<<"  | cost: $"<<board[7].cost<<"  |              |  cost: $"<<board[5].cost<<"  |              |              |   cost: $"<<board[2].cost<<"  |              |   cost: $"<<board[0].cost<<"  |              |"<<endl;
    cout<<"|             |  rent: $"<<board[8].cost<<"  | rent: $"<<board[7].cost<<"  |              |  rent: $"<<board[5].cost<<"  |              |              |   rent: $"<<board[2].cost<<"  |              |   rent: $"<<board[0].cost<<"  |              |"<<endl;
    cout<<"|             |     "<<board[8].occupied<<"     |     "<<board[7].occupied<<"    |              |     "<<board[5].occupied<<"     |              |              |     "<<board[2].occupied<<"     |              |     "<<board[0].occupied<<"     |              |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

bool stop_game()
{
    // INSERT
    return false;
}

bool in_jail(player current_player)
{
    return current_player.in_jail;
}

void withdraw_money(player current_player, int amount)
{
    current_player.net_worth -= amount;
}

void deposit_money(player current_player, int amount)
{
    current_player.net_worth += amount;
}

void move_to_space(player current_player, int spaces)
{
    current_player.spaces_moved = spaces;
}

// give player $200 for passing Go
void collect_go(player current_player)
{
    deposit_money(current_player, 200);
}

void pay_rent(player current_player, player player_to_pay, int amount_to_pay)
{
    withdraw_money(current_player, amount_to_pay);
    deposit_money(player_to_pay, amount_to_pay);
}

void buy_property(player current_player, board_spot prop)
{
    int price = prop.cost;

    withdraw_money(current_player, price);
    prop.owner = current_player;
    prop.is_owned = true;
    current_player.occupied.push_back(prop.name) ; // add prop to list of props player owns
}


int roll_dice ()
{
    srand(time(0));
    
    int d1 = rand() % 6 + 1;
    int d2 = rand() % 6 + 1;
    int values = d1 + d2;
    
    return values;
}



int main()
{
    // start game
    cout<<"How many players? (minimum 2 and maximum 4)"<<endl;
    int players_number;
    cin>>players_number;
    vector<player> players;
    if (players_number == 2)
    {
        player player1;
        player1 = player_setup(1);
        player player2;
        player2 = player_setup(2);
        players.push_back(player1);
        players.push_back(player2);
    }
    if (players_number == 3)
    {
        player player1;
        player1 = player_setup(1);
        player player2;
        player2 = player_setup(2);
        player player3;
        player3 = player_setup(3);
        players.push_back(player1);
        players.push_back(player2);
        players.push_back(player3);

    }
    if (players_number == 4)
    {
        player player1;
        player1 = player_setup(1);
        player player2;
        player2 = player_setup(2);
        player player3;
        player3 = player_setup(3);
        player player4;
        player4 = player_setup(4);
        players.push_back(player1);
        players.push_back(player2);
        players.push_back(player3);
        players.push_back(player4);
    }

    cout<<"All the players and starting money and net worths:"<<endl;
    for (int i = 0; i<players.size(); i++)
        cout<<players[i].player_name<<" money:"<<players[i].net_worth<<" net worth: "<<players[i].net_worth<<endl;
        
    cout<<"Display of the board"<<endl;
    vector<board_spot> board;
    board = board_setup();
    board_display(board);

    // play game
    int total_board_spaces = board.size();
    while (!stop_game())
    {
        for (int i = 0; i < players_number; i++)
        {
            // order of players = whoever enters their info first
            player current_player = players[i];
            player next_player;
            if (i == (players_number) - 1)
            {
                next_player = players[0];
            }
            else
            {
                next_player = players[i+1];
            }

            cout << "It is " << current_player.player_name << "'s turn." << endl;
            

            if (!in_jail(current_player))
            {
                int spaces_to_move = roll_dice();
                cout << "You rolled a " << spaces_to_move << "!" << endl;
                current_player.spaces_moved += spaces_to_move;
    

                // check if player passed go
                if (current_player.spaces_moved >= total_board_spaces)
                {
                    collect_go(current_player);
                    cout << "You have passed go. You now have $" << current_player.net_worth << "." << endl;
                    current_player.spaces_moved -= total_board_spaces;
                }

                // get board space/property that player landed on
                board_spot prop = board[current_player.spaces_moved];
                string name = prop.name;
                cout << "You have landed on " << name << "." << endl;
                
                // assumes that chance cards only involve player and next_player
                if (name == "Chance" || name == "Community")
                {
                    vector<string> chancecard;
                    chancecard.push_back("Move 10 spaces forward");
                    chancecard.push_back("You receive $200");
                    chancecard.push_back("Give $30 to each player");
                    chancecard.push_back("Move 5 spaces backward");
                    chancecard.push_back("Move to the nearest occupied space");
                    chancecard.push_back("You receive $40 from each player");
                    chancecard.push_back("You receive $10 from each player");
                    chancecard.push_back("You receive $100");
                    
                    int chooser = rand() % 9 + 0;
                    if (chancecard[chooser] == chancecard[0])
                    {
                        move_to_space(current_player, 10);
                        // move to specified space on board
                        int old_space = current_player.spaces_moved;
                        int new_space = prop.move_to;
                        move_to_space(current_player, new_space);
                        cout << "You have been moved to " << board[new_space].name << "." << endl;

                        // check if player passed go
                        if (new_space < old_space)
                        {
                            collect_go(current_player);
                            cout << "You have passed Go. You now have $" << current_player.net_worth << " ." << endl;
                        }
                    }
                    else if (chancecard[chooser] == chancecard[1])
                    {
                        deposit_money(current_player, 200);
                        cout << "Your new net worth is" << current_player.net_worth << "." << endl;
                    }
                    else if (chancecard[chooser] == chancecard[2])
                    {
                        withdraw_money(current_player, 30 * players_number);
                        deposit_money(players[0], 30);
                        deposit_money(players[1], 30);
                        deposit_money(players[2], 30);
                        deposit_money(players[3], 30);
                        withdraw_money(current_player, 30);
                        cout << "Your new net worth is" << current_player.net_worth << "." << endl;

                    }
                    else if (chancecard[chooser] == chancecard[3])
                    {
                        move_to_space(current_player, -5);
                        // move to specified space on board
                        int old_space = current_player.spaces_moved;
                        int new_space = prop.move_to;
                        move_to_space(current_player, new_space);
                        cout << "You have been moved to " << board[new_space].name << "." << endl;

                        // check if player passed go
                        if (new_space < old_space)
                        {
                            collect_go(current_player);
                            cout << "You have passed Go. You now have $" << current_player.net_worth << " ." << endl;
                        }

                    }
                    else if (chancecard[chooser] == chancecard[4])
                    {
                        deposit_money(current_player, 40 * players_number);
                        withdraw_money(players[0], 40);
                        withdraw_money(players[1], 40);
                        withdraw_money(players[2], 40);
                        withdraw_money(players[3], 40);
                        deposit_money(current_player, 40);
                        cout << "Your new net worth is" << current_player.net_worth << "." << endl;

                    }
                    else if (chancecard[chooser] == chancecard[5])
                    {
                        deposit_money(current_player, 10 * players_number);
                        withdraw_money(players[0], 10);
                        withdraw_money(players[1], 10);
                        withdraw_money(players[2], 10);
                        withdraw_money(players[3], 10);
                        deposit_money(current_player, 10);
                        cout << "Your new net worth is" << current_player.net_worth << "." << endl;

                    }
                    else
                    {
                        deposit_money(current_player, 100);
                        cout << "Your new net worth is" << current_player.net_worth << "." << endl;

                    }
                }
                else if (name == "Jail")
                {
                    // move player to jail
                    cout << "You've landed in jail! Your next 3 turns will be skipped." << endl;
                    current_player.in_jail = true;
                }
                else if (prop.is_owned)
                {
                    // pay rent
                    player player_to_pay = prop.owner;
                    int amount_to_pay = prop.rent;

                    cout << name << " is already owned. You must pay " << player_to_pay.player_name << " $" << amount_to_pay << " in rent." << endl;
                    pay_rent(current_player, player_to_pay, amount_to_pay);
                    cout << "You now have $" << current_player.net_worth<< " left." << endl;
                }
                else if (name != "Go")
                {
                    // buy property
                    char buy;
                    cout << name << " is not owned and costs " << prop.cost << "." << endl;
                    if (current_player.net_worth > 0)
                    {
                        cout << "Would you like to buy " << name << "? (Y/N)" << endl;
                        cin >> buy;
                        if (toupper(buy) == 'Y')
                        {
                            buy_property(current_player, prop);
                            cout << name << " is now yours! You have $" << current_player.net_worth << " left." << endl;
                        }
                        else
                            cout << name << " is still unowned." << endl;
                    }
                    else
                        cout << "However, you have $0 left! You will not be able to purchase new property." << endl;
                }
            }
            else
            {
                // keep track of remaining jail time
                int turns = current_player.num_turns;
                cout << "You are in jail for " << turns-1 << " more turn(s) after this turn." << endl;

                if (turns == 1)
                {
                    current_player.in_jail = false;
                    current_player.num_turns = 3;
                }
                else
                {
                current_player.num_turns--;
                }
            }
        }
    }
    return 0;
}

