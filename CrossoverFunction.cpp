#include "CrossoverFunction.h"

MutationFunctio::MutationFunction() : crossFactor(0.0f) {}

float CrossoverFunction::getCrossFactor() {
	return crossFacto;
}

void CrossoverFunction::setCrossFactor(float cf) {
	crossFacto = cf;
}
