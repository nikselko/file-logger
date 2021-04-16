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

#pragma once

#include "Tracker.h"
#include "includes.h"

class DynamicArray
{
public:
	DynamicArray(int size, double init);
	DynamicArray(int size);
	~DynamicArray();

	double* get(); 
	const double* get() const;
	
	double& at(int index); 
	const double& at(int index) const;
	int size() const;

	static const Tracker& tracker();

private:
	int m_size;
	double* m_array;

	static inline Tracker s_tracker{};
};

