#include "Vector2D.h"
#include <fstream>

std::ostream& operator<<(std::ostream& os, const Vector2D& rhs)
{
	os << " " << rhs.m_x << " " << rhs.m_y;

	return os;
}


std::ifstream& operator>>(std::ifstream& is, Vector2D& lhs)
{
	is >> lhs.m_x >> lhs.m_y;

	return is;
}