/*
 * MutationFunction.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
 */

#ifndef MUTATIONFUNCTION_H_
#define MUTATIONFUNCTION_H_


class MutationFunction {
public:
	MutationFunction() : mutator(0.0f) {}
	float getMutator();
	void setMutator(float m);
private:
	float mutator;
};


#endif /* MUTATIONFUNCTION_H_ */
