/*
 * CrossoverFunction.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
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
	float crossFactor;
};


#endif /* CROSSOVERFUNCTION_H_ */