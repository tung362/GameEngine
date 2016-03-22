#pragma once

#include "System.h"
#include "Input.h"
#include "Time.h"
#include "Factory.h"

class PlayerFlightSystem : public System
{
    bool condition(Handle<Entity> i)
    {
        return i->rigidbody  > -1 &&
               i->transform  > -1 &&
               i->controller > -1;
    }

    void update(Handle<Entity> i)
    {
        auto  &input = Input::instance();
        auto  &c     = *i->controller;
        auto  &r     = *i->rigidbody;
        float dt     = Time::instance().getDeltaTime();

        if (input.getKey(c.LEFT))
            i->rigidbody->AddTorque(c.turnSpeed);

        if(input.getKey(c.RIGHT))
            r.AddTorque(-c.turnSpeed);

        if (input.getKey(c.FORWARD))
            r.AddForce(i->transform->GetUp() * c.speed);

        if (input.getKey(' '))
        {
            Factory::makeBullet(i->transform->GetPosition(), i->transform->GetUp());
        }
    }

};