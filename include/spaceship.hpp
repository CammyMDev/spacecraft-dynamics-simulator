#include "vector3.hpp"

class Spacecraft{
    private:
        Vector3 position;
        Vector3 velocity;
        double mass;

    public:
        Spacecraft(const Vector3& pos, const Vector3& vel, double m);
        void update(double dt);
        Vector3 getPosition() const;
        Vector3 getVelocity() const;
};