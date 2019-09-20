#include "testFunction.h"
#include <stdio.h>

static testFunction	gTest;

testFunction::testFunction()
{
}

testFunction::~testFunction()
{
}

void testFunction::TestPrintf(int a){
	m_a += a;
	printf("테스트 한글 출력. %d\n", m_a);
}

extern "C" void TestPrintf(int a)
{
	gTest.TestPrintf(a);
}