// reference : https://raytracing.github.io/books/RayTracingInOneWeekend.html

#include "vec3.h"
#include "color.h"

#include <iostream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            pixel_color = color(double(i)/(image_width -1), double(j)/(image_height-1), 0);
            write_color(std::out, pixel_color);
        }
    }

    std::out << "Done!" << '\n';
    return 0;
}