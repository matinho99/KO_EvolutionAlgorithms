/*
 * FitnessFunction.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
 */

#ifndef FITNESSFUNCTION_H_
#define FITNESSFUNCTION_H_

#include <vector>
#include <math.h>

class FitnessFunction {
public:
	FitnessFunction();
	FitnessFunction(std::vector<float> numFact, std::vector<float> denomFact, float t);
	std::vector<float> getNumeratorFactors();
	void setNumeratorFactors(std::vector<float> numFact);
	std::vector<float> getDenominatorFactors();
	void setDenominatorFactors(std::vector<float> denomFact);
	float getTarget();
	void setTarget(float t);
	float calculateValue(float x);
private:
	std::vector<float> numeratorFactors;
	std::vector<float> denominatorFactors;
	float target;
};


#endif /* FITNESSFUNCTION_H_ */
