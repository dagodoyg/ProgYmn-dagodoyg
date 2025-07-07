// main_md.cpp
// g++ -std=c++17 -g particle.cpp main_visual_md.cpp -lsfml-window -lsfml-graphics -lsfml-system
#include "particle.h"
#include "integrator.h"
#include "collider.h"
#include "boundary.h"
#include <vector>
#include <random>
#include <algorithm>

#include <SFML/Graphics.hpp>

void initial_conditions(std::vector<Particle> & particles, double min_p_rad, double max_p_rad);

int main(int argc, char **argv) {
  std::vector<Particle> bodies; // only one particle for now
  bodies.resize(200);
  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 100.8767;
  p["DT"] = 0.01;
  p["G"] = 0.0; //-9.81;
  p["K"] = 200.543;
  p["MIN_prad"] = 0.05;
  p["MAX_prad"] = 0.1;

  // window
  const int WIDTH = 1800, HEIGHT = 1000;
  const float METERS_TO_PIXELS = 75.0f; // 200 pixels per meter
  
  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // Boundary conditions
  Boundary bc(6, 0.0, 0.0, 0.0, 1.0); // RMAX, CX, CY, CZ, EN

  // initial conditions and properties
  initial_conditions(bodies,p["MIN_prad"],p["MAX_prad"]);
  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  std::cout << p["T0"] << "\t";

  // --- VISUALIZATION SETUP ---
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "C++ Simulation & Visualization");
  window.setFramerateLimit(120);
  sf::CircleShape particle_shape(bodies[0].rad);
  particle_shape.setFillColor(sf::Color::Cyan);
  particle_shape.setOrigin(0, 0);

  sf::CircleShape circle(2.345*METERS_TO_PIXELS); // Radius of 50 pixels
  circle.setFillColor(sf::Color::Green);
  circle.setOutlineThickness(20);
  circle.setOutlineColor(sf::Color::Black);
  circle.setPosition(100, 100); // Position at (100, 100)

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter && window.isOpen(); ++ii) {
    // check close event
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    // md simul
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
    bc.apply(bodies);

    // 2. Run the C++ visualization
    sf::Color windowColor(0,200,0);
    window.clear(windowColor);
    for (const auto& p : bodies) {
      float pixel_radius = p.rad * METERS_TO_PIXELS;
      // Set the radius for this specific particle, scaled to pixels
      particle_shape.setRadius(pixel_radius);
      // Center the origin so setPosition() refers to the center of the circle
      particle_shape.setOrigin(pixel_radius, pixel_radius);

      sf::Color particleColor(p.rad*255/0.5,p.rad*255/0.5,p.rad*255/0.5);
      particle_shape.setFillColor(particleColor);

      // Convert world coordinates to screen coordinates
      sf::Vector2f screen_pos;
      screen_pos.x = (WIDTH / 2.0f) + (p.R[0] * METERS_TO_PIXELS);
      // Flip the Y-axis: (HEIGHT - world_y_in_pixels)
      screen_pos.y = (HEIGHT / 2.0f) - (p.R[2] * METERS_TO_PIXELS);
      
      particle_shape.setPosition(screen_pos);
      window.draw(particle_shape);
    }
    window.display();

    // // print local info
    // double time = p["T0"] + ii*p["DT"];
    // std::cout << time << "\t";
    // bodies[0].print();
    // std::cout << "\n";
  }

  return 0;
}

void initial_conditions(std::vector<Particle> & particles, double min_p_rad, double max_p_rad){

  std::random_device random;
  std::mt19937 gen(random());
  std::uniform_real_distribution<> distrib_R(-1.0, 1.0);
  std::uniform_real_distribution<> distrib_V(-5.0, 5.0);
  std::uniform_real_distribution<> distrib_rad(min_p_rad,max_p_rad);
  for (int idx{0}; idx < particles.size(); idx++){
    particles[idx].R[0] = distrib_R(gen);
    particles[idx].R[1] = distrib_R(gen);
    particles[idx].R[2] = distrib_R(gen);
    particles[idx].V[0] = distrib_V(gen);
    particles[idx].V[1] = distrib_V(gen);
    particles[idx].V[2] = distrib_V(gen);
    particles[idx].rad  = distrib_rad(gen);
    particles[idx].mass = 0.337;
  }
}