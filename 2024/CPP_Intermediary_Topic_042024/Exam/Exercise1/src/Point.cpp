#include <iostream>
#include "Point.h"

bool Point::operator==(const Point& aOtherPoint) const
{
    bool retVal = false;
    if (m_x == aOtherPoint.m_x &&
        m_y == aOtherPoint.m_y)
    {
        retVal = true;
    }

    return retVal;
}

Point::Point(int x, int y) : m_x(x), m_y(y) {}

Point::Point(const Point& rhs) {
    m_x = rhs.m_x;
    m_y = rhs.m_y;
}

Point& Point::operator+=(const Point& lhs) {
    this->m_x += lhs.m_x;
    this->m_y += lhs.m_y;
    return *this;
}

Point operator-(const Point& lhs, const Point& rhs) {
    return Point(lhs.m_x - rhs.m_y, lhs.m_x - rhs.m_y);
}

void Point::printPoint() {
    std::cout<<"x: "<<m_x<<std::endl;
    std::cout<<"y: "<<m_y<<std::endl;
}