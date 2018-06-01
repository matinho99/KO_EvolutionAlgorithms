#include "MutationFunction.h"

MutationFunctio::MutationFunction() : mutator(0.0f) {}

float MutationFunction::getMutator() {
	return mutator;
}

void MutationFunction::setMutator(float m) {
	mutator = m;
}
