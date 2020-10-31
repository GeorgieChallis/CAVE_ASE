#ifndef TARGET_H
#define TARGET_H

#include <ngl/Vec3.h>

class Target{
    public:
        Target()=default;
        ~Target()=default;
        void setPos(float _x, float _y, float _z);
        void setPos(ngl::Vec3 _pos);
        void Pos();

    private:



};

#endif // TARGET_H
