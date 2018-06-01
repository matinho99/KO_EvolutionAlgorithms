/*
 * Algorithm.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
 */

#ifndef EVOALGORITHM_H_
#define EVOALGORITHM_H_


class EvoAlgorithm {
public:
	virtual ~EvoAlgorithm() {}
	//void setFitnessFunction(FitnessFunction *f);
	virtual void execAlgorithm() {}
};


#endif /* EVOALGORITHM_H_ */
