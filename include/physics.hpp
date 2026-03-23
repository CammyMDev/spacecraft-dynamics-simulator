#pragma once 

#include "gravitational_object.hpp"
#include "vector3.hpp"
constexpr double GRAV_CONST = 6.67430e-11;

Vector3 computeGravitationalAcceleration(const Vector3& spaceshipPos, const gravitationalObject& body);