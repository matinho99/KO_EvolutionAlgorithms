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

		for(Individual i : p.getPopulation()) {
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
		std::cout << "Pairs Evo" << std::endl;
		int popSize = p.getPopulation().size();
		int pairFoundMatrix[popSize][popSize] = { 0 };
		float tolerance = 0.0f;
		float target = ff->getTarget();
		int found = 0;
		Population newPop;

		while(found < popSize) {
			tolerance += 1.0f;

			for(int i = 0; i < popSize-1 && found < popSize; i++) {
				float iVal = p.getPopulation().at(i).getValue();

				for(int j = i+1; j < popSize && found < popSize; j++) {
					if(pairFoundMatrix[i][j] == 1) continue;

					float jVal = p.getPopulation().at(j).getValue();
					float newVal = (iVal+jVal)/2;
					float y = ff->calculateFitness(newVal);

					if(abs(y-target) < tolerance) {
						if(y < target) {

						} else {
							
						}

						Individual newInd(newVal);
						newPop.addIndividual(newInd);
						pairFoundMatrix[i][j] = 1;
						found++;
					}
				}
			}
		}

		return newPop;
	}
};

int main() {
	ExecClass e(5);
	StandardEvo se;
	e.setAlgorithm(&se);
	std::vector<float> num {1, 1, 1};
	std::vector<float> denom {2, 0, 0};
	FitnessFunction ff(num, denom, 10.0f);
	e.setFitnessFunction(&ff);
	MutationFunction mf(0.05f);
	e.setMutationFunction(&mf);
	e.showPopulationFitness();

	for(int i = 0; i < 20; i++) {
		e.generateNextPopulation();
		e.showPopulationFitness();
	}

	return 0;
}
