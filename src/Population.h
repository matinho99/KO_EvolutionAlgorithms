/*
 * Population.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <vector>
#include "Individual.h"
#include <iostream>

class Population {
public:
	Population();
	void addIndividual(const Individual &ind);
	std::vector<Individual> getPopulation() const;
	friend std::ostream& operator<<(std::ostream& os, const Population& p);
private:
	std::vector<Individual> pop;
};


#endif /* POPULATION_H_ */
