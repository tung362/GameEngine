#pragma once
#include "System.h"
#include "Assets.h"

class RenderSystem : public System
{
    // sprite and transform
    bool condition(Handle<Entity> i)
    {
        return i->sprite > -1 && i->transform > -1;
    }

    // the actual draw call
    void update(Handle<Entity> i)
    {
        Matrix3x3 m = 
                  i->transform->GetGlobalTransform()
                  * Matrix3x3::Translate(i->sprite->offset)
                  * Matrix3x3::Scale(i->sprite->dimension)
                  * Matrix3x3::Rotate(i->sprite->angle);

        Asset::instance().drawTexture(i->sprite->assetName, m);
    }
};