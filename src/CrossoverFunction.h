/*
 * \class CrossoverFunction
 *
 * \brief Class that holds the parameter for the crossover function
 *
 * Class that holds the parameter for the crossover function along with
 * the methods for setting and returning the variable.
 *
 * Created on: 28.04.2018
 */

#ifndef CROSSOVERFUNCTION_H_
#define CROSSOVERFUNCTION_H_


class CrossoverFunction {
public:
	CrossoverFunction();
	CrossoverFunction(float cf);
	float getCrossFactor();
	void setCrossFactor(float cf);
private:
	float crossFactor;			///< The crossover function parameter
};


#endif /* CROSSOVERFUNCTION_H_ */
