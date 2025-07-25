#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "utils.h"

#include "hittable.h"
#include "ray.h"

#include <vector>

class hittable_list : public Hittable {
public:
  std::vector<shared_ptr<Hittable>> objects;

  hittable_list() {}
  hittable_list(shared_ptr<Hittable> object) { add(object); }

  void clear() { objects.clear(); }

  void add(shared_ptr<Hittable> object) { objects.push_back(object); }

  bool hit(const Ray &r, interval ray_t, hit_record &rec) const override {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = ray_t.max;

    for (const auto &object : objects) {
      if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
        hit_anything = true;
        closest_so_far = temp_rec.t;
        rec = temp_rec;
      }
    }

    return hit_anything;
  }
};

#endif