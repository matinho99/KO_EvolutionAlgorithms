/*
 * @class ExecClass
 *
 * Created on: 28.04.2018
 */

#ifndef EXECCLASS_H_
#define EXECCLASS_H_

#include "Population.h"
#include "EvoAlgorithm.h"
#include "FitnessFunction.h"
#include "MutationFunction.h"
#include "CrossoverFunction.h"

/**
 * @brief Class that holds the executing algorithm and its key elements.
 *
 * Class that holds the EvoAlgorithm specific algorithm as well as
 * mutation, crossover, fitness functions and population.
 */
class ExecClass {
public:
	ExecClass();
	ExecClass(const Population& p, const FitnessFunction& fitF, const MutationFunction& mutF, const CrossoverFunction& crF, EvoAlgorithm *ea);
	~ExecClass();
	Population& getPopulation();								///< Get the population.
	void setPopulation(const Population& p);					///< Set the population.
	FitnessFunction& getFitnessFunction();						///< Get the fitness function.
	void setFitnessFunction(const FitnessFunction& f);			///< Set the fitness function.
	MutationFunction& getMutationFunction();					///< Get the mutation function.
	void setMutationFunction(const MutationFunction& f);		///< Set the mutation function.
	CrossoverFunction& getCrossoverFunction();					///< Get the crossover function.
	void setCrossoverFunction(const CrossoverFunction& f);		///< Set the crossover function.
	EvoAlgorithm* getAlgorithm();								///< Get the algorithm.
	void setAlgorithm(EvoAlgorithm* ea);						///< Set the algorithm for further operations.
	void generateNextPopulation();								///< Execute the execAlgorithm function of the alg algorithm.
	void showPopulationFitness();								///< Write out the values and fitness values of the population.
private:
	Population pop;
	FitnessFunction ff;
	MutationFunction mf;
	CrossoverFunction cf;
	EvoAlgorithm* alg;
};


#endif /* EXECCLASS_H_ */
