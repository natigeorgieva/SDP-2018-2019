#include "Point3.h"

Point3::Point3(const int x, const int y, const int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

int Point3::getX() const{
    return this->x;
}

int Point3::getY() const{
    return this->y;
}

int Point3::getZ() const{
    return this->z;
}

void Point3::setX(const int x){
    this->x = x;
}

void Point3::setY(const int y){
    this->y = y;
}

void Point3::setZ(const int z){
    this->z = z;
}

bool Point3::operator<(const Point3& other) const{
    return this->x < other.x ||
        (this->x == other.x && this->y < other.y) ||
        (this->x == other.x && this->y == other.y && this->z < other.z);
}
