#include "EvoAlgorithm.h"
#include "ExecClass.h"

#include <cstdint>
#include <string>

#include "boost/test/unit_test.hpp"

class TestEvoAlg : public EvoAlgorithm {
public:
	TestEvoAlg() {}
	~TestEvoAlg() {}

	Population execAlgorithm(Population& p, FitnessFunction& ff, MutationFunction& mf, CrossoverFunction& cf) {
		Population newPop;
		newPop.addIndividual(p.getIndividuals().front());
		return newPop;
	}
};

BOOST_AUTO_TEST_SUITE(EvoTests)

BOOST_AUTO_TEST_CASE(GivenOneThingAnotherThingHappens)  // proof that Boost tests work
{
	BOOST_CHECK_EQUAL(2+2,4);
}

/* Individual class testing */
BOOST_AUTO_TEST_CASE(WhenIndividualDefaultConstructThenValueIsZero) {
	Individual ind;
	BOOST_CHECK_EQUAL(0.0f, ind.getValue());
}

BOOST_AUTO_TEST_CASE(WhenIndividualConstructWithValueThenValueIsCorrect) {
	Individual ind(10.0f);
	BOOST_CHECK_EQUAL(10.0f, ind.getValue());
}

BOOST_AUTO_TEST_CASE(WhenSettingIndividualValueThenValueIsCorrect) {
	Individual ind;
	ind.setValue(5.0f);
	BOOST_CHECK_EQUAL(5.0f, ind.getValue());
}

/* Population class testing */
BOOST_AUTO_TEST_CASE(WhenPopulationDefualtConstructThenItIsEmpty) {
	Population pop;
	BOOST_CHECK_EQUAL(true, pop.getIndividuals().empty());
}

BOOST_AUTO_TEST_CASE(WhenAddingOneIndividualToPopulationThenItIsNotEmpty) {
	Population pop;
	Individual ind;
	pop.addIndividual(ind);
	BOOST_CHECK_EQUAL(false, pop.getIndividuals().empty());
}

BOOST_AUTO_TEST_CASE(WhenTwoIndividualsAddedToPopulationThenLastOnesValueIsCorrect) {
	Population p;
	Individual ind1(4.0f);
	Individual ind2(6.0f);
	p.addIndividual(ind1);
	p.addIndividual(ind2);
	float checkVal = p.getIndividuals().back().getValue();
	BOOST_CHECK_EQUAL(6.0f, checkVal);
}

/* FitnessFunction class testing */
BOOST_AUTO_TEST_CASE(WhenFitnessFunctionDefualtConstructThenNumeratorIsEmptyAndDenominatorIsEmptyAndTargetIsZero) {
	FitnessFunction ff;
	BOOST_CHECK_EQUAL(true, ff.getNumeratorFactors().empty());
	BOOST_CHECK_EQUAL(true, ff.getDenominatorFactors().empty());
	BOOST_CHECK_EQUAL(0.0f, ff.getTarget());
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionDefaultConstructThenFunctionValueThrows) {
	FitnessFunction ff;
	BOOST_CHECK_THROW(ff.calculateFunctionValue(2.0f), EvoZeroDivisionException);
	BOOST_CHECK_THROW(ff.calculateFunctionValue(20.0f), EvoZeroDivisionException);
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionDefaultConstructThenFitnessThrows) {
	FitnessFunction ff;
	BOOST_CHECK_THROW(ff.calculateFitness(2.0f), EvoZeroDivisionException);
	BOOST_CHECK_THROW(ff.calculateFitness(20.0f), EvoZeroDivisionException);
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionConstructWithNumeratorDenominatorAndTargetThenTheyAreSetCorrectly) {
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	FitnessFunction ff(numFact, denomFact, 10.0f);
	BOOST_CHECK(numFact == ff.getNumeratorFactors());
	BOOST_CHECK(denomFact == ff.getDenominatorFactors());
	BOOST_CHECK_EQUAL(10.0f, ff.getTarget());
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionSettingNumeratorDenominatorAndTargetThenTheyAreSetCorrectly) {
	FitnessFunction ff;
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	ff.setNumeratorFactors(numFact);
	ff.setDenominatorFactors(denomFact);
	ff.setTarget(10.0f);
	BOOST_CHECK(numFact == ff.getNumeratorFactors());
	BOOST_CHECK(denomFact == ff.getDenominatorFactors());
	BOOST_CHECK_EQUAL(10.0f, ff.getTarget());
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionConstructWithNumeratorDenominatorAndTargetThenFunctionValueIsCorrect) {
	FitnessFunction ff;
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	ff.setNumeratorFactors(numFact);
	ff.setDenominatorFactors(denomFact);
	BOOST_CHECK_EQUAL(7.0f, ff.calculateFunctionValue(2.0f));
	BOOST_CHECK_EQUAL(111.0f, ff.calculateFunctionValue(10.0f));
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionConstructWithNumeratorDenominatorAndTargetThenFitnessIsCorrect) {
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	FitnessFunction ff(numFact, denomFact, 10.0f);
	BOOST_CHECK_EQUAL(1/(10.0f-7.0f), ff.calculateFitness(2.0f));
	BOOST_CHECK_EQUAL(1/(111.0f-10.0f), ff.calculateFitness(10.0f));
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionDivisionByZeroThenExceptionIsThrown) {
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {0};
	FitnessFunction ff(numFact, denomFact, 10.0f);
	BOOST_CHECK_THROW(ff.calculateFitness(2.0f), EvoZeroDivisionException);
}

/* MutationFunction class testing */
BOOST_AUTO_TEST_CASE(WhenMutationDefaultConstructThenMutatorIsZero) {
	MutationFunction mf;
	BOOST_CHECK_EQUAL(0.0f, mf.getMutator());
}

BOOST_AUTO_TEST_CASE(WhenMutationIsSetThenMutatorIsCorrect) {
	MutationFunction mf;
	mf.setMutator(5.0f);
	BOOST_CHECK_EQUAL(5.0f, mf.getMutator());
}

/* CrossoverFunction class testing */
BOOST_AUTO_TEST_CASE(WhenCrossoverDefaultConstructThenCrossoverFactorIsZero) {
	CrossoverFunction cf;
	BOOST_CHECK_EQUAL(0.0f, cf.getCrossFactor());
}

BOOST_AUTO_TEST_CASE(WhenCrossoverIsSetThenCrossoverFactorIsCorrect) {
	CrossoverFunction cf;
	cf.setCrossFactor(5.0f);
	BOOST_CHECK_EQUAL(5.0f, cf.getCrossFactor());
}

/* ExecClass class testing */
BOOST_AUTO_TEST_CASE(WhenExecClassDefaultConstructThenPopulationIsEmptyAndAlgorithmIsNull) {
	ExecClass e;
	BOOST_CHECK_EQUAL(true, e.getPopulation().getIndividuals().empty());
	BOOST_CHECK(e.getAlgorithm() == nullptr);
}

BOOST_AUTO_TEST_CASE(WhenExecClassNullAlgorithmThenGeneratePopulationThrows) {
	ExecClass e;
	BOOST_CHECK_THROW(e.generateNextPopulation(), EvoNullPointerException);
}

BOOST_AUTO_TEST_CASE(WhenExecClassCopyConstructThenMembersAreSetCorrectly) {
	std::vector<Individual> inds { 5.0f, 10.0f, 15.0f };
	std::vector<float> num { 1.0f, 2.0f };
	std::vector<float> denom { 2.0f };
	ExecClass e(Population(inds), FitnessFunction(num, denom, 5.0f), MutationFunction(), CrossoverFunction(), new TestEvoAlg());

	for(int i=0; i<inds.size(); ++i) BOOST_CHECK_EQUAL(inds[i].getValue(), e.getPopulation().getIndividuals().at(i).getValue());

	BOOST_CHECK_EQUAL_COLLECTIONS(begin(num), end(num), begin(e.getFitnessFunction().getNumeratorFactors()), end(e.getFitnessFunction().getNumeratorFactors()));
	BOOST_CHECK_EQUAL_COLLECTIONS(begin(denom), end(denom), begin(e.getFitnessFunction().getDenominatorFactors()), end(e.getFitnessFunction().getDenominatorFactors()));
	BOOST_CHECK_EQUAL(5.0f, e.getFitnessFunction().getTarget());
	BOOST_CHECK_EQUAL(0.0f, e.getMutationFunction().getMutator());
	BOOST_CHECK_EQUAL(0.0f, e.getCrossoverFunction().getCrossFactor());
	e.generateNextPopulation();
	BOOST_CHECK_EQUAL(1, e.getPopulation().getIndividuals().size());
	BOOST_CHECK_EQUAL(5.0f, e.getPopulation().getIndividuals().front().getValue());
}

BOOST_AUTO_TEST_SUITE_END()

