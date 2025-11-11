#include "../include/physics.hpp"
#include <cmath>
#include <iostream>

Vector3 computeGravitationalAcceleration(const Vector3& spaceshipPos, const gravitationalObject& body) {
    Vector3 displacement;
    double r;
    Vector3 unit_directon;
    double accelMagnitude;
    Vector3 acceleration;

    displacement = body.position - spaceshipPos;
    r = displacement.magnitude();
    unit_directon.x = displacement.x / r;
    unit_directon.y = displacement.y / r;
    unit_directon.z = displacement.z / r;

    accelMagnitude = (G * body.mass) / (r * r);

    acceleration.x = unit_directon.x * accelMagnitude;
    acceleration.y = unit_directon.y * accelMagnitude;
    acceleration.z = unit_directon.z * accelMagnitude;

    return acceleration;
}