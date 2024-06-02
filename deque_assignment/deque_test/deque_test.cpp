#include "pch.h"
#include "CppUnitTest.h"
#include <time.h>
#include<deque>
#include "../deque_assignment/my_deque.cpp"
#include "../deque_assignment/my_deque_iterator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dequetest
{
	int verbose = 0;
	int init_size = 32;
	int n = 32;

	TEST_CLASS(dequetest)
	{
	public:

		TEST_METHOD(push_back_pop_back)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			for (int i = 0; i < n; i++) {
				Assert::AreEqual((n - (i + 1)), d.pop_back());
			}
		}

		TEST_METHOD(push_back_pop_front)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}
			for (int i = 0; i < n; i++) {
				Assert::AreEqual(i, d.pop_front());
			}
		}

		TEST_METHOD(push_front_pop_back)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n; i++) {
				d.push_front(i);
			}
			for (int i = 0; i < n; i++) {
				Assert::AreEqual(i, d.pop_back());
			}
		}

		TEST_METHOD(push_front_pop_front)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n; i++) {
				d.push_front(i);
			}

			for (int i = 0; i < n; i++) {
				int ret_front = d.pop_front();
				Assert::AreEqual(n - (i + 1), ret_front);
			}
		}

		TEST_METHOD(push_mixed_pop_front)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n; i += 2) {
				d.push_back(i);
				d.push_front(i + 1);
			}
			for (int i = 1; i < n; i += 2) {
				Assert::AreEqual((n - i), d.pop_front());
			}
			for (int i = 0; i < n; i += 2) {
				Assert::AreEqual(i, d.pop_front());
			}
		}

		TEST_METHOD(push_mixed_pop_back)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n; i += 2) {
				d.push_back(i);
				d.push_front(i + 1);
			}
			for (int i = 0; i < n; i += 2) {
				Assert::AreEqual((n - (i + 2)), d.pop_back());
			}

			for (int i = 1; i < n; i += 2) {
				Assert::AreEqual(i, d.pop_back());
			}
		}

		TEST_METHOD(push_mixed_pop_mixed)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n; i += 2) {
				d.push_back(i);
				d.push_front(i + 1);
			}
			for (int i = 0; i < n; i += 2) {
				int front_ret = d.pop_front();
				int back_ret = d.pop_back();

				Assert::AreEqual((n - (i + 2)), back_ret);
				Assert::AreEqual((n - (i + 1)), front_ret);
			}
		}

		TEST_METHOD(push_mixed_pop_mixed_large)
		{
			my_deque d = my_deque(init_size);
			for (int i = 0; i < n * 10; i += 2) {
				d.push_back(i);
				d.push_front(i + 1);
			}
			for (int i = 0; i < n * 10; i += 2) {
				int front_ret = d.pop_front();
				int back_ret = d.pop_back();

				Assert::AreEqual((n * 10 - (i + 2)), back_ret);
				Assert::AreEqual((n * 10 - (i + 1)), front_ret);
			}
		}

		TEST_METHOD(random_test_large)
		{
			srand(time(NULL));
			std::deque<int> d_correct;
			my_deque d_testing(n);
			size_t iterations = n << 8;
			for (size_t i = 0; i < iterations; ++i) {
				int adding = rand() % 1000;
				if (adding % 2 == 0) {
					d_correct.push_back(adding);
					d_testing.push_back(adding);
				}
				else {
					d_correct.push_front(adding);
					d_testing.push_front(adding);
				}
			}
			for (size_t i = 0; i < iterations; ++i) {
				Assert::AreEqual(d_correct[i], d_testing[i]);
			}
			for (size_t i = 0; i < iterations; ++i) {
				int correct;
				int testing;
				if (rand() % 2 == 0) {
					correct = d_correct.back();
					d_correct.pop_back();
					testing = d_testing.pop_back();
				}
				else {
					correct = d_correct.front();
					d_correct.pop_front();
					testing = d_testing.pop_front();
				}
				Assert::AreEqual(correct, testing);
			}
		}

		TEST_METHOD(invalid_pop) {
			auto func = [] {my_deque d(8); d.push_back(5); d.pop_back(); d.pop_front(); };
			Assert::ExpectException<std::exception>(func);

			auto func2 = [] {my_deque d(8); d.push_back(5); d.pop_front(); d.pop_back(); };
			Assert::ExpectException<std::exception>(func2);
		}

		TEST_METHOD(recenter_back)
		{

			my_deque d = my_deque(init_size);
			size_t start_size = d.get_size();

			for (int i = 0; i < n; i++) {
				d.push_back(i);
				Assert::AreEqual(i, d.pop_front());
			}

			Assert::IsTrue(d.get_size() <= start_size);
		}

		TEST_METHOD(recenter_front)
		{
			my_deque d = my_deque(init_size);
			size_t start_size = d.get_size();
			for (int i = 0; i < n; i++) {
				d.push_front(i);
				Assert::AreEqual(i, d.pop_back());
			}

			Assert::IsTrue(d.get_size() <= start_size);
		}

		TEST_METHOD(subscript)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}
			for (int i = 0; i < n; i++) {
				Assert::AreEqual(d[i], i);
			}

			// invalid index
			auto func = [] {my_deque d = my_deque(4); d.push_back(1); d[1]; };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(copy)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n; i += 2) {
				d.push_front(i);
				d.push_back(i + 1);
			}

			my_deque d_copy(d);
			Assert::AreEqual(d_copy.get_size(), d.get_size());
			Assert::AreNotEqual(d_copy.get_mem(), d.get_mem());

			for (int i = 0; i < n; i++) {
				Assert::AreEqual(d_copy[i], d[i]);
			}

			Assert::IsTrue(!memcmp(d_copy.get_mem(),
				d.get_mem(),
				d.get_size() * sizeof(int)));

			for (int i = 0; i < n; i += 2) {
				Assert::AreEqual(d_copy.pop_back(), d.pop_back());

				Assert::AreEqual(d_copy.pop_front(), d.pop_front());
			}
		}
	};
	
	TEST_CLASS(dequeiteratortest)
	{
	public:

		TEST_METHOD(construct_past_the_end)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_rIndex(), &d);
			Assert::AreEqual(d.get_mem() + d.get_rIndex(), di.get_mem());
		}
		TEST_METHOD(invalid_constructor)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			my_deque d2(4);
			d2.push_back(5);
			my_deque_iterator di(d2.get_mem(), &d);
			Assert::AreEqual(di.get_mem(), (int*)nullptr);

			my_deque_iterator di2(d.get_mem() - 1, &d);
			Assert::AreEqual(di2.get_mem(), (int*)nullptr);
		}
		TEST_METHOD(good_constructor)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			Assert::AreEqual(di.get_mem(), d.get_mem() + d.get_lIndex() + 1);

			my_deque_iterator di2(d.get_mem() + d.get_lIndex() + n / 2, &d);
			Assert::AreEqual(d.get_mem() + d.get_lIndex() + n / 2, di2.get_mem());
		}
		TEST_METHOD(addition)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			my_deque_iterator di2 = di + n / 2;
			Assert::AreEqual(di2.get_mem(), d.get_mem() + d.get_lIndex() + n / 2 + 1);

			my_deque_iterator di3 = di + n;
			Assert::AreEqual(di3.get_mem(), d.get_mem() + d.get_rIndex());

			my_deque_iterator di4 = di2 + -6;
			Assert::AreEqual(di4.get_mem(), (int*)nullptr);
		}

		TEST_METHOD(plus_equals)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n; i++) {
				d.push_back(i); 
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			di += n / 2;
			Assert::AreEqual(di.get_mem(), d.get_mem() + d.get_lIndex() + n / 2 + 1);

			my_deque_iterator d2(d.get_mem() + d.get_lIndex() + 1, &d);
			d2 += n;
			Assert::AreEqual(d2.get_mem(), d.get_mem() + d.get_rIndex());

			d2 += -6;
			Assert::AreEqual(d2.get_mem(), (int*)nullptr);
		}

		TEST_METHOD(dereference)
		{
			my_deque d = my_deque(init_size);

			int j = 0;
			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);

			while (j < n) {
				Assert::AreEqual(*di, d[j]);
				++j;
				di += 1;
			}

			auto func = [] {my_deque d(32); d.push_back(5); my_deque_iterator di2(d.get_mem() + d.get_rIndex(), &d); *di2; };
			Assert::ExpectException<std::exception>(func);

			auto func2 = [] {my_deque d(32); d.push_back(5); my_deque_iterator di3((int*)nullptr, &d); *di3; };
			Assert::ExpectException<std::exception>(func2);
		}

		TEST_METHOD(less_than)
		{
			my_deque d = my_deque(init_size);
			int j = 0;

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			my_deque_iterator di2(d.get_mem() + d.get_lIndex() + n / 2 + 1, &d);
			Assert::IsTrue(di < di2);
			Assert::IsFalse(di2 < di);

			di += n / 2;
			Assert::IsFalse(di < di2);
			Assert::IsFalse(di2 < di);

			// invalid comparison
			auto func = [] {my_deque d(2); my_deque d2(2); my_deque_iterator di(d.get_mem() + d.get_rIndex(), &d); my_deque_iterator d2i(d2.get_mem() + d2.get_rIndex(), &d2); di < d2i; };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(equivalence)
		{
			my_deque d = my_deque(init_size);
			int j = 0;

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			my_deque_iterator di2(d.get_mem() + d.get_lIndex() + n / 2 + 1, &d);
			Assert::IsFalse(di2 == di);

			di += n / 2;
			Assert::IsTrue(di == di2);
		}

		TEST_METHOD(begin_end_traverse_and_access_all)
		{
			my_deque d = my_deque(init_size);
			int j = 0;

			for (int i = 0; i < n; i++) {
				d.push_back(i);
			}

			auto start = d.begin();
			Assert::AreEqual(start.get_mem(), &d[0]);

			auto end = d.end();
			Assert::AreEqual(end.get_mem(), d.get_mem() + d.get_rIndex());

			while (start < end) {
				Assert::AreEqual(*start, d[j]);
				++j;
				start += 1;
			}

			Assert::IsTrue(start == d.end());
			Assert::AreEqual(start.get_mem(), d.get_mem() + d.get_rIndex());
		}
	};
	
	// Below are the test case I designed
	TEST_CLASS(dequeiteratortestlarge)
	{
		TEST_METHOD(construct_past_the_end_large)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < n * 10; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_rIndex(), &d);
			Assert::AreEqual(d.get_mem() + d.get_rIndex(), di.get_mem());
		}

		TEST_METHOD(invalid_constructor_large)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			my_deque d2(4);
			d2.push_back(5);
			my_deque_iterator di(d2.get_mem(), &d);
			Assert::AreEqual(di.get_mem(), (int*)nullptr);

			my_deque_iterator di2(d.get_mem() - 1, &d);
			Assert::AreEqual(di2.get_mem(), (int*)nullptr);
		}

		TEST_METHOD(good_constructor_large)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			Assert::AreEqual(di.get_mem(), d.get_mem() + d.get_lIndex() + 1);

			my_deque_iterator di2(d.get_mem() + d.get_lIndex() + n / 2, &d);
			Assert::AreEqual(d.get_mem() + d.get_lIndex() + n / 2, di2.get_mem());
		}

		TEST_METHOD(addition_large)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			my_deque_iterator di2 = di + 10 * n / 2;
			Assert::AreEqual(di2.get_mem(), d.get_mem() + d.get_lIndex() + 10 * n / 2 + 1);

			my_deque_iterator di3 = di + 10 * n;
			Assert::AreEqual(di3.get_mem(), d.get_mem() + d.get_rIndex());

			my_deque_iterator di4 = di2 + -6;
			Assert::AreEqual(di4.get_mem(), (int*)nullptr);
		}

		TEST_METHOD(plus_equals_large)
		{
			my_deque d = my_deque(init_size);

			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			di += 10 * n / 2;
			Assert::AreEqual(di.get_mem(), d.get_mem() + d.get_lIndex() + 10 * n / 2 + 1);

			my_deque_iterator d2(d.get_mem() + d.get_lIndex() + 1, &d);
			d2 += 10 * n;
			Assert::AreEqual(d2.get_mem(), d.get_mem() + d.get_rIndex());

			d2 += -6;
			Assert::AreEqual(d2.get_mem(), (int*)nullptr);
		}

		TEST_METHOD(dereference_large)
		{
			my_deque d = my_deque(init_size);

			int j = 0;
			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);

			while (j < 10 * n) {
				Assert::AreEqual(*di, d[j]);
				++j;
				di += 1;
			}

			auto func = [] {my_deque d(32); d.push_back(5); my_deque_iterator di2(d.get_mem() + d.get_rIndex(), &d); *di2; };
			Assert::ExpectException<std::exception>(func);

			auto func2 = [] {my_deque d(32); d.push_back(5); my_deque_iterator di3((int*)nullptr, &d); *di3; };
			Assert::ExpectException<std::exception>(func2);
		}

		TEST_METHOD(less_than_large)
		{
			my_deque d = my_deque(init_size);
			int j = 0;

			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			my_deque_iterator di2(d.get_mem() + d.get_lIndex() + 10 * n / 2 + 1, &d);
			Assert::IsTrue(di < di2);
			Assert::IsFalse(di2 < di);

			di += 10 * n / 2;
			Assert::IsFalse(di < di2);
			Assert::IsFalse(di2 < di);

			// invalid comparison
			auto func = [] {my_deque d(2); my_deque d2(2); my_deque_iterator di(d.get_mem() + d.get_rIndex(), &d); my_deque_iterator d2i(d2.get_mem() + d2.get_rIndex(), &d2); di < d2i; };
			Assert::ExpectException<std::exception>(func);
		}
		
		TEST_METHOD(equivalence_large)
		{
			my_deque d = my_deque(init_size);
			int j = 0;

			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			my_deque_iterator di(d.get_mem() + d.get_lIndex() + 1, &d);
			my_deque_iterator di2(d.get_mem() + d.get_lIndex() + 10 * n / 2 + 1, &d);
			Assert::IsFalse(di2 == di);

			di += 10 * n / 2;
			Assert::IsTrue(di == di2);
		}

		TEST_METHOD(begin_end_traverse_and_access_all_large)
		{
			my_deque d = my_deque(init_size);
			int j = 0;

			for (int i = 0; i < 10 * n; i++) {
				d.push_back(i);
			}

			auto start = d.begin();
			Assert::AreEqual(start.get_mem(), &d[0]);

			auto end = d.end();
			Assert::AreEqual(end.get_mem(), d.get_mem() + d.get_rIndex());

			while (start < end) {
				Assert::AreEqual(*start, d[j]);
				++j;
				start += 1;
			}

			Assert::IsTrue(start == d.end());
			Assert::AreEqual(start.get_mem(), d.get_mem() + d.get_rIndex());
		}

	};


}

