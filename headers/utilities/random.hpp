#pragma once

#include "math/vector/vec3.hpp"

#include <random>

class Random {
    Random() = delete;
    Random(const Random&) = delete;
    Random(Random&&) noexcept = delete;
    ~Random() noexcept = delete;

    Random& operator=(const Random&) = delete;
    Random& operator=(Random&&) noexcept = delete;

    public:
        template <typename T, typename U1, typename U2>
        static inline Vec<T, 3> Vec3(const U1&, const U2&) noexcept;

        template <typename T, typename U1, typename U2>
        static inline T range(const U1&, const U2&) noexcept;

    private:
        static std::random_device rd;
        static std::mt19937 engine;
};

template <typename T, typename U1, typename U2>
inline Vec<T, 3> Random::Vec3(const U1& min, const U2& max) noexcept {
    std::uniform_real_distribution<T> dis(static_cast<T>(min), static_cast<T>(max));

    return { dis(engine), dis(engine), dis(engine) };
}

template <typename T, typename U1, typename U2>
inline T Random::range(const U1& min, const U2& max) noexcept {
    using distribution = IF<
        isInteger<T>,
        std::uniform_int_distribution<T>,
        std::uniform_real_distribution<T>
    >;

    distribution dis(static_cast<T>(min), static_cast<T>(max));
    return dis(engine);
}