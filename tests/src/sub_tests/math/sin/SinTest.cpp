#include <exception>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include <mipp.h>

#include "SinTest.hpp"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(SinTest);

void 
SinTest::setUp()
{
}

void 
SinTest::tearDown()
{
}

template <typename T>
void SinTest::test_reg_sin()
{
	try
	{
		T inputs1[mipp::N<T>()];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);

		mipp::reg r1 = mipp::load<T>(inputs1);
		mipp::reg r2 = mipp::sin<T>(r1);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			T res = std::sin(inputs1[i]);
//			CPPUNIT_ASSERT_EQUAL(res, *((T*)&r2 +i));
			T diff = std::abs(res - *((T*)&r2 +i));
			CPPUNIT_ASSERT(diff < 0.001);
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void SinTest::test_reg_sin_float () { test_reg_sin<float >(); }
void SinTest::test_reg_sin_double() { test_reg_sin<double>(); }

template <typename T>
void SinTest::test_Reg_sin()
{
	try
	{
		T inputs1[mipp::N<T>()];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);

		mipp::Reg<T> r1 = inputs1;
		mipp::Reg<T> r2 = mipp::sin(r1);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			T res = std::sin(inputs1[i]);
//			CPPUNIT_ASSERT_EQUAL(res, r2[i]);
			T diff = std::abs(res - r2[i]);
			CPPUNIT_ASSERT(diff < 0.001);
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void SinTest::test_Reg_sin_float () { test_Reg_sin<float >(); }
void SinTest::test_Reg_sin_double() { test_Reg_sin<double>(); }

template <typename T>
void SinTest::test_reg_maskz_sin()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::reg r1 = mipp::load<T>(inputs1);
		mipp::msk m  = mipp::set <N>(mask   );

		mipp::reg r2 = mipp::maskz<T,mipp::sin<T>>(m, r1);

		for (auto i = 0; i < N; i++)
		{
			if (mask[i])
			{
				T res = std::sin(inputs1[i]);
//				CPPUNIT_ASSERT_EQUAL(res, *((T*)&r2 +i));
				T diff = std::abs(res - *((T*)&r2 +i));
				CPPUNIT_ASSERT(diff < 0.001);
			}
			else
				CPPUNIT_ASSERT_EQUAL((T)0, *((T*)&r2 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void SinTest::test_reg_maskz_sin_float () { test_reg_maskz_sin<float >(); }
void SinTest::test_reg_maskz_sin_double() { test_reg_maskz_sin<double>(); }

template <typename T>
void SinTest::test_Reg_maskz_sin()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::Reg<T> r1 = inputs1;
		mipp::Msk<N> m  = mask;

		mipp::Reg<T> r2 = mipp::maskz<T,mipp::sin>(m, r1);

		for (auto i = 0; i < N; i++)
		{
			if (mask[i])
			{
				T res = std::sin(inputs1[i]);
//				CPPUNIT_ASSERT_EQUAL(res, r2[i]);
				T diff = std::abs(res - r2[i]);
				CPPUNIT_ASSERT(diff < 0.001);
			}
			else
				CPPUNIT_ASSERT_EQUAL((T)0, r2[i]);
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void SinTest::test_Reg_maskz_sin_float () { test_Reg_maskz_sin<float >(); }
void SinTest::test_Reg_maskz_sin_double() { test_Reg_maskz_sin<double>(); }

template <typename T>
void SinTest::test_reg_mask_sin()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N], inputs2[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 0);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::reg r1 = mipp::load<T>(inputs1);
		mipp::reg r2 = mipp::load<T>(inputs2);
		mipp::msk m  = mipp::set <N>(mask   );

		mipp::reg r3 = mipp::mask<T,mipp::sin<T>>(m, r2, r1);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			if (mask[i])
			{
				T res = std::sin(inputs1[i]);
//				CPPUNIT_ASSERT_EQUAL(res, *((T*)&r3 +i));
				T diff = std::abs(res - *((T*)&r3 +i));
				CPPUNIT_ASSERT(diff < 0.001);
			}
			else
				CPPUNIT_ASSERT_EQUAL(inputs2[i], *((T*)&r3 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void SinTest::test_reg_mask_sin_float () { test_reg_mask_sin<float >(); }
void SinTest::test_reg_mask_sin_double() { test_reg_mask_sin<double>(); }

template <typename T>
void SinTest::test_Reg_mask_sin()
{
	try
	{
		constexpr int N = mipp::N<T>();
		T inputs1[N], inputs2[N];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 1);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 0);

		bool mask[N];
		std::fill(mask,       mask + N/2, true );
		std::fill(mask + N/2, mask + N,   false);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(mask,    mask    + mipp::N<T>(), g);

		mipp::Reg<T> r1 = inputs1;
		mipp::Reg<T> r2 = inputs2;
		mipp::Msk<N> m  = mask;

		mipp::Reg<T> r3 = mipp::mask<T,mipp::sin>(m, r2, r1);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			if (mask[i])
			{
				T res = std::sin(inputs1[i]);
//				CPPUNIT_ASSERT_EQUAL(res, *((T*)&r3 +i));
				T diff = std::abs(res - r3[i]);
				CPPUNIT_ASSERT(diff < 0.001);
			}
			else
				CPPUNIT_ASSERT_EQUAL(inputs2[i], *((T*)&r3 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void SinTest::test_Reg_mask_sin_float () { test_Reg_mask_sin<float >(); }
void SinTest::test_Reg_mask_sin_double() { test_Reg_mask_sin<double>(); }
