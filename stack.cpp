#include "stack.h"
#include <stdlib.h>
#include <unistd.h>

template <class T>
stack<T>::stack()
{
	m_data = new T [STACK_SIZE];
	m_size = STACK_SIZE;
	m_current_size = 0;
}

template <class T>
stack<T>::stack(int size)
{
	m_data = new T [size];
	m_size = size;
	m_current_size = 0;
}


template <class T>
stack<T>::stack(const stack &s)
{
	m_data = new T [s.size()];
	m_size = s.size();
	m_current_size = s.current_size();
	for (int i = 0; i < m_current_size; i++)
		m_data[i] = s.data()[i];
}

template <class T>
stack<T>::~stack()
{
	delete [] m_data;
	m_data = NULL;
}

template <class T>
T stack<T>::pop()
{
	if (m_current_size == 0) {
		cerr << "Stack is empty" << endl;
		throw EEMPTY;
	}
	return m_data[--m_current_size];
}

template <class T>
void stack<T>::push(T val)
{
	if (m_current_size == m_size) {
		cerr << "Stack is full" << endl;
		throw EFULL;
	}
	m_data[m_current_size++] = val;
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T> &s)
{
	delete [] m_data;
	m_data = new T [s.size()];
	m_size = s.size();
	m_current_size = s.current_size();
	for (int i = 0; i < m_current_size; i++)
		m_data[i] = s.data()[i];
	return *this;
}

