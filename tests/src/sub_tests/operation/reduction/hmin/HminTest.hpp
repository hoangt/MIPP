#ifndef HMINTEST_HPP_
#define HMINTEST_HPP_

#include <cppunit/extensions/HelperMacros.h>

class HminTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(HminTest);

#if defined(MIPP_BW)
#if !defined(MIPP_SSE) || (defined(MIPP_SSE) && MIPP_INSTR_VERSION >= 41)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hmin_int8);
#endif
	CPPUNIT_TEST(test_Reg_hmin_int8);
#endif

#if !defined(MIPP_SSE) || (defined(MIPP_SSE) && MIPP_INSTR_VERSION >= 31)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hmin_int16);
#endif
	CPPUNIT_TEST(test_Reg_hmin_int16);
#endif
#endif

#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
#if !defined(MIPP_SSE) || (defined(MIPP_SSE) && MIPP_INSTR_VERSION >= 41)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hmin_int32);
#endif
	CPPUNIT_TEST(test_Reg_hmin_int32);
#endif
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hmin_float);
#endif
	CPPUNIT_TEST(test_Reg_hmin_float);

#if defined(MIPP_64BIT)
#if !defined(MIPP_SSE) && !defined(MIPP_AVX) && !defined(MIPP_NEON)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hmin_int64);
#endif
	CPPUNIT_TEST(test_Reg_hmin_int64);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_hmin_double);
#endif
	CPPUNIT_TEST(test_Reg_hmin_double);
#endif

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	template <typename T>
	void test_reg_hmin_int();
	template <typename T>
	void test_reg_hmin_real();
	void test_reg_hmin_int8();
	void test_reg_hmin_int16();
	void test_reg_hmin_int32();
	void test_reg_hmin_int64();
	void test_reg_hmin_float();
	void test_reg_hmin_double();

	template <typename T>
	void test_Reg_hmin_int();
	template <typename T>
	void test_Reg_hmin_real();
	void test_Reg_hmin_int8();
	void test_Reg_hmin_int16();
	void test_Reg_hmin_int32();
	void test_Reg_hmin_int64();
	void test_Reg_hmin_float();
	void test_Reg_hmin_double();
};

#endif // HMINTEST_HPP_
