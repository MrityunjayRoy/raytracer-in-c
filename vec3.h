#ifndef VEC3_H
#define VEC3_H

#include <math>
#include <iostream>

class vec3{
    public:
        double e[3];

        vec3() : e{0 ,0, 0} {}
        vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}
        
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3& v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];

            return *this;
        }

        vec3& operator*=(const vec3& v){
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            e[2] *= v.e[2];

            return *this;
        }

        vec3& operator*=(double t){
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;

            return *this;
        }

        vec3& operator/=(double t){
            return *this /= 1/t;
        }

        double length() const{
            return std::sqrt(length_squared())
        }

        double length_squared(){
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
}

using point3 = vec3;

inline std::ostream& operator<<(std::ostream, vec3& v){
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& v1, const vec3& v2){
    vec3 v3;

    v3.e[0] = v1.e[0] + v2.e[0];
    v3.e[1] = v1.e[1] + v2.e[1];
    v3.e[2] = v1.e[2] + v2.e[2];

    return v3;
}

inline vec3 operator-(const vec3& v2, const vec3& v1){
    vec3 v3;

    v3.e[0] = v2.e[0] - v1.e[0];
    v3.e[1] = v2.e[1] - v1.e[1];
    v3.e[2] = v2.e[2] - v1.e[2];

    return v3;
}

inline vec3 operator*(const vec3& v1, const vec3& v2){
    vec3 v3;

    v3.e[0] = v1.e[0] * v2.e[0];
    v3.e[1] = v1.e[1] * v2.e[1];
    v3.e[2] = v1.e[2] * v2.e[2];

    return v3;
}

inline vec3 operator*(double t, const vec3& v) {
    vec3 v2;

    v2.e[0] = v.e[0] * t;
    v2.e[1] = v.e[1] * t;
    v2.e[2] = v.e[2] * t;

    return v3;
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 dot(const vec3& v1, const vec3& v2){
    return   v1.e[0] * v2.e[0];
           + v1.e[1] * v2.e[1];
           + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2){
    return vec3();
}

inline vec3 unit_vector(const vec3& v){
    return v/v.length();
}

#endif