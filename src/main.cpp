#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "../include/spaceship.hpp"
#include "../include/physics.hpp"
#include "../include/gravitational_object.hpp"
#include <SFML/Graphics.hpp>

int startSim(double &spaceshipVelocity, int &planetSelection, double &spaceshipStartLocation);
void print_boot_screen();
void sleep_ms(int ms);
void print_slow(const std::string& text, int delay_ms = 60);
sf::Vector2f toScreen(double x, double y, unsigned int width, unsigned int height);
void configuration(int &planetSelection, double &spaceshipVelocity, double &spaceshipStartLocation);

const std::string RESET   = "\033[0m";
const std::string GREEN   = "\033[32m";
const std::string BGREEN  = "\033[92m";
const std::string CYAN    = "\033[96m";
const std::string AMBER   = "\033[33m";
const std::string RED     = "\033[91m";
const std::string DIM     = "\033[2m";
const std::string WHITE   = "\033[97m";

const double SCALE = 1.0 / 50000.0; //1 Pixel is equel to 50km



int main (){
    int planetSelection;
    double spaceshipVelocity;
    double spaceshipStartLocation;
    

    print_boot_screen();
    configuration(planetSelection, spaceshipVelocity, spaceshipStartLocation);

    

    startSim(spaceshipVelocity, planetSelection, spaceshipStartLocation);
}

sf::Vector2f toScreen(double x, double y, unsigned int width, unsigned int height){
    return {
        (float)(width / 2 + x * SCALE),
        (float)(height / 2 - y * SCALE)
    };
};

void print_boot_screen() {
    

    std::cout << "\033[2J\033[H";

    // Banner box
    std::cout << GREEN;
    print_slow("╔══════════════════════════════════════════════════════════════════╗", 20);
    print_slow("║                                                                  ║", 20);

    std::cout << BGREEN;
    print_slow("║        ███████╗ ██████╗███████╗    ██████╗ ██╗   ██╗███████╗     ║", 20);
    print_slow("║        ██╔════╝██╔════╝██╔════╝    ██╔══██╗╚██╗ ██╔╝██╔════╝     ║", 20);
    print_slow("║        ███████╗██║     ███████╗    ██║  ██║ ╚████╔╝ ███████╗     ║", 20);
    print_slow("║        ╚════██║██║     ╚════██║    ██║  ██║  ╚██╔╝  ╚════██║     ║", 20);
    print_slow("║        ███████║╚██████╗███████║    ██████╔╝   ██║   ███████║     ║", 20);
    print_slow("║        ╚══════╝ ╚═════╝╚══════╝    ╚═════╝    ╚═╝   ╚══════╝     ║", 20);

    std::cout << GREEN;
    print_slow("║                                                                  ║", 20);

    std::cout << CYAN;
    print_slow("║             S P A C E C R A F T   D Y N A M I C S                ║", 20);
    print_slow("║                     S I M U L A T O R  v1.0                      ║", 20);

    std::cout << GREEN;
    print_slow("║                                                                  ║", 20);
    print_slow("╚══════════════════════════════════════════════════════════════════╝", 20);

    std::cout << RESET << std::endl;

    // ASCII Rocket
    std::cout << WHITE;
    print_slow("                          /\\", 15);
    print_slow("                         /  \\", 15);
    print_slow("                        | () |", 15);
    print_slow("                        |    |", 15);
    print_slow("                       /|    |\\", 15);
    print_slow("                      / |    | \\", 15);
    print_slow("                     /__|____|__\\", 15);
    print_slow("                        |    |", 15);

    std::cout << AMBER;
    print_slow("                       /|    |\\", 15);
    print_slow("                      / |    | \\", 15);

    std::cout << RED;
    print_slow("                     *  | __ |  *", 15);
    print_slow("                      * |/__\\| *", 15);
    print_slow("                         \\  /", 15);
    print_slow("                          \\/", 15);

    std::cout << RESET << std::endl;

    std::cout << DIM + GREEN;
    print_slow("──────────────────────────────────────────────────────────────────", 10);
}


void configuration(int &planetSelection, double &       spaceshipVelocity, double &spaceshipStartLocation){
    

    std::cout << CYAN;
    std::cout << "[*] Select Planet" << std::endl;
    std::cout << "[*] 1. Earth" << std::endl;
    std::cin >> planetSelection;

    std::cout << "[*] Select Spaceship Velocity: " << std::endl;
    std::cin >> spaceshipVelocity;
    std::cout << "[*] Select Spaceship Location above Surface (km): " << std::endl;
    std::cin >> spaceshipStartLocation;
    std::cout << RESET << std::endl;

    std::cout << GREEN;
    print_slow("  [*]  Loading orbital mechanics module...");
    print_slow("  [*]  Calibrating attitude control system...");
    print_slow("  [*]  Linking propulsion telemetry...");
    print_slow("  [*]  Running Gravity Simulation...");

    std::cout << RESET << std::endl;
    std::cout << DIM + GREEN;
    print_slow("──────────────────────────────────────────────────────────────────", 10);
    std::cout << RESET << std::endl;

    std::cout << CYAN;
    print_slow("  SPACECRAFT DYNAMICS SIMULATOR  |   By Cameron McKay");
    std::cout << RESET << std::endl;

    sleep_ms(1000);

}


int startSim(double &spaceshipVelocity, int &planetSelection, double &spaceshipStartLocation){
    double MASS;

    switch(planetSelection){
        case 1:
            MASS = 5.97219e24;
            break;
        default:
            std::cout << "[*]Invalid Selection" << std::endl;
            return 1;
    }
    

    double altituteMeters = spaceshipStartLocation * 1000;
    double distanceFromCenter = 6.371e6 + altituteMeters;
    
    double dt = 1.0 / 240; //Setting this to scale to my Monitor
    std::vector<sf::Vertex> trail;

    Vector3 acceleration;
    Spacecraft spacecraft(Vector3{distanceFromCenter,0,0}, Vector3{0,spaceshipVelocity,0}, 200.0); //400 Km above surface
    gravitationalObject earth {Vector3{0,0,0}, MASS};

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(desktop, "Spacecraft Dynamics Simulator");

    window.setFramerateLimit(240);
    auto size = window.getSize();

    //Creating Earth Circle
    float earthRadius = (float)(6.371e6 * SCALE);
    sf::CircleShape earthShape(earthRadius);
    earthShape.setFillColor(sf::Color(29, 158, 117));
    earthShape.setOrigin({earthRadius, earthRadius});
    earthShape.setPosition(toScreen(0, 0, size.x, size.y));


    //Creating Spaceship Object
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

        

        sf::Vector2f screenPos = toScreen(pos.x, pos.y, size.x, size.y);

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
    return 0;
}


void sleep_ms(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void print_slow(const std::string& text, int delay_ms) {
    std::cout << text << std::endl;
    sleep_ms(delay_ms);
}


