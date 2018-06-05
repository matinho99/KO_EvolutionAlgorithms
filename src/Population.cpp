#include "Population.h"

Population::Population() {}

Population::Population(const std::vector<Individual>& inds) : pop(inds) {}

void Population::addIndividual(const Individual& ind) {
	pop.push_back(ind);
}

std::vector<Individual>& Population::getIndividuals() {
	return pop;
}

void Population::setIndividuals(const std::vector<Individual>& inds) {
	pop = inds;
}

std::ostream& operator<<(std::ostream& os, const Population& p) {
	Population p_tmp = p;

	for(int i = 0; i < p_tmp.getIndividuals().size(); i++) {
		os << p_tmp.getIndividuals().at(i).getValue() << std::endl;
	}

	return os;
}
