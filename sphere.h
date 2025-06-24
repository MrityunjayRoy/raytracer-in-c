#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "interval.h"
#include "utils.h"
#include "vec3.h"

class Sphere : public Hittable {
public:
  Sphere(point3 &center, double radius)
      : center(center), radius(std::fmax(0, radius)) {}

  bool hit(const Ray &r, interval ray_t, hit_record &rec) const override {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto h = dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius * radius;

    auto discriminent = h * h - 4 * a * c;
    if (discriminent < 0) {
      return false;
    }

    auto sqrtd = std::sqrt(discriminent);

    auto root = (h - sqrtd) / a;
    if (!ray_t.surrounds(root)) {
      root = (h + sqrtd) / a;
      if (!ray_t.surrounds(root))
        return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
  }

private:
  point3 center;
  double radius;
};
#endif