/*
 * Individual.h
 *
 *  Created on: 28.04.2018
 *      Author: matinho1706
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_


class Individual {
public:
	Individual();
	Individual(float v);
	float getValue();
	void setValue(float v);
private:
	float value;
};


#endif /* INDIVIDUAL_H_ */
