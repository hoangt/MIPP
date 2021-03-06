#include <exception>
#include <algorithm>
#include <numeric>
#include <random>
#include <mipp.h>

#include "XorTest.hpp"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(XorTest);

void
XorTest::setUp()
{
}

void
XorTest::tearDown()
{
}

template <typename T>
void XorTest::test_reg_xor()
{
	try
	{
		T inputs1[mipp::N<T>()], inputs2[mipp::N<T>()];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 0);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 0);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);

		mipp::reg r1 = mipp::load<T>(inputs1);
		mipp::reg r2 = mipp::load<T>(inputs2);
		mipp::reg r3 = mipp::xorb<T>(r1, r2);

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			T res = inputs1[i] ^ inputs2[i];
			CPPUNIT_ASSERT_EQUAL(res, *((T*)&r3 +i));
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void XorTest::test_reg_xor_int8 () { test_reg_xor<int8_t >(); }
void XorTest::test_reg_xor_int16() { test_reg_xor<int16_t>(); }
void XorTest::test_reg_xor_int32() { test_reg_xor<int32_t>(); }
void XorTest::test_reg_xor_int64() { test_reg_xor<int64_t>(); }

template <typename T>
void XorTest::test_Reg_xor()
{
	try
	{
		T inputs1[mipp::N<T>()], inputs2[mipp::N<T>()];
		std::iota(inputs1, inputs1 + mipp::N<T>(), 0);
		std::iota(inputs2, inputs2 + mipp::N<T>(), 0);

		std::mt19937 g;
		std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
		std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);

		mipp::Reg<T> r1 = inputs1;
		mipp::Reg<T> r2 = inputs2;
		mipp::Reg<T> r3 = r1 ^ r2;

		for (auto i = 0; i < mipp::N<T>(); i++)
		{
			T res = inputs1[i] ^ inputs2[i];
			CPPUNIT_ASSERT_EQUAL(res, r3[i]);
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void XorTest::test_Reg_xor_int8 () { test_Reg_xor<int8_t >(); }
void XorTest::test_Reg_xor_int16() { test_Reg_xor<int16_t>(); }
void XorTest::test_Reg_xor_int32() { test_Reg_xor<int32_t>(); }
void XorTest::test_Reg_xor_int64() { test_Reg_xor<int64_t>(); }

template <typename T>
void XorTest::test_msk_xor()
{
	try
	{
		constexpr int N = mipp::N<T>();
		bool inputs1[N], inputs2[N];
		std::mt19937 g;
		std::uniform_int_distribution<uint8_t> dis(0, 1);

		for (auto t = 0; t < 100; t++)
		{
			for (auto i = 0; i < N; i++)
			{
				inputs1[i] = dis(g) ? true : false;
				inputs2[i] = dis(g) ? true : false;
			}

			std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
			std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);

			mipp::msk m1 = mipp::set<N>(inputs1);
			mipp::msk m2 = mipp::set<N>(inputs2);
			mipp::msk m3 = mipp::xorb<N>(m1, m2);

			mipp::reg r = mipp::toreg<N>(m3);

			for (auto i = 0; i < N; i++)
			{
				bool res = inputs1[i] ^ inputs2[i];

				if (res)
					CPPUNIT_ASSERT(*((T*)&r +i) != (T)0);
				else
					CPPUNIT_ASSERT_EQUAL((T)res, *((T*)&r +i));
			}
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void XorTest::test_msk_xor_int8 () { test_msk_xor<int8_t >(); }
void XorTest::test_msk_xor_int16() { test_msk_xor<int16_t>(); }
void XorTest::test_msk_xor_int32() { test_msk_xor<int32_t>(); }
void XorTest::test_msk_xor_int64() { test_msk_xor<int64_t>(); }

template <typename T>
void XorTest::test_Msk_xor()
{
	try
	{
		constexpr int N = mipp::N<T>();
		bool inputs1[N], inputs2[N];
		std::mt19937 g;
		std::uniform_int_distribution<uint8_t> dis(0, 1);

		for (auto t = 0; t < 100; t++)
		{
			for (auto i = 0; i < N; i++)
			{
				inputs1[i] = dis(g) ? true : false;
				inputs2[i] = dis(g) ? true : false;
			}

			std::shuffle(inputs1, inputs1 + mipp::N<T>(), g);
			std::shuffle(inputs2, inputs2 + mipp::N<T>(), g);

			mipp::Msk<N> m1 = inputs1;
			mipp::Msk<N> m2 = inputs2;
			mipp::Msk<N> m3 = m1 ^ m2;

			for (auto i = 0; i < N; i++)
			{
				bool res = inputs1[i] ^ inputs2[i];
				CPPUNIT_ASSERT_EQUAL(res, m3[i]);
			}
		}
	}
	catch(std::exception &e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void XorTest::test_Msk_xor_int8 () { test_Msk_xor<int8_t >(); }
void XorTest::test_Msk_xor_int16() { test_Msk_xor<int16_t>(); }
void XorTest::test_Msk_xor_int32() { test_Msk_xor<int32_t>(); }
void XorTest::test_Msk_xor_int64() { test_Msk_xor<int64_t>(); }
