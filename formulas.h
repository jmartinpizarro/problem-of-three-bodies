#ifndef FORMULAS_H
#define FORMULAS_H

#include <cmath>

using namespace std;

constexpr double G = 6.67430e-11;

struct velocityVector {
    double velocity;
    vector<double> vVector;
};

double calcOrbit(body planet, body orbitalBody){
    // calculates the orbit (radius) between two bodies in a 2D dimension plane
    return sqrt(pow(orbitalBody.px - planet.px, 2) + pow(orbitalBody.py - planet.py, 2));
}

velocityVector calcOrbitalVelocity(body planet, body orbitalBody){
    double rOrbit = calcOrbit(planet, orbitalBody);
    double v = sqrt((G * planet.mass) / rOrbit);
    vector<double> velVector = {(-orbitalBody.py / rOrbit), (orbitalBody.px / rOrbit)};

    velocityVector velocityVector = {v, velVector};
    return velocityVector;
}

#endif // FORMULAS_H