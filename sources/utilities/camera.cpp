#include "utilities/camera.hpp"

Camera::Camera() { }
Camera::~Camera() noexcept { }

// Setters
void Camera::pos(const Vec3<float>& p) noexcept { mPos = p; }
void Camera::look(const Vec3<float>& l) noexcept { mLook = l; }

// Getters
Vec3<float> Camera::pos() const noexcept { return mPos; }
Vec3<float> Camera::look() const noexcept { return mLook; }