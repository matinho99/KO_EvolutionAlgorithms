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
#include <math.h>

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
		Population newPop;
		float target = ff->getTarget();
		float tolerance = 1.0f;
		float mut = mf->getMutator();
		std::cout << "Standard Evo -> target = " << target << std::endl;

		for(Individual i : p.getIndividuals()) {
			float iVal = i.getValue();
			float fitness = ff->calculateFitness(iVal);
			float y = ff->calculateFunctionValue(iVal);

			if(fitness < tolerance) {
				if(y < target) {
					iVal += iVal*mut;
				} else {
					iVal -= iVal*mut;
				}
			}

			Individual newInd(iVal);
			newPop.addIndividual(newInd);
		}

		return newPop;
	}
};

class PairsEvo : public EvoAlgorithm {
public:
	Population execAlgorithm(const Population& p, FitnessFunction *ff, MutationFunction *mf, CrossoverFunction *cf) {
		Population newPop;
		std::vector<Individual> newIndM;
		int popSize = p.getIndividuals().size();

		for(int i = 0; i < popSize-1; i++) {
			Individual iInd = p.getIndividuals().at(i);
			float iVal = iInd.getValue();
			
			for(int j = i+1; j < popSize; j++) {
				Individual jInd = p.getIndividuals().at(j);
				float jVal = jInd.getValue();
				Individual newInd;
				newInd.setValue((iVal+jVal)/2);
				newIndM.push_back(newInd);
			}
		}

		for(int i = newIndM.size(); i > 0; --i) {
			for(int j = 0; j < i-1; ++j) {
				if(ff->calculateFitness(newIndM[j].getValue()) < ff->calculateFitness(newIndM[j+1].getValue()))
					std::swap(newIndM[j], newIndM[j+1]);
			}
		}

		for(int i = 0; i < popSize; i++) {
			newPop.addIndividual(newIndM[i]);
		}

		return newPop;
	}
};

int main() {
	srand(time(NULL));
	ExecClass e(20);
	PairsEvo se;
	e.setAlgorithm(&se);
	FitnessFunction ff({1, 1, 1}, {2, 0, 0}, 10.0f);
	e.setFitnessFunction(&ff);
	MutationFunction mf(0.05f);
	e.setMutationFunction(&mf);
	e.showPopulationFitness();

	for(int i = 0; i < 5; i++) {
		std::cout << "Population nr. " << i+1 << std::endl;
		e.generateNextPopulation();
		e.showPopulationFitness();
	}

	FitnessFunction testFF;
	std::cout << testFF.calculateFunctionValue(2.0f) << std::endl;

	return 0;
}
