#ifndef POINT3_H
#define POINT3_H


class Point3
{
    public:
        Point3(const int = 0, const int = 0, const int = 0);
        int getX() const;
        int getY() const;
        int getZ() const;

        void setX(const int);
        void setY(const int);
        void setZ(const int);

        bool operator<(const Point3&) const;

    private:
        int x;
        int y;
        int z;
};

#endif // POINT3_H
