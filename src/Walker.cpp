#include "Walker.h"
#include <iostream>

std::random_device g_rd; // g for global
std::seed_seq g_seed{g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd()}; 
std::mt19937 g_rng(g_seed);

void Walker::initRNG()
{
    m_xRand=std::uniform_int_distribution<>(1, m_width-1);
    m_yRand=std::uniform_int_distribution<>(1, m_height-1);   
}

void Walker::randomImageSeed()
{
    m_image->setPixel(m_xRand(g_rng), m_yRand(g_rng), 0, 0, 0, 255);
}

Walker::Walker(int _w, int _h) : m_width{_w}, m_height{_h}
{
    m_image = std::make_unique<Image> (_w, _h, 255, 255, 255, 0);
    initRNG();
}

bool Walker::save(std::string_view _fname) const
{
    return m_image->save(_fname);
}

bool Walker::walk()
{
    resetStart();
    return true;
}

void Walker::resetStart()
{
    m_xpos=m_xRand(g_rng);
    m_ypos=m_yRand(g_rng);
    std::cout<<"New Start "<<m_xpos<<' '<<m_ypos<<'\n';
}