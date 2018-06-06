/*
 * @class FitnessFunction
 *
 * Created on: 28.04.2018
 */

#ifndef FITNESSFUNCTION_H_
#define FITNESSFUNCTION_H_

#include <vector>
#include <math.h>
#include "EvoException.h"

/**
 * @brief Class that holds the fitness function and methods
 *
 * Class that holds the parameters describing the fitness function, the target,
 * the methods for setting as well as returning them and calculating the fitness.
 */
class FitnessFunction {
public:
	FitnessFunction();
	FitnessFunction(const std::vector<float>& numFact, const std::vector<float>& denomFact, float t);
	std::vector<float>& getNumeratorFactors();							///< Get the factors of the function numerator.
	void setNumeratorFactors(const std::vector<float>& numFact);		///< Set the factors of the function numerator.
	std::vector<float>& getDenominatorFactors();						///< Get the factors of the function denominator.
	void setDenominatorFactors(const std::vector<float>& denomFact);	///< Set the factors of the function denominator.
	float getTarget();							///< Get the target of the function.
	void setTarget(float t);					///< Set the target of the function.
	float calculateFitness(float x);			///< Calculate fitness of x.
	float calculateFunctionValue(float x);		///< Calculate the function value of x.
private:
	std::vector<float> numeratorFactors;
	std::vector<float> denominatorFactors;
	float target;
};


#endif /* FITNESSFUNCTION_H_ */
