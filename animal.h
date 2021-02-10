
#include <string>
#include <iostream>

static int g_id = 0;

class CAnimal;

std::ostream& operator<<(std::ostream& out, const CAnimal& ani);

class CAnimal
{
	int m_id;
public:
	CAnimal():m_id(g_id++){}
	// CAnimal(int id):m_id(id){}
	bool operator<(const CAnimal& other) const{return m_id <other.m_id;}
	friend std::ostream& operator<<(std::ostream& out, const CAnimal& ani);
};


