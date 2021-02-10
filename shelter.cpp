
#include "shelter.h"


std::ostream& operator<<(std::ostream& out, const CShelter& ani)
{
	out<<"shelter[\'"<<ani.m_id<<"\']";
	return out;
}

