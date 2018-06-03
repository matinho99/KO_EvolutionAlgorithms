/*
 * Created on: 28.04.2018
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
	int choice;
	int n = 5;
	int popno = 0;

	ExecClass e(20);
	PairsEvo se;
	e.setAlgorithm(&se);
	FitnessFunction ff({1, 1, 1}, {2, 0, 0}, 10.0f);
	e.setFitnessFunction(&ff);
	MutationFunction mf(0.05f);
	e.setMutationFunction(&mf);
	CrossoverFunction cf(0.5f);	//
	e.setCrossoverFunction(&cf);	//
	std::cout << "Populacja numer: " << popno << std::endl;
	e.showPopulationFitness();

	while(1) {
		std::cout << "Opcje:\n";
		std::cout << "1: Wygeneruj kolejna populacje\n";
		std::cout << "2: Wygeneruj kolejne N populacji\n";
		std::cout << "3: Zmien parametr mutacji\n";
		std::cout << "4: Zmien parametr krzyzowania\n";
		std::cout << "0: Zamknij program\n";
		std::cout << "\nWybor: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch(choice) {
			case 1:
				std::cout << "Populacja numer: " << ++popno << std::endl;
				e.generateNextPopulation();
				e.showPopulationFitness();
				break;
			case 2:
				std::cout << "N = ";
				std::cin >> n;
				std::cout << std::endl;
				if(n > 0) {
					for(int i = 0; i < n; ++i) {
						std::cout << "Populacja numer: " << ++popno << std::endl;
						e.generateNextPopulation();
						e.showPopulationFitness();
					}
				} else {
					std::cout << "N musi byc wieksze od 0\n";
				}
				break;
			case 3:
				float cmf;
				std::cout << "Parametr mutacji = ";
				std::cin >> cmf;
				mf.setMutator(cmf);
				break;
			case 4:
				float ccf;
				std::cout << "Parametr krzyzowania = ";
				std::cin >> ccf;
				cf.setCrossFactor(ccf);
				break;
			case 0:
				return 0;
			default:
				std::cout << "Zla opcja\n";
				break;
		}
	}
//	FitnessFunction testFF;
//	std::cout << testFF.calculateFunctionValue(2.0f) << std::endl;

	return 0;
}
