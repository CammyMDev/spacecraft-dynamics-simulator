#include "include/spaceship.hpp"


Spacecraft::Spacecraft(const Vector3& pos, const Vector3& vel, double m)
    : position(pos), velocity(vel), mass(m) {}


Vector3 Spacecraft::getPosition() const {
    return position;
}

Vector3 Spacecraft::getVelocity() const {
    return velocity;
}

void Spacecraft::update(double dt){
    //TODO
}