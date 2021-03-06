#include <exception>
#include <algorithm>
#include <numeric>
#include <random>
#include <mipp.h>

#include "FnmsubTest.hpp"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(FnmsubTest);

void 
FnmsubTest::setUp()
{
}

void 
FnmsubTest::tearDown()
{
}

template <typename T>
void FnmsubTest::test_reg_fnmsub()
{
	try
	{
		T inputs1[mipp::N<T>()], inputs2[mipp::N<T>()], inputs3[mipp::N<T>()];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 1);
		std::iota(inputs3, inputs3 + mipp::N<T>(), 1);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);
		std::shuffle(inputs3, inputs3 + mipp::N<T>(), g);

		mipp::reg r1 = mipp::load<T>(inputs1);
		mipp::reg r2 = mipp::load<T>(inputs2);
		mipp::reg r3 = mipp::load<T>(inputs3);
		mipp::reg r4 = mipp::fnmsub<T>(r1, r2, r3);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			T res = -inputs3[i] - inputs1[i] * inputs2[i];
			CPPUNIT_ASSERT_EQUAL(res, *((T*)&r4 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void FnmsubTest::test_reg_fnmsub_float () { test_reg_fnmsub<float >(); }
void FnmsubTest::test_reg_fnmsub_double() { test_reg_fnmsub<double>(); }

template <typename T>
void FnmsubTest::test_Reg_fnmsub()
{
	try
	{
		T inputs1[mipp::N<T>()], inputs2[mipp::N<T>()], inputs3[mipp::N<T>()];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 1);
		std::iota(inputs3, inputs3 + mipp::N<T>(), 1);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);
		std::shuffle(inputs3, inputs3 + mipp::N<T>(), g);

		mipp::Reg<T> r1 = inputs1;
		mipp::Reg<T> r2 = inputs2;
		mipp::Reg<T> r3 = inputs3;
		mipp::Reg<T> r4 = mipp::fnmsub(r1, r2, r3);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			T res = -inputs3[i] - inputs1[i] * inputs2[i];
			CPPUNIT_ASSERT_EQUAL(res, r4[i]);
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void FnmsubTest::test_Reg_fnmsub_float () { test_Reg_fnmsub<float >(); }
void FnmsubTest::test_Reg_fnmsub_double() { test_Reg_fnmsub<double>(); }

template <typename T>
void FnmsubTest::test_reg_maskz_fnmsub()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N], inputs2[N], inputs3[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 1);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);
		std::shuffle(inputs3, inputs3 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::reg r1 = mipp::load<T>(inputs1);
		mipp::reg r2 = mipp::load<T>(inputs2);
		mipp::reg r3 = mipp::load<T>(inputs3);
		mipp::msk m  = mipp::set <N>(mask   );

		mipp::reg r4 = mipp::maskz<T,mipp::fnmsub<T>>(m, r1, r2, r3);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			if (mask[i])
			{
				T res = -inputs3[i] - inputs1[i] * inputs2[i];
				CPPUNIT_ASSERT_EQUAL(res, *((T*)&r4 +i));
			}
			else
				CPPUNIT_ASSERT_EQUAL((T)0, *((T*)&r4 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void FnmsubTest::test_reg_maskz_fnmsub_float () { test_reg_maskz_fnmsub<float >(); }
void FnmsubTest::test_reg_maskz_fnmsub_double() { test_reg_maskz_fnmsub<double>(); }

template <typename T>
void FnmsubTest::test_Reg_maskz_fnmsub()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N], inputs2[N], inputs3[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 1);
		std::iota(inputs3, inputs3 + mipp::N<T>(), 1);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);
		std::shuffle(inputs3, inputs3 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::Reg<T> r1 = inputs1;
		mipp::Reg<T> r2 = inputs2;
		mipp::Reg<T> r3 = inputs3;
		mipp::Msk<N> m  = mask;

		mipp::Reg<T> r4 = mipp::maskz<T,mipp::fnmsub>(m, r1, r2, r3);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			if (mask[i])
			{
				T res = -inputs3[i] - inputs1[i] * inputs2[i];
				CPPUNIT_ASSERT_EQUAL(res, r4[i]);
			}
			else
				CPPUNIT_ASSERT_EQUAL((T)0, r4[i]);
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void FnmsubTest::test_Reg_maskz_fnmsub_float () { test_Reg_maskz_fnmsub<float >(); }
void FnmsubTest::test_Reg_maskz_fnmsub_double() { test_Reg_maskz_fnmsub<double>(); }

template <typename T>
void FnmsubTest::test_reg_mask_fnmsub()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N], inputs2[N], inputs3[N], inputs4[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 1);
		std::iota(inputs3, inputs3 + mipp::N<T>(), 1);
		std::iota(inputs4, inputs4 + mipp::N<T>(), 0);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);
		std::shuffle(inputs3, inputs3 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::reg r1 = mipp::load<T>(inputs1);
		mipp::reg r2 = mipp::load<T>(inputs2);
		mipp::reg r3 = mipp::load<T>(inputs3);
		mipp::reg r4 = mipp::load<T>(inputs4);
		mipp::msk m  = mipp::set <N>(mask   );

		mipp::reg r5 = mipp::mask<T,mipp::fnmsub<T>>(m, r4, r1, r2, r3);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			if (mask[i])
			{
				T res = -inputs3[i] - inputs1[i] * inputs2[i];
				CPPUNIT_ASSERT_EQUAL(res, *((T*)&r5 +i));
			}
			else
				CPPUNIT_ASSERT_EQUAL(inputs4[i], *((T*)&r5 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void FnmsubTest::test_reg_mask_fnmsub_float () { test_reg_mask_fnmsub<float >(); }
void FnmsubTest::test_reg_mask_fnmsub_double() { test_reg_mask_fnmsub<double>(); }

template <typename T>
void FnmsubTest::test_Reg_mask_fnmsub()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N], inputs2[N], inputs3[N], inputs4[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 1);
		std::iota(inputs3, inputs3 + mipp::N<T>(), 1);
		std::iota(inputs4, inputs4 + mipp::N<T>(), 0);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);
		std::shuffle(inputs3, inputs3 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::Reg<T> r1 = inputs1;
		mipp::Reg<T> r2 = inputs2;
		mipp::Reg<T> r3 = inputs3;
		mipp::Reg<T> r4 = inputs4;
		mipp::Msk<N> m  = mask;

		mipp::Reg<T> r5 = mipp::mask<T,mipp::fnmsub>(m, r4, r1, r2, r3);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			if (mask[i])
			{
				T res = -inputs3[i] - inputs1[i] * inputs2[i];
				CPPUNIT_ASSERT_EQUAL(res, *((T*)&r5 +i));
			}
			else
				CPPUNIT_ASSERT_EQUAL(inputs4[i], *((T*)&r5 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void FnmsubTest::test_Reg_mask_fnmsub_float () { test_Reg_mask_fnmsub<float >(); }
void FnmsubTest::test_Reg_mask_fnmsub_double() { test_Reg_mask_fnmsub<double>(); }
