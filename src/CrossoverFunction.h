/*
 * @class CrossoverFunction
 *
 * Created on: 28.04.2018
 */

#ifndef CROSSOVERFUNCTION_H_
#define CROSSOVERFUNCTION_H_

/**
 * @brief Class that holds the parameter for the crossover function
 *
 * Class that holds the parameter for the crossover function along with
 * the methods for setting and returning the variable.
 */
class CrossoverFunction {
public:
	CrossoverFunction();
	CrossoverFunction(float cf);
	float getCrossFactor();				///< Get the crossFactor
	void setCrossFactor(float cf);		///< Set the crossFactor
private:
	float crossFactor;
};


#endif /* CROSSOVERFUNCTION_H_ */
