#include "Individual.h"

Individual::Individual() : value(0.0f) {}

Individual::Individual(float v) : value(v) {}

float Individual::getValue() {
	return value;
}

void Individual::setValue(float v) {
	value = v;
}


