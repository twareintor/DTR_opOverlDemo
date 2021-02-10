
#include "animal.h"


std::ostream& operator<<(std::ostream& out, const CAnimal& ani)
{
	out<<std::hex<<"animal["<<ani.m_id<<"]"<<std::dec;
	return out;
}

