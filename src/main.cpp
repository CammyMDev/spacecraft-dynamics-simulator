#include <iostream>
#include "../include/spaceship.hpp"
#include "../include/physics.hpp"
#include "../include/gravitational_object.hpp"

#define EARTH_MASS 5.97219e24
// Step 1: Define the spaceship
// - Store position, velocity, and mass
// - Provide methods to update its state and retrieve position/velocity

// Step 2: Define the gravitational object (Earth to start)
// - Store mass and position (can start at origin)
// - Used to calculate gravitational acceleration on the spaceship

// Step 3: Apply physics to the spaceship
// - Compute gravitational acceleration from Earth
// - Update spaceship velocity and position over each timestep
// - Run in a simulation loop to observe motion

// Step 4: Observe results
// - Output position (console or file) to verify physics behavior
// - Confirm trajectory behaves as expected (e.g., circular or elliptical orbit)


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