#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class Particle
{
public:
    glm::vec3 position, previous_position, acceleration, velocity;

    Particle()
    {
        position = {0, 0, 0};
    };
    Particle(glm::vec3 position)
    {
        this->position = position;
    }
    void selfRepulsion(vector<Particle> &particles, float spacing)
    {
        glm::vec3 force_summation;
        for (Particle &p : particles)
        {
            if (&p != this && spacing)
            {
                float distance = glm::distance(position, p.position);
                glm::vec3 force_direction = glm::normalize(position - p.position);
                force_summation += force_direction / distance * spacing;
            }
        }
        acceleration = force_summation;
        velocity += acceleration;
        previous_position = position;
        position += velocity;
    }
    void gravity(glm::vec3 attraction_point, float magnitude)
    {
        glm::vec3 force_direction = glm::normalize(attraction_point - position);
        float distance = glm::distance(attraction_point, position);
        distance = MAX(distance, 1);
        if (distance * magnitude)
        {
            acceleration = force_direction * distance * magnitude;
            velocity += acceleration;
            position += velocity;
        }
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