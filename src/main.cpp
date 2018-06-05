/*
 * Created on: 28.04.2018
 */

#include "ExecClass.h"
#include "EvoAlgorithm.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "ui.h"

class StandardEvo : public EvoAlgorithm {
public:
	StandardEvo() {}
	~StandardEvo() {}

	Population execAlgorithm(Population& p, FitnessFunction& ff, MutationFunction& mf, CrossoverFunction& cf) {
		Population newPop;
		float target = ff.getTarget();
		float tolerance = 1.0f;
		float mut = mf.getMutator();

		for(Individual i : p.getIndividuals()) {
			float iVal = i.getValue();
			float fitness = ff.calculateFitness(iVal);
			float y = ff.calculateFunctionValue(iVal);

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
	PairsEvo() {};
	~PairsEvo() {};

	Population execAlgorithm(Population& p, FitnessFunction& ff, MutationFunction& mf, CrossoverFunction& cf) {
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
				if(ff.calculateFitness(newIndM[j].getValue()) < ff.calculateFitness(newIndM[j+1].getValue()))
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
	ExecClass e;
	e.setAlgorithm(new StandardEvo());
	e.setFitnessFunction(FitnessFunction());
	e.setMutationFunction(MutationFunction());
	e.setCrossoverFunction(CrossoverFunction());	//
	ui(e);
	return 0;
}
