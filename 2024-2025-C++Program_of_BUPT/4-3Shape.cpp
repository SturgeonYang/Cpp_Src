#include <iostream>
using namespace std;

// 定义Shape基类
class Shape {
    private:
        double area;
    public:
        void setArea(double b){
            area = b;
        }
        double getArea(){
            return area;
        }
};

// 定义Rectangle类，继承自Shape类
class Rectangle : public Shape {

    public:
        Rectangle(double leng,double wid){
            setArea(leng*wid);
        }
        double GetArea(){
            return getArea();
        }
};

// 定义Circle类，继承自Shape类
class Circle : public Shape {
    public:
        Circle(double r){
            setArea(3.14*r*r);
        }
        double GetArea(){
            return getArea();
        }
};

int main() {
    Rectangle rect(5, 3);
    Circle circle(2);

    cout <<  rect.GetArea() << endl;
    cout <<  circle.GetArea() << endl;

    return 0;
}