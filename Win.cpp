#include "Win.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;


win::win(){

	isAlive = true;
    age = 0;

	//construct physique
	strength = (rand() % trait_range) + 1;
	speed = (rand() % trait_range) + 1;
    
    //determine gender
	if (rand() % gender_bias == 0)
		gender = 'A';
	else
		gender = 'B';

	//construct personality
	combativeness = (rand() % trait_range) + 1;
	mating_selectivity_speed = (rand() % trait_range) + 1;
	mating_selectivity_strength = (rand() % trait_range) + 1;

}

//initialize everything as the given variables then set isAlive to true and age to 0
win::win(int strength,
         int speed,
         char gender,
         int combativeness,
         int mating_selectivity_strength,
         int mating_selectivity_speed) :
            strength(strength),
            speed(speed),
            gender(gender),
            combativeness(combativeness),
            mating_selectivity_strength(mating_selectivity_strength),
            mating_selectivity_speed(mating_selectivity_speed)
{
	isAlive = true;
    age = 0;

}

//copy all values to make a new win
win::win(const win& w){

	isAlive = w.isAlive;
    age = w.age;
	strength = w.strength;
	speed = w.speed;
	gender = w.gender;
	combativeness = w.combativeness;
	mating_selectivity_strength = w.mating_selectivity_strength;
	mating_selectivity_speed = w.mating_selectivity_speed;

}

ostream& operator<<(ostream& os, win& w){
    int set_w_constant = 13;
	os <<right
    << setw(set_w_constant) << w.isAlive
    << setw(set_w_constant) << w.age
    << setw(set_w_constant) << w.strength
    << setw(set_w_constant) << w.speed
    << setw(set_w_constant) << w.gender
    << setw(set_w_constant) << w.combativeness
    << setw(set_w_constant) << w.mating_selectivity_strength
    << setw(set_w_constant) << w.mating_selectivity_speed
    << setw(set_w_constant) << "\n";
	return os;
}

//mates two wins and returns their child
win mate(win& w1, win& w2){

	int mutation;

	//gene stability determines chance that child receives a mutation
	if (rand() % gene_stability == 0)
		mutation = rand() % mutation_range;
	else
		mutation = 0;

	//child's physiology is average of parents
	int child_strength=(w1.strength + w2.strength) / 2 + mutation;
	int child_speed = (w1.speed + w2.speed) / 2 + mutation;
	
	//child's gender is random with ' % gender_bias' odds for either parent's gender
	char child_gender;
	if (rand() % gender_bias == 0)
		child_gender = w1.gender;
	else
		child_gender = w2.gender;
	
	//child's personality is average of parents
	int child_combativeness = (w1.combativeness + w2.combativeness) / 2 + mutation;
	int child_mate_selectivity_strength = (w1.mating_selectivity_strength + w2.mating_selectivity_strength) / 2 + mutation;
	int child_mate_selectivity_speed = (w1.mating_selectivity_speed + w2.mating_selectivity_speed) / 2 + mutation;

	//make child with constructed traits
	win child(child_strength,
              child_speed,
              child_gender,
              child_combativeness,
              child_mate_selectivity_strength,
              child_mate_selectivity_speed);

	//one of them can randomly die in mating/childbirth
	if ((rand() % ease_of_childbirth) == 0)
		w1.isAlive = false;

	return child;
}

//starts a fight between the two wins
bool fight(win& w1, win& w2){
    
    //wins will fight when their combativeness is above the fight threshold
    //  wins will attempt to run otherwise
    //      if the win that chose to fight is faster, he attacks

	//case where both want to fight
	if (w1.combativeness >= fight_threshold && w2.combativeness >= fight_threshold)
	{
		w1.attack(w2);
		return true;
	}
		

	//case where w1 wants to run but w2 wants to fight
	if (w1.combativeness < fight_threshold && w2.combativeness >= fight_threshold)
		if (w1.speed <= w2.speed)
		{ 
			w2.attack(w1);
			return true;
		}
			

	//case where w1 wants to fight but w1 wants to run
	if (w1.combativeness >= fight_threshold && w2.combativeness < fight_threshold)
		if (w1.speed > w2.speed)
		{
			w1.attack(w2);
			return true;
		}
			

	//if neither wants to fight, both run (thus nothing happens)
    //or if one outran another
	return false;

}

//returns a boolean for whether we can mate with the passed in win
bool win::potential_mate(win& w2){
    
    //if either is too young to mate
    if(age < youngest_mating_age || w2.age < youngest_mating_age)
        return false;

	//don't mate with it if it's dead...
	if (!w2.isAlive)
		return false;

    //if the mate is the same gender, and satisfies this wins selectivity for all traits
	if (gender == w2.gender)
		if (w2.strength >= mating_selectivity_strength && w2.speed >= mating_selectivity_speed)
			return true;
	else
		return false;
    
    //just in case we reach the end of this control path without returning
    return false;
}

//returns a boolean for whether we're alive or dead at the end of the fight
bool win::attack(win& w2){

	//if we're dead we lost
	if (!isAlive)
		return false;

	//if they're dead they lost
	if (!w2.isAlive)
		return true;

	//the strongest kills the weakest

	if (strength > w2.strength)
	{
		//cout << '\a';           beep upon death
		w2.isAlive = false;
		return true;
	}
		
		
	if (strength < w2.strength)
	{
		//cout << '\a';           beep upon death
		isAlive = false;
		return false;
	}

	//if they are equal in strength, they kill each other

	if (strength == w2.strength)
	{
		//cout << '\a' << '\a';   beep upon death
		isAlive = false;
		w2.isAlive = false;
		return false;
	}

	//just in case we reach the end of this control path without returning
	return false;
}

//check whether win is alive
bool win::alive(){
    return isAlive;
}

bool win::grow_older(){
    
    age++;
    
    if(age>max_life_expectancy)
        isAlive=false;
    
    return true;
}


