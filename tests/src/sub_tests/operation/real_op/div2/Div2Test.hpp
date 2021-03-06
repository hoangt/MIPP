#ifndef DIV2TEST_HPP_
#define DIV2TEST_HPP_

#include <cppunit/extensions/HelperMacros.h>

class Div2Test : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(Div2Test);

#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
#if !defined(MIPP_SSE) || (defined(MIPP_SSE) && MIPP_INSTR_VERSION >= 31)
#if defined(MIPP_BW)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_div2_int8);
	CPPUNIT_TEST(test_reg_maskz_div2_int8);
	CPPUNIT_TEST(test_reg_mask_div2_int8);
#endif
	CPPUNIT_TEST(test_Reg_div2_int8);
	CPPUNIT_TEST(test_Reg_maskz_div2_int8);
	CPPUNIT_TEST(test_Reg_mask_div2_int8);

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_div2_int16);
	CPPUNIT_TEST(test_reg_maskz_div2_int16);
	CPPUNIT_TEST(test_reg_mask_div2_int16);
#endif
	CPPUNIT_TEST(test_Reg_div2_int16);
	CPPUNIT_TEST(test_Reg_maskz_div2_int16);
	CPPUNIT_TEST(test_Reg_mask_div2_int16);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_div2_int32);
	CPPUNIT_TEST(test_reg_maskz_div2_int32);
	CPPUNIT_TEST(test_reg_mask_div2_int32);
#endif
	CPPUNIT_TEST(test_Reg_div2_int32);
	CPPUNIT_TEST(test_Reg_maskz_div2_int32);
	CPPUNIT_TEST(test_Reg_mask_div2_int32);
#endif
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_div2_float);
	CPPUNIT_TEST(test_reg_maskz_div2_float);
	CPPUNIT_TEST(test_reg_mask_div2_float);
#endif
	CPPUNIT_TEST(test_Reg_div2_float);
	CPPUNIT_TEST(test_Reg_maskz_div2_float);
	CPPUNIT_TEST(test_Reg_mask_div2_float);

#if defined(MIPP_64BIT)
#if !defined(MIPP_SSE) && !defined(MIPP_AVX)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_div2_int64);
	CPPUNIT_TEST(test_reg_maskz_div2_int64);
	CPPUNIT_TEST(test_reg_mask_div2_int64);
#endif
	CPPUNIT_TEST(test_Reg_div2_int64);
	CPPUNIT_TEST(test_Reg_maskz_div2_int64);
	CPPUNIT_TEST(test_Reg_mask_div2_int64);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_div2_double);
	CPPUNIT_TEST(test_reg_maskz_div2_double);
	CPPUNIT_TEST(test_reg_mask_div2_double);
#endif
	CPPUNIT_TEST(test_Reg_div2_double);
	CPPUNIT_TEST(test_Reg_maskz_div2_double);
	CPPUNIT_TEST(test_Reg_mask_div2_double);
#endif

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	template <typename T>
	void test_reg_div2();
	void test_reg_div2_int8();
	void test_reg_div2_int16();
	void test_reg_div2_int32();
	void test_reg_div2_int64();
	void test_reg_div2_float();
	void test_reg_div2_double();

	template <typename T>
	void test_Reg_div2();
	void test_Reg_div2_int8();
	void test_Reg_div2_int16();
	void test_Reg_div2_int32();
	void test_Reg_div2_int64();
	void test_Reg_div2_float();
	void test_Reg_div2_double();

	template <typename T>
	void test_reg_maskz_div2();
	void test_reg_maskz_div2_int8();
	void test_reg_maskz_div2_int16();
	void test_reg_maskz_div2_int32();
	void test_reg_maskz_div2_int64();
	void test_reg_maskz_div2_float();
	void test_reg_maskz_div2_double();

	template <typename T>
	void test_Reg_maskz_div2();
	void test_Reg_maskz_div2_int8();
	void test_Reg_maskz_div2_int16();
	void test_Reg_maskz_div2_int32();
	void test_Reg_maskz_div2_int64();
	void test_Reg_maskz_div2_float();
	void test_Reg_maskz_div2_double();

	template <typename T>
	void test_reg_mask_div2();
	void test_reg_mask_div2_int8();
	void test_reg_mask_div2_int16();
	void test_reg_mask_div2_int32();
	void test_reg_mask_div2_int64();
	void test_reg_mask_div2_float();
	void test_reg_mask_div2_double();

	template <typename T>
	void test_Reg_mask_div2();
	void test_Reg_mask_div2_int8();
	void test_Reg_mask_div2_int16();
	void test_Reg_mask_div2_int32();
	void test_Reg_mask_div2_int64();
	void test_Reg_mask_div2_float();
	void test_Reg_mask_div2_double();
};

#endif // DIV2TEST_HPP_
