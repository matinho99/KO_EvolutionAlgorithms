/*
 * \class Population
 *
 * \brief Class that holds the population of the algorithm.
 *
 * Class that holds the vector of the individuals in the population
 * and methods for adding, returning members and writing out the members.
 *
 * Created on: 28.04.2018
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <vector>
#include "Individual.h"
#include <iostream>

class Population {
public:
	Population();
	Population(const std::vector<Individual>& inds);
	Population(int popSize, int range);
	void addIndividual(const Individual& ind);
	std::vector<Individual>& getIndividuals();
	void setIndividuals(const std::vector<Individual>& inds);
private:
	std::vector<Individual> pop;			///< Vector of the individuals in the population.
};


#endif /* POPULATION_H_ */
