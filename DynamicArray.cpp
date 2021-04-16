/******************************************************************************
*                                                                             *
*   Program : FileLogger                                                      *
*                                                                             *
*   Date : 15 / 04 / 2021                                                     *
*                                                                             *
*   Programmer : Nikita Seliverstov (nikselko)                                *
*                                                                             *
*                                                                             *
******************************************************************************/

#include "DynamicArray.h"

#define _CRT_SECURE_NO_WARNINGS

DynamicArray::DynamicArray(int size, double init) : m_size{ size }, m_array{ new double[m_size] }
{
	std::fill_n(m_array, size, init);

	if (init != 0) 
		s_tracker.add_memory((std::size_t)(m_size) * sizeof(double));
	else
		s_tracker.add_memory((std::size_t)(m_size));

	s_tracker.add_instance();
}

DynamicArray::DynamicArray(int size) : DynamicArray(size, 0) {}

const Tracker& DynamicArray::tracker()
{
	return s_tracker;
}

double* DynamicArray::get()
{
	return m_array;
}

const double* DynamicArray::get() const
{
	return m_array;
}

double& DynamicArray::at(int index)
{
	return m_array[index];
}

const double& DynamicArray::at(int index) const
{
	return m_array[index];
}

int DynamicArray::size() const
{
	return m_size;
}

DynamicArray::~DynamicArray()
{
	int empty_checker = 0;

	for (auto i = 0; i < m_size; i++)
		empty_checker = +at(i);

	if (empty_checker != 0)
		s_tracker.remove_memory((std::size_t)(m_size) * sizeof(at(0)));
	else
		s_tracker.remove_memory((std::size_t)(m_size));

	s_tracker.remove_instance();

	delete[] m_array;
}
