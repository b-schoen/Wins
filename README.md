# Wins
Simulate the evolution of little complex creatures called "Wins" over many generations.

Individual Wins:

Wins have a physique (strength, speed, gender), and a personality (combativeness, mating_selectivity_strength, mating_selectivity_speed). Their personality determines how they interact with others, and their physique determines how others choose to interact with them.

Interacting:

Wins are complex but brutal creatures. If they encounter one another, they will attempt to mate if they can, and fight if they can't. Details of these functions and their relationship to personality/physique is made clear in the comments for the ‘mate’ and ‘fight’ functions defined in “Win.cpp”.

Environmental Factors (Initial Conditions):

There are a few factors that can be tweaked for the species as a whole. These are located in "Win.h". For example, 'youngest_mating_age' or 'gene_stability'.