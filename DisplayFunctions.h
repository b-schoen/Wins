//
//  DisplayFunctions.h
//  work_win_go
//
//  Created by Bronson Schoen on 10/30/15.
//  Copyright © 2015 Bronson Schoen. All rights reserved.
//

#ifndef DisplayFunctions_h
#define DisplayFunctions_h

#include <stdio.h>
#include <list>
#include <iomanip>
#include "Win.h"

void display_wins(list<win*> wins)
{
    for (list<win *>::iterator list_position = wins.begin(); list_position != wins.end(); list_position++)
    {
        cout<<*(*list_position);
    }
}

void display_iteration_info(int iteration, int population_size)
{
    string visual_divider = "--------------------------- New Iteration ------------------------------------";
    
    cout << visual_divider << endl;
    
    cout << "Current iteration is: "<<iteration<<endl;
    cout<<"Current population size is: "<<population_size<<endl;
}

void display_stats_labels(){
    
    int setw_constant = 13;
    
    cout<<right
        <<setw(setw_constant)<<" Alive^"
        <<setw(setw_constant)<<" Age^"
        <<setw(setw_constant)<<" Strength^"
        <<setw(setw_constant)<<" Speed^"
        <<setw(setw_constant)<<" Gender^"
        <<setw(setw_constant)<<" Combative^"
        <<setw(setw_constant)<<" MS_Strength^"
        <<setw(setw_constant)<<" MS_Speed^"
    <<endl;

}

void display_config_warning(){
    cout<<"Please widen console window if numbers look jumbled together"<<endl;
}


#endif /* DisplayFunctions_h */
