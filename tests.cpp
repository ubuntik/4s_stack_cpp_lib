#include <iostream>

// because of template
#include "stack.cpp"

using namespace std;

void check_copy_constructor(stack<int> s)
{
	cout << s;
}

void check_copy_constructor(stack< stack<int> > s)
{
	cout << s;
}

int main()
{
	stack<int> *s1 = NULL;
	stack<int> *s2 = NULL;

/*
 * This is just for example to catch bad alloc
	try {
		s1 = new stack(-1);
	} catch (const bad_alloc& ex) {
		cout << "Test_0\t->\tPASSED" << endl;
	} catch (...) {
		cout << "Test_0\t->\tFAILED" << endl;
	}
*/
	try {
		s1 = new stack<int>(3);
	} catch (...) {
		cout << "Test_1\t->\tFAILED" << endl;
	}
	cout << "Test_1\t->\tPASSED" << endl;

	try {
		s2 = new stack<int>();
	} catch (...) {
		cout << "Test_2\t->\tFAILED" << endl;
	}
	cout << "Test_2\t->\tPASSED" << endl;

	try {
		s1->pop();
	} catch (const stack<int>::stack_error &ex) {
		if (ex == stack<int>::EEMPTY)
			cout << "Test_3\t->\tPASSED" << endl;
		else
			cout << "Test_3\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_3\t->\tFAILED" << endl;
	}

	try {
		s1->push(1);
	} catch (...) {
		cout << "Test_4\t->\tFAILED" << endl;
	}
	cout << "Test_4\t->\tPASSED" << endl;

	try {
		s1->push(2);
	} catch (...) {
		cout << "Test_5\t->\tFAILED" << endl;
	}
	cout << "Test_5\t->\tPASSED" << endl;

	try {
		s1->push(3);
	} catch (...) {
		cout << "Test_6\t->\tFAILED" << endl;
	}
	cout << "Test_6\t->\tPASSED" << endl;

	try {
		s1->push(4);
	} catch (const stack<int>::stack_error &ex) {
		if (ex == stack<int>::EFULL)
			cout << "Test_7\t->\tPASSED" << endl;
		else
			cout << "Test_7\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_7\t->\tFAILED" << endl;
	}

	try {
		*s2 = *s1;
	} catch (...) {
		cout << "Test_8\t->\tFAILED" << endl;
	}
	cout << "Test_8\t->\tPASSED" << endl;

	check_copy_constructor(*s1);
	check_copy_constructor(*s2);

	try {
		if (s2->pop() != 3)
			cout << "Test_9\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_9\t->\tFAILED" << endl;
	}
	cout << "Test_9\t->\tPASSED" << endl;

	try {
		if (s2->pop() != 2)
			cout << "Test_10\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_10\t->\tFAILED" << endl;
	}
	cout << "Test_10\t->\tPASSED" << endl;

	try {
		if (s2->pop() != 1)
			cout << "Test_11\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_11\t->\tFAILED" << endl;
	}
	cout << "Test_11\t->\tPASSED" << endl;

	try {
		s2->pop();
	} catch (const stack<int>::stack_error &ex) {
                if (ex == stack<int>::EEMPTY)
			cout << "Test_12\t->\tPASSED" << endl;
		else
			cout << "Test_12\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_12\t->\tFAILED" << endl;
	}

	stack< stack<int> > *s3 = NULL;

	try {
		s3 = new stack< stack<int> >(2);
	} catch (...) {
		cout << "Test_13\t->\tFAILED" << endl;
	}
	cout << "Test_13\t->\tPASSED" << endl;

	try {
		s3->push(*s2);
	} catch (...) {
		cout << "Test_14\t->\tFAILED" << endl;
	}
	cout << "Test_14\t->\tPASSED" << endl;

	try {
		s3->push(*s1);
	} catch (...) {
		cout << "Test_15\t->\tFAILED" << endl;
	}
	cout << "Test_15\t->\tPASSED" << endl;

	check_copy_constructor(*s3);

	stack<int> tmp;
	try {
		tmp = s3->pop();
	} catch (...) {
		cout << "Test_16\t->\tFAILED" << endl;
	}
	cout << "Test_16\t->\tPASSED" << endl;

	int val = 0;
	try {
		val = tmp.pop();
	} catch (...) {
		cout << "Test_17\t->\tFAILED" << endl;
	}
	if (val == 3)
		cout << "Test_17\t->\tPASSED" << endl;
	else
		cout << "Test_17\t->\tFAILED" << endl;

	delete s1;
	delete s2;
	delete s3;
	return 0;
}
