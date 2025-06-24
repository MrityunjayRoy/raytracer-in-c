// reference : https://raytracing.github.io/books/RayTracingInOneWeekend.html

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "utils.h"
#include "vec3.h"

color ray_color(const Ray &r, const Hittable &world) {
  hit_record rec;
  if (world.hit(r, interval(0, infinity), rec)) {
    return 0.5 * (rec.normal + color(1,1,1));
  }

  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {

  // Image
  auto aspect_ratio = 16.0 / 9.0;
  double image_width = 400.0;

  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  // World
  auto center_small = point3(0, 0, -5);
  auto center_big = point3(0, -100.5, -1);

  hittable_list world;
  world.add(make_shared<Sphere>(center_small, 4.5));
  world.add(make_shared<Sphere>(center_big, 100));

  // Camera
  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width) / image_height);
  auto camera_center = point3(0, 0, 0);

  auto viewport_u = vec3(viewport_width, 0, 0);
  auto viewport_v = vec3(0, -viewport_height, 0);

  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) -
                             viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc =
      viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  // Render

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      auto pixel_center =
          pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      Ray r(camera_center, ray_direction);

      color pixel_color = ray_color(r, world);
      write_color(std::cout, pixel_color);
    }
  }

  std::cout << "Done!" << '\n';
  return 0;
}