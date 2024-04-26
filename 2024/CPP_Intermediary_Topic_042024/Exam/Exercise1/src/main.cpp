#include <iostream>
#include "Point.h"
#include "Polygon.h"
#define CHECK(a,b) check(a,b,__LINE__);
#define CHECKPOL(a,b,c) checkPol(a,b,c,__LINE__);

int check(const Point& a, const Point& b, int line, bool printOutput = true) {
  if (a == b)
  {
    if (printOutput) std::cout << "PASSED line:" << line << std::endl;
    return 0;
  }
  else
  {
    if (printOutput) std::cout << "FAILURE on line:" << line << std::endl;
    return -1;
  }
}

void checkPol(Polygon& pol, Point point1, Point point2, int line) {
  if ((check(pol.getPoint(0), point1, 0, false) == 0) &&
      (check(pol.getPoint(1), point2, 0, false) == 0) )
  {
    std::cout << "PASSED line:" << line << std::endl;
  }
  else
  {
    std::cout << "FAILURE on line:" << line << std::endl;
  }
}

int main(int argc, char* argv[])
{	
  // STEP1: make sure Point has all the required methods
  (void)argc;
  (void)argv;

  const Point p0(0,0);
  const Point p1(1,1);
  const Point p2(2,2);
  const Point p3(3,3);

  Point pointA(p1);
  Point pointB(p0);
  CHECK(pointA, p1);

  pointA += p2;
  CHECK(pointA, p3);

  pointB = pointA - p2; 
  CHECK(pointB, p1);
  CHECK(pointA, p3);
  //
  pointB.printPoint();  //hint: prints x and y

  // STEP2: make sure that your heap objects are properly managed: we do not want memory leaks !

  Point *polyPoint1 = new Point(1,18);
  Point *polyPoint2 = new Point(2,2);

  Polygon pol1, pol2;
  pol1.addPoint(polyPoint1);
  pol1.addPoint(polyPoint2);
  CHECKPOL(pol1, *polyPoint1, *polyPoint2);

  Point *polyPoint3 = new Point(3,19);
  Point *polyPoint4 = new Point(4,80);
  pol2.addPoint(new Point(3,19));
  pol2.addPoint(new Point(4,80));
  CHECKPOL(pol2, *polyPoint3, *polyPoint4);

  Polygon pol3(pol1);
  CHECKPOL(pol3, *polyPoint1, *polyPoint2);

  pol1 = pol2;
  CHECKPOL(pol1, *polyPoint3, *polyPoint4);

  pol3.removeAllPoints();
	
  return 0;
}
// Expected output:
// PASSED line:43
// PASSED line:46
// PASSED line:49
// PASSED line:50
// x:1 y:1
// PASSED line:62
// PASSED line:68
// PASSED line:71
// PASSED line:74