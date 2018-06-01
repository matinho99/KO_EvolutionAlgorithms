/*
 * ExecClass.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
 */

#ifndef EXECCLASS_H_
#define EXECCLASS_H_

#include "Population.h"
#include "EvoAlgorithm.h"
#include "FitnessFunction.h"
#include "MutationFunction.h"
#include "CrossoverFunction.h"

class ExecClass {
public:
	ExecClass();
	ExecClass(int popSize);
	~ExecClass();
	FitnessFunction *getFitnessFunction();
	void setFitnessFunction(FitnessFunction *f);
	MutationFunction *getMutationFunction();
	void setMutationFunction(MutationFunction *f);
	CrossoverFunction *getCrossoverFunction();
	void setCrossoverFunction(CrossoverFunction *f);
	void setAlgorithm(EvoAlgorithm *ea);
	void generateNextPopulation();
	void showPopulationFitness();
private:
	Population pop;
	FitnessFunction *ff;
	MutationFunction *mf;
	CrossoverFunction *cf;
	EvoAlgorithm *alg;
};


#endif /* EXECCLASS_H_ */
