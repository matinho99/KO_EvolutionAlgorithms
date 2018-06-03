#include "Population.h"

Population::Population() {}

void Population::addIndividual(const Individual &ind) {
	pop.push_back(ind);
}

std::vector<Individual> Population::getIndividuals() const {
	return pop;
}

std::ostream& operator<<(std::ostream& os, const Population& p) {
	for(int i = 0; i < p.getIndividuals().size(); i++) {
		os << p.getIndividuals().at(i).getValue() << std::endl;
	}

	return os;
}
