#include "MutationFunction.h"

MutationFunction::MutationFunction() : mutator(0.0f) {}

MutationFunction::MutationFunction(float m) : mutator(m) {}

float MutationFunction::getMutator() {
	return mutator;
}

void MutationFunction::setMutator(float m) {
	mutator = m;
}
