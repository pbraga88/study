#include <iostream>
#include "CollectionOfPoints.h"
#include "Point.h"


void CollectionOfPoints::addPoint(Point* pPoint)
{
  // pPoint->printPoint();
  m_list.push_back(pPoint);						// this stores the pPoint pointer in m_list
};
void CollectionOfPoints::printList() {
  for(auto& item : m_list){
    item->printPoint();
  }
}

Point* CollectionOfPoints::operator[](int index) const
{
  return m_list[index];								// this returns element index from m_list
}

int CollectionOfPoints::itemsStored() const
{
  return m_list.size();								// this returns the amount of items in m_list
}

//TIP: use m_list.clear() to remove all elements from the list