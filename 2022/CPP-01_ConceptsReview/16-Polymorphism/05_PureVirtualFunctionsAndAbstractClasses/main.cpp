// Section 16
// Using Base class pointers

#include <iostream>
#include <vector>


/* The declaration of virtual functions below assigning the value of '0' (e.g: virtual void draw() = 0;), makes this class 
an 'Abstract Class', meanings that it can not be instantiated by any means. It's possible to only derive it.
   This one will be the 'Abstract Base Class'.
*/
class Shape {
private:
    //attributes common to all shapes

public:
    virtual void draw() = 0; // pure virtual function
    virtual void rotate() = 0; // pure virtual function
    virtual ~Shape() {}
};

/* Note that the below class is also abstract. It is due to the fact that it's not overriding the derived Shape class methods. */
class Open_Shape : public Shape { // Abstract Class
public:
    virtual ~Open_Shape() {}
};
/* Same as above. */
class Closed_Shape : public Shape { // Abstract Class
public:
    virtual ~Closed_Shape() {}
};

/* Now, the below class is 'Concrete'. This is becaused it derive the abstract classes above and override the pure virtual methods */
class Line : public Open_Shape { // Concrete Class
public:
    virtual void draw() override {
        std::cout<<"Drawing a line"<<std::endl;
    }
    virtual void rotate() override {
        std::cout<<"Rotating a line"<<std::endl;
    }
    virtual ~Line() {}
};
/* Same as above */
class Circle : public Closed_Shape { // Concrete Class
public:
    virtual void draw() override {
        std::cout<<"Drawing a circle"<<std::endl;
    }
    virtual void rotate() {
        std::cout<<"Rotating a circle"<<std::endl;
    }
    virtual ~Circle() {}
};
/* Same as above */
class Square : public Closed_Shape { // Concrete Class
public:
    virtual void draw() override {
        std::cout<<"Drawing a square"<<std::endl;
    }
    virtual void rotate() {
        std::cout<<"Rotating a square"<<std::endl;
    }
    virtual ~Square() {}
};

// Call objects methods 
void screen_refresh(std::vector<Shape*> &shapes) {
    std::cout<<"Refreshing screen"<<std::endl;
    for (const auto shape:shapes) {
        shape->draw();
        shape->rotate();
    }
}

int main() {
   /* The below calls will cause a compilation error, since it's not possible
    to instantiate objects of Abstract Class Type (Shape, Open_Shape and Closed_Shape)*/
    // Shape s;
    // Open_Shape os;
    // Closed_Shape cs;


    /* When a pointer to a Concrete Class object is istantiated, it works */
    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();

    std::vector<Shape*> shapes {s1, s2, s3};
    screen_refresh(shapes);

    delete s1;
    delete s2;
    delete s3;

    return 0;
}