#include "Population.h"

Population::Population() {}

Population::Population(const std::vector<Individual>& inds) : pop(inds) {}

Population::Population(int popSize, int range) {
	for(int i = 0; i < popSize; ++i) {
		float val = pow(-1, rand()%2)*(rand() % range + (float)rand()/RAND_MAX);
		pop.push_back(Individual(val));
	}
}

void Population::addIndividual(const Individual& ind) {
	pop.push_back(ind);
}

std::vector<Individual>& Population::getIndividuals() {
	return pop;
}

void Population::setIndividuals(const std::vector<Individual>& inds) {
	pop = inds;
}

