#ifndef HADDTEST_HPP_
#define HADDTEST_HPP_

#include <cppunit/extensions/HelperMacros.h>

class HaddTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(HaddTest);

#if defined(MIPP_BW)
#if !defined(MIPP_SSE) || (defined(MIPP_SSE) && MIPP_INSTR_VERSION >= 31)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hadd_int8);
#endif
	CPPUNIT_TEST(test_Reg_hadd_int8);

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hadd_int16);
#endif
	CPPUNIT_TEST(test_Reg_hadd_int16);
#endif
#endif

#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hadd_int32);
#endif
	CPPUNIT_TEST(test_Reg_hadd_int32);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hadd_float);
#endif
	CPPUNIT_TEST(test_Reg_hadd_float);

#if defined(MIPP_64BIT)
#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hadd_int64);
#endif
	CPPUNIT_TEST(test_Reg_hadd_int64);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hadd_double);
#endif
	CPPUNIT_TEST(test_Reg_hadd_double);
#endif

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	template <typename T>
	void test_reg_hadd_int();
	template <typename T>
	void test_reg_hadd_real();
	void test_reg_hadd_int8();
	void test_reg_hadd_int16();
	void test_reg_hadd_int32();
	void test_reg_hadd_int64();
	void test_reg_hadd_float();
	void test_reg_hadd_double();

	template <typename T>
	void test_Reg_hadd_int();
	template <typename T>
	void test_Reg_hadd_real();
	void test_Reg_hadd_int8();
	void test_Reg_hadd_int16();
	void test_Reg_hadd_int32();
	void test_Reg_hadd_int64();
	void test_Reg_hadd_float();
	void test_Reg_hadd_double();
};

#endif // HADDTEST_HPP_
