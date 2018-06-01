#include "Population.h"

Population::Population() {}

void Population::addIndividual(const Individual &ind) {
	pop.push_back(ind);
}

std::vector<Individual> Population::getPopulation() const {
	return pop;
}

std::ostream& operator<<(std::ostream& os, const Population& p) {
	for(int i = 0; i < p.getPopulation().size(); i++) {
		os << p.getPopulation().at(i).getValue() << std::endl;
	}

	return os;
}
