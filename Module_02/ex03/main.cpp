#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

void printTriangle(Point const a, Point const b, Point const c, Point const p) {
    int width = 10;
    int height = 10;

    for (int y = height; y >= 0; --y) {
        for (int x = 0; x <= width; ++x) {
            if ((int)a.getXValue() == x && (int)a.getYValue() == y) 
                std::cout << "A";
            else if ((int)b.getXValue() == x && (int)b.getYValue() == y) 
                std::cout << "B";
            else if ((int)c.getXValue() == x && (int)c.getYValue() == y)
                std::cout << "C";
            else if ((int)p.getXValue() == x && (int)p.getYValue() == y)
                std::cout << "P";
            else 
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const Point a(1.0f, 1.0f);
    const Point b(9.0f, 3.0f);
    const Point c(4.0f, 7.0f);
    const Point p1(4.0f, 3.0f);
    const Point p2(4, 2);
    const Point p3(a);
   
    Point p4 = b;
    std::cout << "Coord Point p4(" << (int)p4.getXValue() << ", " << (int)p4.getYValue() << ")" << std::endl;

    bool flag;

    //  TEST N_1 //
    std::cout << "=>Test 1 - Basic: " << std::endl;
    std::cout << "Coord Point a(" << (int)a.getXValue() << ", " << (int)a.getYValue() << ")" << std::endl;
    std::cout << "Coord Point b(" << (int)b.getXValue() << ", " << (int)b.getYValue() << ")" << std::endl;
    std::cout << "Coord Point c(" << (int)c.getXValue() << ", " << (int)c.getYValue() << ")" << std::endl;
    std::cout << "\nPoint to check p("<< (int)p1.getXValue() << ", " << (int)p1.getYValue() << ")" << std::endl;
    printTriangle(a, b, c, p1);
    flag = bsp(a, b, c, p1);
    std::cout << "RESULT = "; 
    if (flag)
        std::cout << "Point inside triangle ABC" << std::endl;
    else
        std::cout << "Point outside triangle ABC or edge case" << std::endl;
    

    //  TEST N_2 //
    std::cout << "\n=>Test 2: " << std::endl;
    std::cout << "Coord Point a(" << (int)a.getXValue() << ", " << (int)a.getYValue() << ")" << std::endl;
    std::cout << "Coord Point b(" << (int)b.getXValue() << ", " << (int)b.getYValue() << ")" << std::endl;
    std::cout << "Coord Point c(" << (int)c.getXValue() << ", " << (int)c.getYValue() << ")" << std::endl;
    std::cout << "\nPoint to check p("<< (int)p2.getXValue() << ", " << (int)p2.getYValue() << ")" << std::endl;
    printTriangle(a, b, c, p2);
    flag = bsp(a, b, c, p2);
    std::cout << "RESULT = "; 
    if (flag)
        std::cout << "Point inside triangle ABC" << std::endl;
    else
        std::cout << "Point outside triangle ABC or edge case" << std::endl;
    
    //  TEST N_3 //
    std::cout << "\n=>Test 3 - Edge case: " << std::endl;
    std::cout << "Coord Point a(" << (int)a.getXValue() << ", " << (int)a.getYValue() << ")" << std::endl;
    std::cout << "Coord Point b(" << (int)b.getXValue() << ", " << (int)b.getYValue() << ")" << std::endl;
    std::cout << "Coord Point c(" << (int)c.getXValue() << ", " << (int)c.getYValue() << ")" << std::endl;
    std::cout << "\nPoint to check p("<< (int)p3.getXValue() << ", " << (int)p3.getYValue() << ")" << std::endl;
    printTriangle(a, b, c, p3);
    flag = bsp(a, b, c, p3);
    std::cout << "RESULT = "; 
    if (flag)
        std::cout << "Point inside triangle ABC" << std::endl;
    else
        std::cout << "Point outside triangle ABC or edge case" << std::endl;
    
    return 0;
}