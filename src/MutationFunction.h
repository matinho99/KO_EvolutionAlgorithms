/*
 * \class MutationFunction
 *
 * \brief Class that holds the mutation function parameter
 *
 * Class that holds the parameter describing the mutation function
 * and the methods for setting and returning it.
 *
 * Created on: 28.04.2018
 */

#ifndef MUTATIONFUNCTION_H_
#define MUTATIONFUNCTION_H_


class MutationFunction {
public:
	MutationFunction();
	MutationFunction(float m);
	float getMutator();
	void setMutator(float m);
private:
	float mutator;				///< Mutation parameter of the mutation function.
};


#endif /* MUTATIONFUNCTION_H_ */
