#ifndef LOADTEST_HPP_
#define LOADTEST_HPP_

#include <cppunit/extensions/HelperMacros.h>

class LoadTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(LoadTest);

#if defined(MIPP_BW)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_load_int8);
	CPPUNIT_TEST(test_reg_loadu_int8);
#endif
	CPPUNIT_TEST(test_Reg_load_int8);
	CPPUNIT_TEST(test_Reg_loadu_int8);

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_load_int16);
	CPPUNIT_TEST(test_reg_loadu_int16);
#endif
	CPPUNIT_TEST(test_Reg_load_int16);
	CPPUNIT_TEST(test_Reg_loadu_int16);
#endif

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_load_int32);
	CPPUNIT_TEST(test_reg_loadu_int32);
#endif
	CPPUNIT_TEST(test_Reg_load_int32);
	CPPUNIT_TEST(test_Reg_loadu_int32);

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_load_float);
	CPPUNIT_TEST(test_reg_loadu_float);
#endif
	CPPUNIT_TEST(test_Reg_load_float);
	CPPUNIT_TEST(test_Reg_loadu_float);

#if defined(MIPP_64BIT)
#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_load_int64);
	CPPUNIT_TEST(test_reg_loadu_int64);
#endif
	CPPUNIT_TEST(test_Reg_load_int64);
	CPPUNIT_TEST(test_Reg_loadu_int64);

#ifndef MIPP_NO
	CPPUNIT_TEST(test_reg_load_double);
	CPPUNIT_TEST(test_reg_loadu_double);
#endif
	CPPUNIT_TEST(test_Reg_load_double);
	CPPUNIT_TEST(test_Reg_loadu_double);
#endif

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	template <typename T>
	void test_reg_load();
	void test_reg_load_int8();
	void test_reg_load_int16();
	void test_reg_load_int32();
	void test_reg_load_int64();
	void test_reg_load_float();
	void test_reg_load_double();

	template <typename T>
	void test_reg_loadu();
	void test_reg_loadu_int8();
	void test_reg_loadu_int16();
	void test_reg_loadu_int32();
	void test_reg_loadu_int64();
	void test_reg_loadu_float();
	void test_reg_loadu_double();

	template <typename T>
	void test_Reg_load();
	void test_Reg_load_int8();
	void test_Reg_load_int16();
	void test_Reg_load_int32();
	void test_Reg_load_int64();
	void test_Reg_load_float();
	void test_Reg_load_double();

	template <typename T>
	void test_Reg_loadu();
	void test_Reg_loadu_int8();
	void test_Reg_loadu_int16();
	void test_Reg_loadu_int32();
	void test_Reg_loadu_int64();
	void test_Reg_loadu_float();
	void test_Reg_loadu_double();
};

#endif  // LOADTEST_HPP_
