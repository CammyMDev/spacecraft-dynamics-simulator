#include <iostream>
#include "../include/spaceship.hpp"
#include "../include/physics.hpp"
#include "../include/gravitational_object.hpp"

#define EARTH_MASS 5.97219e24

int main (){
    double dt = 1.0;
    int steps = 1000;


    Vector3 acceleration;
    Spacecraft spacecraft(Vector3{6.771e6,0,0}, Vector3{0,0,0}, 200.0); //400 Km above surface
    gravitationalObject earth {Vector3{0,0,0}, EARTH_MASS};

    for (int i = 0; i < steps; i++){
        acceleration  = computeGravitationalAcceleration(spacecraft.getPosition(), earth);
        spacecraft.update(dt, acceleration);
        Vector3 pos = spacecraft.getPosition();
        std::cout << "Step " << i << ": " << pos.x << ", " << pos.y << ", " << pos.z << "\n";

    }
    
}