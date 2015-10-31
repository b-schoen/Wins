#ifndef WIN_H
#define WIN_H

#include <iostream>

using namespace std;


const int youngest_mating_age = 3;            //youngest age before different genders will view each other as potential mates
const int max_life_expectancy = 10;           //maximum number of years (iterations) a win can live through

const int fight_threshold = 5;                //threshold combativeness must exceed before a win chooses to fight
const int trait_range = 10;                   //maximum value any given trait can have
const int mutation_range = 3;                 //degree to which a trait can change from a single mutation

//following odds calculated as "X-1 in X chance" of outcome occuring (ex: 10 => 9 in 10 chance of outcome)
const int gender_bias = 2;                    //likelihood child inherets the 'A' gender when mating
const int ease_of_childbirth = 10;            //likelihood of living through childbirth
const int gene_stability = 5;                 //likelihood that child will not have a mutatation during conception

class win {

	public:
    
        //constructors
		win();
		win(int strength,
            int speed,
            char gender,
            int combativeness,
            int mating_selectivity_strength,
            int mating_selectivity_speed);
		win(const win& w);

		friend ostream& operator<<(ostream& os, win& w);

		friend win mate(win& w1, win& w2);
		friend bool fight(win& w1, win& w2);

		bool potential_mate(win& w2);
		bool attack(win& w2);
    
        bool alive();
        bool grow_older();

	private:

		bool isAlive;
    
        int age;

		//physique
		int strength;
		int speed;
		char gender;

		//personality
		int combativeness;      //propensity to fight with respect to other win's strength
		int mating_selectivity_strength;  //acceptable deviation from own strength in potential mate
		int mating_selectivity_speed;  //acceptable deviation from own speed in potential mate

};




#endif