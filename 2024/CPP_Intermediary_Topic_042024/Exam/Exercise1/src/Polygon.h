#ifndef POLYGON_H
#define POLYGON_H

#include "CollectionOfPoints.h"

class Polygon
{
public:
  Polygon(const Polygon& src);
  void addPoint(Point* p);
  void removeAllPoints();
  Point getPoint(int anArrayIndex);
  
  // add required methods
  Polygon(){}
  Polygon& operator=(const Polygon& rhs) {
    if (this != &rhs) {
      this->m_List = rhs.m_List;
    }
    return *this;
  }

private:
  CollectionOfPoints m_List;
};

#endif