#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class Particle
{
public:
    glm::vec3 position, previous_position, acceleration, velocity, direction;

    Particle()
    {
        position = {0, 0, 0};
    };
    Particle(glm::vec3 position)
    {
        this->position = position;
    }
    void update(glm::vec3 force)
    {
        float limit = .001;
        velocity.x = ofClamp(velocity.x, -limit, limit);
        velocity.y = ofClamp(velocity.y, -limit, limit);
        velocity.z = ofClamp(velocity.z, -limit, limit);
        velocity += force;
        previous_position = position;
        position += velocity;

        direction = glm::normalize(position - previous_position);
        if (ofGetElapsedTimef() > 1)
        {
            cout << force << " " << previous_position << endl;
            // exit(0);
        }
    }
    glm::vec3 selfRepulsion(vector<Particle> &particles, float magnitude)
    {
        glm::vec3 force_summation;
        for (Particle &p : particles)
        {
            if (&p != this)
            {
                float distance = glm::distance(position, p.position);
                glm::vec3 force_direction = glm::normalize(position - p.position);
                force_summation += force_direction / distance * magnitude;
            }
        }
        return force_summation;
    }
    glm::vec3 gravity(glm::vec3 attraction_point, float magnitude)
    {
        glm::vec3 force_direction;
        float distance;
        if (attraction_point != position)
        {
            force_direction = glm::normalize(attraction_point - position);
            distance = glm::distance(attraction_point, position);
            distance = MAX(distance, 1);
        }
        else
        {
            distance = 1;
        }
        return force_direction * distance * magnitude;
    }
    void constrain(vector<Particle> &particles, float distance_limit)
    {
        for (int i = 1; i < (int)particles.size(); i++)
        {
            if (glm::distance(particles[i].position, particles[i - 1].position) > distance_limit)
            {
                glm::vec3 direction = glm::normalize(particles[i].position - particles[i - 1].position);
                particles[i].position = particles[i - 1].position + direction * distance_limit;
            }
        }
    }
};

#endif