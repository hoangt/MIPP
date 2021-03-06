#ifndef SUBTEST_HPP_
#define SUBTEST_HPP_

#include <cppunit/extensions/HelperMacros.h>

class SubTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(SubTest);

#if defined(MIPP_BW)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_sub_int8);
	CPPUNIT_TEST(test_reg_maskz_sub_int8);
	CPPUNIT_TEST(test_reg_mask_sub_int8);
#endif
	CPPUNIT_TEST(test_Reg_sub_int8);
	CPPUNIT_TEST(test_Reg_maskz_sub_int8);
	CPPUNIT_TEST(test_Reg_mask_sub_int8);

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_sub_int16);
	CPPUNIT_TEST(test_reg_maskz_sub_int16);
	CPPUNIT_TEST(test_reg_mask_sub_int16);
#endif
	CPPUNIT_TEST(test_Reg_sub_int16);
	CPPUNIT_TEST(test_Reg_maskz_sub_int16);
	CPPUNIT_TEST(test_Reg_mask_sub_int16);
#endif

#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_sub_int32);
	CPPUNIT_TEST(test_reg_maskz_sub_int32);
	CPPUNIT_TEST(test_reg_mask_sub_int32);
#endif
	CPPUNIT_TEST(test_Reg_sub_int32);
	CPPUNIT_TEST(test_Reg_maskz_sub_int32);
	CPPUNIT_TEST(test_Reg_mask_sub_int32);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_sub_float);
	CPPUNIT_TEST(test_reg_maskz_sub_float);
	CPPUNIT_TEST(test_reg_mask_sub_float);
#endif
	CPPUNIT_TEST(test_Reg_sub_float);
	CPPUNIT_TEST(test_Reg_maskz_sub_float);
	CPPUNIT_TEST(test_Reg_mask_sub_float);

#if defined(MIPP_64BIT)
#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_sub_int64);
	CPPUNIT_TEST(test_reg_maskz_sub_int64);
	CPPUNIT_TEST(test_reg_mask_sub_int64);
#endif
	CPPUNIT_TEST(test_Reg_sub_int64);
	CPPUNIT_TEST(test_Reg_maskz_sub_int64);
	CPPUNIT_TEST(test_Reg_mask_sub_int64);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_sub_double);
	CPPUNIT_TEST(test_reg_maskz_sub_double);
	CPPUNIT_TEST(test_reg_mask_sub_double);
#endif
	CPPUNIT_TEST(test_Reg_sub_double);
	CPPUNIT_TEST(test_Reg_maskz_sub_double);
	CPPUNIT_TEST(test_Reg_mask_sub_double);
#endif

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	template <typename T>
	void test_reg_sub();
	void test_reg_sub_int8();
	void test_reg_sub_int16();
	void test_reg_sub_int32();
	void test_reg_sub_int64();
	void test_reg_sub_float();
	void test_reg_sub_double();

	template <typename T>
	void test_Reg_sub();
	void test_Reg_sub_int8();
	void test_Reg_sub_int16();
	void test_Reg_sub_int32();
	void test_Reg_sub_int64();
	void test_Reg_sub_float();
	void test_Reg_sub_double();

	template <typename T>
	void test_reg_maskz_sub();
	void test_reg_maskz_sub_int8();
	void test_reg_maskz_sub_int16();
	void test_reg_maskz_sub_int32();
	void test_reg_maskz_sub_int64();
	void test_reg_maskz_sub_float();
	void test_reg_maskz_sub_double();

	template <typename T>
	void test_Reg_maskz_sub();
	void test_Reg_maskz_sub_int8();
	void test_Reg_maskz_sub_int16();
	void test_Reg_maskz_sub_int32();
	void test_Reg_maskz_sub_int64();
	void test_Reg_maskz_sub_float();
	void test_Reg_maskz_sub_double();

	template <typename T>
	void test_reg_mask_sub();
	void test_reg_mask_sub_int8();
	void test_reg_mask_sub_int16();
	void test_reg_mask_sub_int32();
	void test_reg_mask_sub_int64();
	void test_reg_mask_sub_float();
	void test_reg_mask_sub_double();

	template <typename T>
	void test_Reg_mask_sub();
	void test_Reg_mask_sub_int8();
	void test_Reg_mask_sub_int16();
	void test_Reg_mask_sub_int32();
	void test_Reg_mask_sub_int64();
	void test_Reg_mask_sub_float();
	void test_Reg_mask_sub_double();
};

#endif  // SUBTEST_HPP_
