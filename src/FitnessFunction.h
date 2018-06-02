/*
 * \class FitnessFunction
 *
 * \brief Class that holds the fitness function and methods
 *
 * Class that holds the parameters describing the fitness function, the target,
 * the methods for setting / returning them and calculating the fitness.
 *
 * Created on: 28.04.2018
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
	float calculateFitness(float x);			///< Calculate fitness of x
	float calculateFunctionValue(float x);		///< Calculate the function value of x
private:
	std::vector<float> numeratorFactors;		///< Numerator factors of the fitness function in descending powers.
	std::vector<float> denominatorFactors;		///< Denominator factors of the fitness function in descending powers.
	float target;								///< Target value of the fitness function.
};


#endif /* FITNESSFUNCTION_H_ */
