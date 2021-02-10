
#include <iostream>
#include <vector>
#include <algorithm>

#include "animal.h"

static char g_ids = 'A';

class CShelter;

std::ostream& operator<<(std::ostream& out, const CShelter& ani);

class CShelter
{
	// std::vector<std::reference_wrapper<CAnimal>> m_animals;
	std::vector<CAnimal> m_animals;
	char m_id;
public:
	CShelter():m_id(g_ids++){}
	// CShelter(char id):m_id(id){}
	bool operator==(const CShelter& other) const{return m_id == other.m_id;}
	friend std::ostream& operator<<(std::ostream& out, const CShelter& ani);
};



