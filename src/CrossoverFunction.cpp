#include "CrossoverFunction.h"

CrossoverFunction::CrossoverFunction() : crossFactor(0.0f) {}

CrossoverFunction::CrossoverFunction(float cf) : crossFactor(cf) {}

float CrossoverFunction::getCrossFactor() {
	return crossFactor;
}

void CrossoverFunction::setCrossFactor(float cf) {
	crossFactor = cf;
}
