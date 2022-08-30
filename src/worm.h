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
    ofSpherePrimitive sphere;

    Worm(){};
    Worm(int length, float spacing, float width, int resolution)
    {
        this->length = length;
        this->spacing = spacing;
        sphere.setRadius(width);
        sphere.setResolution(resolution);

        particles.push_back(Particle());

        for (int i = 1; i < length; i++)
        {
            float angle = ofRandom(0, TWO_PI * 4);
            particles.push_back(
                Particle({particles[i - 1].position.x + cos(angle) * spacing,
                          particles[i - 1].position.y + sin(angle) * spacing,
                          particles[i - 1].position.z + sin(ofRandom(0, TWO_PI * 4)) * spacing}));
        }
    }
    void update()
    {
        for (Particle &p : particles)
        {
            glm::vec3 force;
            force += p.gravity({0, 0, 0}, 0.05);
            force += p.selfRepulsion(particles, 0.1);
            p.constrain(particles, spacing);
            p.update(force);
        }
    }
    void draw()
    {
        ofNoFill();
        // line.begin();
        // line.clear();
        // line.curveTo(particles.front().position);
        for (Particle p : particles)
        {
            sphere.setPosition(p.position);
            sphere.draw();
            // line.curveTo(p.position);
            // glm::mat4 m;
            // m = glm::translate(p.position);
            // ofDrawLine(p.position, p.previous_position);
            //             ofSetColor(ofColor::green);
            //             ofDrawSphere(p.position, .1f);
            //             ofSetColor(ofColor::red);
            //
            //             ofDrawSphere(p.previous_position, .1f);
            // m *= glm::rotate(p.direction,);
            // ofLine(p.position, p.position + p.direction*10);
            // ofPushMatrix();
            // ofMultMatrix(m);
            // //ofDrawCircle({0,0,0}, 5);
            // // ofDrawSphere({0, 0, 0}, 5);
            // ofPopMatrix();
        }
        //         line.curveTo(particles.back().position);
        //         line.end();
        //
        //         line.draw();
    }
};

#endif