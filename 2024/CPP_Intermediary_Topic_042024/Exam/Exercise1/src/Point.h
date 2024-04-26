#ifndef POINT_H
#define POINT_H

class Point
{
public:
	bool operator==(const Point& aOtherPoint) const;

  // add required methods
	Point(int x, int y);
	Point(const Point& rhs);

	// Rule of 3 
	~Point(){}
	Point& operator=(const Point& rhs){
		if(this != &rhs) {
			m_x = rhs.m_x;
			m_y = rhs.m_y;
		}
		return *this;
	}
	Point& operator+=(const Point& lhs);

	void printPoint();

	friend Point operator-(const Point& lhs, const Point& rhs);

private:
	int m_x;
	int m_y;
};

#endif