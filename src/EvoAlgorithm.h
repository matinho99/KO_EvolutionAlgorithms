/*
 * \class EvoAlgorithm
 *
 * \brief Base class for specific algorithm class implementation.
 *
 * Class that is inherited to a specific evolutionary algorithm class.
 *
 * Created on: 28.04.2018
 */

#ifndef EVOALGORITHM_H_
#define EVOALGORITHM_H_

#include "Population.h"
#include "FitnessFunction.h"
#include "MutationFunction.h"
#include "CrossoverFunction.h"

class EvoAlgorithm {
public:
	virtual ~EvoAlgorithm() {}
	virtual Population execAlgorithm(const Population& p, FitnessFunction *ff, MutationFunction *mf, CrossoverFunction *cf) {}		///< Function responsible for executing the algorithm code.
};


#endif /* EVOALGORITHM_H_ */
