// reference : https://raytracing.github.io/books/RayTracingInOneWeekend.html

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "utils.h"
#include "vec3.h"

int main() {
  // World
  auto center_small = point3(0, 0, -5);
  auto center_big = point3(0, -100.5, -1);

  hittable_list world;
  world.add(make_shared<Sphere>(center_small, 4.5));
  world.add(make_shared<Sphere>(center_big, 100));

  Camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 400;

  return 0;
}