#include <iostream>
#include "../include/spaceship.hpp"
#include "../include/physics.hpp"
#include "../include/gravitational_object.hpp"
#include <SFML/Graphics.hpp>

constexpr double EARTH_MASS = 5.97219e24;
const double SCALE = 1.0 / 50000.0; //1 Pixel is equel to 50km


sf::Vector2f toScreen(double x, double y){
    return {
        (float)(400 + x * SCALE),
        (float)(300 - y * SCALE)
    };
};


int main (){
    double dt = 1.0 / 240; //Setting this to scale to my Monitor
    std::vector<sf::Vertex> trail;

    Vector3 acceleration;
    Spacecraft spacecraft(Vector3{6.771e6,0,0}, Vector3{0,7669,0}, 200.0); //400 Km above surface
    gravitationalObject earth {Vector3{0,0,0}, EARTH_MASS};


    sf::RenderWindow window(sf::VideoMode({800, 600}), "Spacecraft Dynamics Simulator");
    window.setFramerateLimit(240);

    float earthRadius = (float)(6.371e6 * SCALE);
    sf::CircleShape earthShape(earthRadius);
    earthShape.setFillColor(sf::Color(29, 158, 117));
    earthShape.setOrigin({earthRadius, earthRadius});
    earthShape.setPosition(toScreen(0, 0));



    sf::CircleShape dot(5);
    dot.setFillColor(sf::Color::White);

        while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        acceleration  = computeGravitationalAcceleration(spacecraft.getPosition(), earth);
        spacecraft.update(dt, acceleration);

        Vector3 pos = spacecraft.getPosition();

        sf::Vector2f screenPos = toScreen(pos.x, pos.y);

        sf::Vertex v;
        v.position = screenPos;
        v.color = sf::Color::White;
        trail.push_back(v);
        dot.setPosition(screenPos);

        std::cout << "Postion: " << pos.x << ", " << pos.y << ", " << pos.z << "\n";
 
      
        window.clear();
        window.draw(earthShape);
        window.draw(trail.data(), trail.size(), sf::PrimitiveType::LineStrip);
        window.draw(dot);
        window.display();
    }

}


