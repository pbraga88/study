#include "Polygon.h"
#include "Point.h"

Polygon::Polygon(const Polygon& src) {
  this->m_List = src.m_List;
}

void Polygon::addPoint(Point* p)
{
  m_List.addPoint(p);
}

Point Polygon::getPoint(int anArrayIndex)
{
	return *m_List[anArrayIndex];
}

void Polygon::removeAllPoints()
{
 // add implementation
  int itemsStored = m_List.itemsStored();
  for (int i = 0; i<itemsStored; i++) {
    delete m_List[i];
  }
}
