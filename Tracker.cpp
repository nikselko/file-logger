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

#include "Tracker.h"

Tracker::Tracker() : m_instance_count(0), m_memory_count(0) {}

void Tracker::add_instance()
{
	m_instance_count++;
}

void Tracker::remove_instance()
{
	m_instance_count--;
}

void Tracker::add_memory(std::size_t memory)
{
	m_memory_count = m_memory_count + memory;
}

void Tracker::remove_memory(std::size_t memory)
{
	m_memory_count = m_memory_count - memory;
}

std::size_t Tracker::memory() const
{
	return m_memory_count;
}

std::size_t Tracker::instances() const
{
	return m_instance_count;
}