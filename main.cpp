#include "Win.h"

#include "DisplayFunctions.h"

#include <iostream>

#include <iterator>

#include <list>

#include <cstdlib>

#include <ctime>

#include <iomanip>


using namespace std;

const int total_iterations_to_simulate=20;
const int starting_population_size = 50;

list<win*> create_initial_population()
{
    list<win*> wins;
    
    //create a list of wins of size "starting_population_size"
    for (int i = 0; i < starting_population_size; i++)
        
        wins.push_back(new win());
    
    //display starting population
    cout<<"Starting population of wins is: "<<endl;
    display_wins(wins);
    
    return wins;
}

//attempt to fight or mate wins in the list with one another
list<win*> interact_with_each_other(list<win*> wins){
    
    for (list<win *>::iterator list_position = wins.begin(); next(list_position) != wins.end(); list_position++)
    {
        win* current_win = (*list_position);
        win* next_win = (*next(list_position));
        
        if(current_win->alive())
        {
            current_win->grow_older();
            
            if (current_win->potential_mate(*next_win))
            {
                win* new_child = new win( mate(*current_win, *next_win) );
                wins.push_back(new_child);
            }
            else
                
                fight(*current_win, *next_win);
        }
    }
    
    return wins;
    
}

//predicate as function to be used in the "std::list<>.remove_if" call
bool is_dead(win* w1)
{
    return !w1->alive();
}


int main(){
    
    //seed a new time for random for all rand() calls that wins use
    srand(time(0));
    
    list<win *> wins = create_initial_population();
    
    for (int iterations = 0; iterations < total_iterations_to_simulate && wins.size() > 1; iterations++)
    {
        display_iteration_info(iterations, wins.size());
        
        //mate or fight the wins in the current iteration
        wins = interact_with_each_other(wins);
        
        
        //remove the dead and display
        wins.remove_if(is_dead);
        display_wins(wins);
        
    }
    
    cout<<"There is/are "<<wins.size()<<" survivor(s)."<<endl;
    cout<<"The survivors are: "<<endl;
    
    display_wins(wins);
    display_stats_labels();
    
    display_config_warning();
    
    return 0;
    
}
