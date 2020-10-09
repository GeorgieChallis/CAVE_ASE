#ifndef RGBA_H_
#define RGBA_H_

#include <cstdint>
#include <iostream>

struct RGBA
{
    union 
    {
        uint32_t pixel = 0;
        struct{
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        };
    };
    RGBA()=default;
    RGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) :
        r{_r},g{_g},b{_b},a{_a} {}

    RGBA(const RGBA &)=default;
    ~RGBA()=default;

    void print() const
    {
        std::cout << pixel << ':' << static_cast<int>(r) << ' ' << static_cast<int>(g) << ' ' << static_cast<int>(b) << '/n';  
    }

    void setRGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
    {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }

    void clamp(unsigned char _min, unsigned char _max)
    {
        std::clamp(r, _min, _max);
        std::clamp(g, _min, _max);
        std::clamp(b, _min, _max);
        std::clamp(a, _min, _max);
    }

};

#endif