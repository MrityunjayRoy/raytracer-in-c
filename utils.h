#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// C++ Std usings
using std::make_shared;
using std::shared_ptr;

// Constants
const double pi = 3.1415926535897932385;

// Utility functions

inline double degree_to_radians(double degrees) { return degrees * pi / 180.0; }

// Common headers

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif