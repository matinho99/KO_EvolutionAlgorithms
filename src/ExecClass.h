/*
 * \class ExecClass
 *
 * \brief Class that holds the executing algorithm and its key elements.
 *
 * Class that holds the EvoAlgorithm specific algorithm as well as
 * mutation, crossover, fitness functions and population.
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

class ExecClass {
public:
	ExecClass();
	ExecClass(const Population& p, const FitnessFunction& fitF, const MutationFunction& mutF, const CrossoverFunction& crF, EvoAlgorithm *ea);
	~ExecClass();
	Population& getPopulation();
	void setPopulation(const Population& p);
	FitnessFunction& getFitnessFunction();
	void setFitnessFunction(const FitnessFunction& f);
	MutationFunction& getMutationFunction();
	void setMutationFunction(const MutationFunction& f);
	CrossoverFunction& getCrossoverFunction();
	void setCrossoverFunction(const CrossoverFunction& f);
	EvoAlgorithm* getAlgorithm();
	void setAlgorithm(EvoAlgorithm* ea);
	void generateNextPopulation();	///< Executes the execAlgorithm function of the alg algorithm.
	void showPopulationFitness();	///< Writes out the values and fitness values of the population.
private:
	Population pop;				///< The population the algorithm operates on.
	FitnessFunction ff;			///< The fitness function the algorithm uses.
	MutationFunction mf;			///< The mutation function for algorithm use.
	CrossoverFunction cf;			///< The crossover Function for algorithm use.
	EvoAlgorithm* alg;			///< The specific algorithm the program executes.
};


#endif /* EXECCLASS_H_ */
