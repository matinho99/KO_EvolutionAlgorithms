/*
 * @class MutationFunction
 *
 * Created on: 28.04.2018
 */

#ifndef MUTATIONFUNCTION_H_
#define MUTATIONFUNCTION_H_

/**
 * @brief Class that holds the mutation function parameter
 *
 * Class that holds the parameter describing the mutation function
 * and the methods for setting and returning it.
 */
class MutationFunction {
public:
	MutationFunction();
	MutationFunction(float m);
	float getMutator();				///< Get the mutation parameter.
	void setMutator(float m);		///< Set the mutation parameter.
private:
	float mutator;
};


#endif /* MUTATIONFUNCTION_H_ */
