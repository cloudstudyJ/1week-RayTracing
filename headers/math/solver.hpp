#pragma once

#include "math/vector/vec3.hpp"

class Ray;
class Sphere;

class Solver {
    Solver() = delete;
    Solver(const Solver&) = delete;
    Solver(Solver&&) noexcept = delete;
    ~Solver() noexcept = delete;

    Solver& operator=(const Solver&) = delete;
    Solver& operator=(Solver&&) noexcept = delete;

    public:
        static bool isHitSphere(const Ray&, const Sphere&) noexcept;

        static Vec3<float> lerpColor(const Ray&) noexcept;
};