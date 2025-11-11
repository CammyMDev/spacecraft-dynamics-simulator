#pragma once
#include<cmath>
struct Vector3
{
    double x;
    double y;
    double z;

    Vector3 operator-(const Vector3& other) const{
        return{x - other.x, y - other.y, z - other.z};
    }

    double magnitude(){
        return std::sqrt(x*x + y*y + z*z);
    }
};
