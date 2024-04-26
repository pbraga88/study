//
// TopDisc.cpp
//
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

#include "TopDisc.h"


// Implement the functions as defined in the TopDisc class
int	TopDisc::m_Identifier {0};

TopDisc::TopDisc()
{
		m_Data = new char[max_capacity]; 
}

TopDisc::~TopDisc() {
	delete []m_Data;
}

TopDisc::TopDisc(const char* pszDefaultContents, int max_cap) : max_capacity(max_cap)
{
	Initialize(pszDefaultContents);
}

TopDisc::TopDisc(const TopDisc& rhs) : max_capacity(rhs.max_capacity)
{
	m_Data = new char[max_capacity];
	strcpy(m_Data, rhs.m_Data);
}

TopDisc& TopDisc::operator=(const TopDisc& rhs) {
	if(this != &rhs) {
		delete []m_Data;
		m_Data = nullptr;
		m_Data = new char[rhs.max_capacity];
		strcpy(m_Data, rhs.m_Data);
		max_capacity = rhs.max_capacity;
	}
	return *this;
}

int TopDisc::getId()
{
	return unique_identifier;
}

int TopDisc::get_capacity() {
	return max_capacity;
}

void TopDisc::copyContentFrom(const TopDisc &other)
{
  Initialize(other.m_Data);
}

const char* TopDisc::Read()
{
	return m_Data;
}	

void TopDisc::Write(const char* p_NewData)
{
	Initialize( p_NewData );
}

void TopDisc::Initialize( const char* pszData )
{
	m_Data = new char[max_capacity];
	strncpy(m_Data, pszData , max_capacity);
}
