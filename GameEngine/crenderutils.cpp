#include "sfwdraw.h"
#include "crenderutils.h"

void drawMatrix(const Matrix3x3 &a)
{
    Vector2 &pos  =       a[2].xy;
    Vector2 up    = pos + a[1].xy;
    Vector2 right = pos + a[0].xy;

    sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
    sfw::drawLine(pos.x, pos.y, up.x   , up.y   , GREEN);
}

void drawTransform(const Transform &t) { drawMatrix(t.GetGlobalTransform() * Matrix3x3::Scale({ 30,30 })); }

void drawRigidbody(const Transform &t, const Rigidbody &rb)
{
    Vector2 pos = t.GetPosition();
    Vector2 acc = pos + rb.acceleration;
    Vector2 vel = pos + rb.velocity;

    sfw::drawLine(pos.x, pos.y, acc.x, acc.y, CYAN);
    sfw::drawLine(pos.x, pos.y, vel.x, vel.y, YELLOW);
}

void drawAABB(AABB    &t, unsigned TINT)
{
    sfw::drawLine(t.Min().x, t.Min().y, t.Max().x ,t.Min().y, TINT);
    sfw::drawLine(t.Min().x, t.Max().y, t.Max().x, t.Max().y, TINT);
    sfw::drawLine(t.Max().x, t.Min().y, t.Max().x, t.Max().y, TINT);
    sfw::drawLine(t.Min().x, t.Min().y, t.Min().x, t.Max().y, TINT);
}

void drawCollider(const Transform &t, const Collider  &c)
{
    switch (c.shape)
    {
    case Collider::e_AABB:
        drawAABB(t.GetGlobalTransform() * c.aabb, BLUE);
        break;
    case Collider::e_CIRCLE:
    drawCircle(t.GetGlobalTransform() * c.circle, BLUE);
    break;
    }
}

void drawCircle(const Circle    &t, unsigned TINT)
{
    sfw::drawCircle(t.position.x, t.position.y, t.radius, 6, TINT);
}

