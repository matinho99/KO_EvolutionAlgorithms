/*
 * Algorithm.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
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
	virtual Population execAlgorithm(const Population& p, FitnessFunction *ff, MutationFunction *mf, CrossoverFunction *cf) {}
};


#endif /* EVOALGORITHM_H_ */
