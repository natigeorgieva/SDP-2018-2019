#ifndef VECTOR_H
#define VECTOR_H


struct Vector
{
    public:
    double x;
    double y;

    Vector(double a = 0, double b = 0);
    void read();
    void print() const;
    void add(const Vector& v);
    void substitude(const Vector* v);
    double scalarProduct(const Vector& v) const;
    double length() const;
};

#endif // VECTOR_H
