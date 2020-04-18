#include "stack.h"
#include <iostream>

using namespace std;

void check_copy_constructor(stack s)
{
	cout << s;
}

int main()
{
	stack *s1 = NULL;
	stack *s2 = NULL;

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
		s1 = new stack(3);
	} catch (...) {
		cout << "Test_2\t->\tFAILED" << endl;
	}
	cout << "Test_2\t->\tPASSED" << endl;

	try {
		s2 = new stack();
	} catch (...) {
		cout << "Test_3\t->\tFAILED" << endl;
	}
	cout << "Test_3\t->\tPASSED" << endl;

	try {
		s1->pop();
	} catch (const stack::stack_error &ex) {
		if (ex == stack::EEMPTY)
			cout << "Test_4\t->\tPASSED" << endl;
		else
			cout << "Test_4\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_4\t->\tFAILED" << endl;
	}

	try {
		s1->push(1);
	} catch (...) {
		cout << "Test_5\t->\tFAILED" << endl;
	}
	cout << "Test_5\t->\tPASSED" << endl;

	try {
		s1->push(2);
	} catch (...) {
		cout << "Test_6\t->\tFAILED" << endl;
	}
	cout << "Test_6\t->\tPASSED" << endl;

	try {
		s1->push(3);
	} catch (...) {
		cout << "Test_7\t->\tFAILED" << endl;
	}
	cout << "Test_7\t->\tPASSED" << endl;

	try {
		s1->push(4);
	} catch (const stack::stack_error &ex) {
		if (ex == stack::EFULL)
			cout << "Test_8\t->\tPASSED" << endl;
		else
			cout << "Test_8\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_8\t->\tFAILED" << endl;
	}

	try {
		*s2 = *s1;
	} catch (...) {
		cout << "Test_9\t->\tFAILED" << endl;
	}
	cout << "Test_9\t->\tPASSED" << endl;

	check_copy_constructor(*s1);
	check_copy_constructor(*s2);

	try {
		if (s2->pop() != 3)
			cout << "Test_10\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_10\t->\tFAILED" << endl;
	}
	cout << "Test_10\t->\tPASSED" << endl;

	try {
		if (s2->pop() != 2)
			cout << "Test_11\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_11\t->\tFAILED" << endl;
	}
	cout << "Test_11\t->\tPASSED" << endl;

	try {
		if (s2->pop() != 1)
			cout << "Test_12\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_12\t->\tFAILED" << endl;
	}
	cout << "Test_12\t->\tPASSED" << endl;

	try {
		s2->pop();
	} catch (const stack::stack_error &ex) {
                if (ex == stack::EEMPTY)
			cout << "Test_13\t->\tPASSED" << endl;
		else
			cout << "Test_13\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_13\t->\tFAILED" << endl;
	}

	delete s1;
	delete s2;
	return 0;
}
