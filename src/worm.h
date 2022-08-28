#ifndef WORM_H
#define WORM_H

#include "ofMain.h"
#include "particle.h"

class Worm
{
public:
    int length;
    float spacing;
    vector<Particle> particles;
    ofPolyline line;

    Worm(){};
    Worm(int length, float spacing)
    {
        this->length = length;
        this->spacing = spacing;

        particles.push_back(Particle());

        for (int i = 1; i < length; i++)
        {
            float angle = ofRandom(0, TWO_PI);
            particles.push_back(
                Particle({particles[i - 1].position.x + cos(angle) * spacing,
                          particles[i - 1].position.y + sin(angle) * spacing,
                          particles[i - 1].position.z + sin(ofRandom(0, TWO_PI)) * spacing}));
        }
    }
    void update()
    {
        for (Particle &p : particles)
        {
            p.selfRepulsion(particles, spacing);
            p.gravity({0, 0, 0}, .001);
            p.constrain(particles, spacing);
        }
    }
    void draw()
    {
        line.begin();
        line.clear();
        line.curveTo(particles.front().position);
        for (Particle p : particles)
        {
            line.curveTo(p.position);
            // ofDrawSphere(p.position, 3);
        }
        line.curveTo(particles.back().position);
        line.end();

        line.draw();
    }
};

#endif