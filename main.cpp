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
	void execAlgorithm() {
		std::cout << str << std::endl;
	}
private:
	std::string str;
};

class StandardEvo : public EvoAlgorithm {
public:
	void setFitnessFunction(FitnessFunction *f) {
		ff = f;
	}

	void setMutationFunction(MutationFunction *f) {
		mf = f;
	}

	void execAlgorithm() {
		std::cout << "Standard Evo" << std::endl;
	}
private:
	FitnessFunction *ff;
	MutationFunction *mf;
};

class PairsEvo : public EvoAlgorithm {
public:
	void setFitnessFunction(FitnessFunction *f) {
		ff = f;
	}

	void setMutationFunction(MutationFunction *f) {
		mf = f;
	}

	void setCrossoverFunction(CrossoverFunction *f) {
		cf = f;
	}

	void execAlgorithm() {
		std::cout << "Pairs Evo" << std::endl;
	}
private:
	FitnessFunction *ff;
	MutationFunction *mf;
	CrossoverFunction *cf;
};

int main() {
	ExecClass e(5);
	SpecAlg sa("Specific algorithm");
	e.setAlgorithm(&sa);
	e.generateNextPopulation();
	std::vector<float> num {1, 1, 1};
	std::vector<float> denom {2, 0, 0};
	FitnessFunction ff(num, denom, 50);
	e.setFitnessFunction(&ff);
	e.showPopulationFitness();
	return 0;
}
