/*
 * @class Population
 *
 * Created on: 28.04.2018
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <vector>
#include <math.h>
#include <iostream>
#include "Individual.h"

/**
 * @brief Class that holds the population of the algorithm.
 *
 * Class that holds the vector of the individuals in the population
 * and methods for adding, returning members and writing out the members.
 */
class Population {
public:
	Population();
	Population(const std::vector<Individual>& inds);
	Population(int popSize, int range);
	void addIndividual(const Individual& ind);						///< Add individual to the population.
	std::vector<Individual>& getIndividuals();						///< Get the vector of the individuals in the population.
	void setIndividuals(const std::vector<Individual>& inds);		///< Set the values of the individuals in the population.
private:
	std::vector<Individual> pop;
};


#endif /* POPULATION_H_ */
