#include "EvoAlgorithm.h"
#include "ExecClass.h"

#include <cstdint>
#include <string>

#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(EvoTests)

BOOST_AUTO_TEST_CASE(GivenOneThingAnotherThingHappens)  // proof that Boost tests work
{
	BOOST_CHECK_EQUAL(2+2,4);
}

/* Example tests */
BOOST_AUTO_TEST_CASE(WhenMutationIsSetThenGetReturnsSameValue)
{
	ExecClass e;
	MutationFunction mf;
	mf.setMutator(5.0f);
	e.setMutationFunction(&mf);
	BOOST_CHECK_EQUAL(5.0f, e.getMutationFunction()->getMutator());
}

BOOST_AUTO_TEST_CASE(WhenCrossoverIsSetThenGetReturnsSameValue)
{
	ExecClass e;
	CrossoverFunction cf;
	cf.setCrossFactor(0.5f);
	e.setCrossoverFunction(&cf);
	BOOST_CHECK_EQUAL(0.5f, e.getCrossoverFunction()->getCrossFactor());
}

BOOST_AUTO_TEST_CASE(WhenTwoIndividualsAddedToPopulationThenLastOnesValueIsCorrect)
{
	Population p;
	Individual ind1(4.0f);
	Individual ind2(6.0f);
	p.addIndividual(ind1);
	p.addIndividual(ind2);
	float checkVal = p.getPopulation().back().getValue();
	BOOST_CHECK_EQUAL(6.0f, checkVal);
}


BOOST_AUTO_TEST_SUITE_END()
