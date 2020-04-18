#include "stack.h"
#include <stdlib.h>
#include <unistd.h>

stack::stack()
{
	m_data = new int [STACK_SIZE];
	m_size = STACK_SIZE;
	m_current_size = 0;
}

stack::stack(int size)
{
	m_data = new int [size];
	m_size = size;
	m_current_size = 0;
}

stack::stack(const stack &s)
{
	m_data = new int [s.size()];
	m_size = s.size();
	m_current_size = s.current_size();
	memcpy(m_data, s.data(), m_size * sizeof(int));
}

stack::~stack()
{
	delete [] m_data;
	m_data = NULL;
}

int stack::pop()
{
	if (m_current_size == 0) {
		cerr << "Stack is empty" << endl;
		throw EEMPTY;
	}
	return m_data[--m_current_size];
}

void stack::push(int val)
{
	if (m_current_size == m_size) {
		cerr << "Stack is full" << endl;
		throw EFULL;
	}
	m_data[m_current_size++] = val;
}

stack& stack::operator=(const stack &s)
{
	delete [] m_data;
	m_data = new int [s.size()];
	m_size = s.size();
	m_current_size = s.current_size();
	memcpy(m_data, s.data(), m_size * sizeof(int));
	return *this;
}

