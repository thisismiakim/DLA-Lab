#ifndef WALKER_H_
#define WALKER_H_
#include <memory>
#include "image.h"
#include <random>

class Walker
{
    public :
        Walker(int _w, int _h);
        bool save(std::string_view
        _fname) const;

        void randomImageSeed();
        bool walk();
        void resetStart();

    private :
        std::unique_ptr<Image> m_image;
        int m_width;
        int m_height;

        std::uniform_int_distribution
        <> m_xRand;
        std::uniform_int_distribution
        <> m_yRand;
        void initRNG();

        int m_xpos;
        int m_ypos;

};

#endif