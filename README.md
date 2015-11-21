# Wins #
Simulate the evolution of little complex creatures called "Wins" over many generations.

### Individual Wins: ###

Wins have a physical and mental characteristics:

    physique                    personality
        strength                    combativeness
        speed                       mating_selectivity_strength
        gender                      mating_selectivity_speed

Their personality determines how they interact with others and their physique determines how others choose to interact with them.

### Interacting: ###

When Wins run into each other, they will either attempt to fight or mate. 

* **Fighting:**
  * ***Combativeness***: How likely a Win will choose to fight vs run
  * ***Speed***: How successful a Win is at running away
  * ***Strength***: How successful a Win is at fighting
* **Mating:**
  * ***Gender***: Wins will only mate with Wins of other genders
  * ***Mating_Selectivity_Strength***: Wins will only mate with Wins with a higher strength than their selectivity
  * ***Mating_Selectivitiy_Speed***: Wins will only mate with Wins with a higher speed than their selectivity

Further details of these functions and their relationship to personality/physique is made clear in the comments for the ‘mate’ and ‘fight’ functions defined in “Win.cpp”.

### Environmental and Species Wide Factors: ###

There are a few factors that can be tweaked for the species as a whole. 

* **Thresholds:**
  * ***Youngest_Mating_Age***: Youngest age before different genders will view each other as potential mates
  * ***Max_Life_Expectancy***: Maximum number of years (iterations) a Win can live through
  * ***Fight_Threshold:*** Threshold combativeness must exceed before a win chooses to fight
* **Ranges:**
  * ***Trait_Range:*** Maximum value any given trait can have
  * ***Mutation_Range:*** Degree to which a trait can change from a single mutation

NOTE: Following odds calculated as "X-1 in X chance" of outcome occuring (ex: 10 => 9 in 10 chance of outcome)
* **Randomness:**
  * ***Gender_Bias:*** Likelihood child inherets the 'A' gender when mating
  * ***Ease_Of_Childbirth:*** Likelihood of living through childbirth
  * ***Gene_Stability:*** Likelihood that child will not have a mutatation during conception

These are located in "Win.h".