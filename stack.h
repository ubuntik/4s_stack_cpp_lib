#ifndef _STACK_H_
#define _STACK_H_

#include <cstring>
#include <iostream>

#define STACK_SIZE 10

using namespace std;

class stack
{
public:
	enum stack_error {
		EFULL = 1,
		EEMPTY,
		EINVARG
	};

	stack();
	stack(int size);
	stack(const stack &s);
	~stack();
	int pop();
	void push(int val);
	stack& operator=(const stack &s);

	int *data() const { return m_data; };
	int size() const { return m_size; };
	int current_size() const { return m_current_size; };

	friend ostream &operator<<(ostream &output, const stack &s) {
		output << "Stack: size " << s.size();
		output << " current size " << s.current_size() << endl;
		output << "data: " << (void*)s.data() << " [ ";
		for (int i = 0; i < s.current_size(); i++)
			output << s.data()[i] << " ";
		output << "]" << endl;
		return output;
	};

private:
	int *m_data;
	int m_size;
	int m_current_size;
};

#endif  // _STACK_H_
