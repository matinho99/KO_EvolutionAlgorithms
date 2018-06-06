#include "ExecClass.h"

ExecClass::ExecClass() {
	alg = nullptr;
}

ExecClass::ExecClass(const Population& p, const FitnessFunction& fitF, const MutationFunction& mutF, const CrossoverFunction& crF, EvoAlgorithm *ea)
	: pop(p), ff(fitF), mf(mutF), cf(crF), alg(ea) {}

ExecClass::~ExecClass() {}

Population& ExecClass::getPopulation() {
	return pop;
}

FitnessFunction& ExecClass::getFitnessFunction() {
	return ff;
}

MutationFunction& ExecClass::getMutationFunction() {
	return mf;
}

CrossoverFunction& ExecClass::getCrossoverFunction() {
	return cf;
}

EvoAlgorithm* ExecClass::getAlgorithm() {
	return alg;
}

void ExecClass::setPopulation(const Population& p) {
	pop = p;
}

void ExecClass::setFitnessFunction(const FitnessFunction& f) {
	ff = f;
}

void ExecClass::setMutationFunction(const MutationFunction& f) {
	mf = f;
}

void ExecClass::setCrossoverFunction(const CrossoverFunction& f) {
	cf = f;
}

void ExecClass::setAlgorithm(EvoAlgorithm* ea) {
	alg = ea;
}

/**
 * @throws EvoNullPointerException if the algorithm is a nullptr.
 */
void ExecClass::generateNextPopulation() {
	if(alg == nullptr) throw EvoNullPointerException();
	pop = alg->execAlgorithm(pop, ff, mf, cf);
}

void ExecClass::showPopulationFitness() {
	for(Individual i : pop.getIndividuals()) {
		std::cout << i.getValue() << " - fitness = " << ff.calculateFitness(i.getValue()) << " - wartosc funkcji = " << ff.calculateFunctionValue(i.getValue()) << std::endl;
	}
}
