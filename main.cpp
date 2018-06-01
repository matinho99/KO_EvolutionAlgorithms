/*
 * main.cpp
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
 */

#include "ExecClass.h"
#include "EvoAlgorithm.h"
#include <stdlib.h>
#include <iostream>

class SpecAlg : public EvoAlgorithm {
public:
	SpecAlg(std::string s) : str(s) {}
	~SpecAlg() {}
	Population execAlgorithm(const Population& p, FitnessFunction *ff, MutationFunction *mf, CrossoverFunction *cf) {
		std::cout << str << std::endl;
	}
private:
	std::string str;
};

class StandardEvo : public EvoAlgorithm {
public:
	StandardEvo() {}
	~StandardEvo() {}

	Population execAlgorithm(const Population& p, FitnessFunction *ff, MutationFunction *mf, CrossoverFunction *cf) {
		std::cout << "Standard Evo" << std::endl;
		Population newPop;
		float mut = mf->getMutator();
		std::cout << mut << std::endl;

		for(Individual i : p.getPopulation()) {
			float y = ff->calculateValue(i.getValue());
			float iVal = i.getValue();
			Individual newInd;

			if(y < ff->getTarget()) {
				newInd.setValue(iVal+iVal*mut);
			} else {
				newInd.setValue(iVal-iVal*mut);
			}

			newPop.addIndividual(newInd);
		}

		return newPop;
	}
};

class PairsEvo : public EvoAlgorithm {
public:
	Population execAlgorithm(const Population& p, FitnessFunction *ff, MutationFunction *mf, CrossoverFunction *cf) {
		std::cout << "Pairs Evo" << std::endl;
	}
};

int main() {
	ExecClass e(5);
	StandardEvo se;
	e.setAlgorithm(&se);
	std::vector<float> num {1, 1, 1};
	std::vector<float> denom {2, 0, 0};
	FitnessFunction ff(num, denom, 10);
	e.setFitnessFunction(&ff);
	MutationFunction mf(0.05f);
	e.setMutationFunction(&mf);
	e.showPopulationFitness();

	for(int i = 0; i < 100; i++) {
		e.generateNextPopulation();
		e.showPopulationFitness();
	}
	return 0;
}
