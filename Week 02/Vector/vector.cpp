#include "Vector.h"

#include <iostream>

#include <cmath>

using namespace std;

Vector::Vector(double a, double b){
    x = a;
    y = b;
}

void Vector::read() {
    cin >> x >> y;
}

void Vector::print() const {
    cout << "X: " << x << " Y: " << y << endl;
}

void Vector::add(const Vector& v) {
    x += v.x;
    y += v.y;
}

void Vector::substitude(const Vector* v) {
    x += v->x;
    y += (*v).y;
}

double Vector::scalarProduct(const Vector& v) const {
    return x * v.x + y * v.y;
}

double Vector::length() const {
    return sqrt(x * x + y * y);
}
