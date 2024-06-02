Answer any exam questions here
Name: Ningyuan XIe
WUSTL ID: 476378


1. Deep vs. Shallow copy: Does std::deque provide a deep copy constructor or a shallow copy constructor?

   Experiment code:

    deque<int> d_1 = { 1, 0, 2, 5 };
    cout << "Address of d_1 is " << &d_1 << "; " << endl ;

    deque<int> d_2 = d_1;
    cout << "Address of d_2 is " << &d_2 << ". " << endl;

   After initiating an deque d_1, I created another deque d_2 by copying d_1. If deque provides a shallow
   copy, both d_1 and d_2 would have the same address; if deque provides a deep copy, d_1 and d_2 would have
   different address.

   Console results (one of the tests):

	Address of d_1 is 0000005D02CFF4E8;
	Address of d_2 is 0000005D02CFF528.

   Conclusion: According to the console results, d_1 and d_2 have different address. Therefore, std::deque 
   provides a deep copy constructor.



2. Extra credit

   When I test my_deque in Part I, I found tests such as "push_mixed_pop_mixed_large" the most challenging
   part, as my code is not rigorous enough to handle large size cases where it needs to expand. As a result,
   I spent most of my time in this assginment debugging "push_back()" and "push_front()".
   
   After I passed all "dequeiteratortest" tests, I realized there were no test cases on large size deques. 
   Therefore, I modified the 9 tests from "dequeiteratortest" and created a series of "dequeiteratortestlarge" 
   tests, which insure that both Part I and Part II code are rigorous enough to deal with large size cases.
   Specifically, I multipled the number of elements in deque by 10, so deque would have to expand multiple
   times.

   Test cases include:

	construct_past_the_end_large;
	invalid_constructor_large;
	good_constructor_large;
	addition_large;
	plus_equals_large;
	dereference_large;
	less_than_large;
	equivalence_large;
	begin_end_traverse_and_access_all_large.

   I added these tests to "deque_test.cpp" and make sure all of them can be passed. Detailed code can be seen
   in "deque_test.cpp".
