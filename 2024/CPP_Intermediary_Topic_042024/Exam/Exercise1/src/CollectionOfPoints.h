#ifndef POLPOINTS_H
#define POLPOINTS_H

#include <vector>
class Point;

class CollectionOfPoints
{
public:
  void addPoint(Point* pPoint);
  Point* operator[](int index) const;
  int itemsStored() const;
  
  // add required methods
  void printList();
  
private:
  std::vector<Point*> m_list;
};

#endif