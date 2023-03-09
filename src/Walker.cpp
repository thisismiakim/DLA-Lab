#include "Walker.h"
#include <iostream>

std::random_device g_rd; // g for global
std::seed_seq g_seed{g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd()}; 
std::mt19937 g_rng(g_seed);

std::uniform_int_distribution<>g_walkDir(-1,1);



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
    // [1] while not walking
    // have I hit the edge? If so return
    // else
    // get current pixel, is it a seed?
    // if seed then change colour of current pixel return True;
    // else walk to new position
    // go to [1]

    bool walking = true;
    bool found;
    while(walking)
    {
        // walk to new pos
        m_xpos +=g_walkDir(g_rng);
        m_ypos +=g_walkDir(g_rng);
        // hit and edge?
        if(m_xpos == 0 || m_xpos >= m_image->width() ||
           m_ypos == 0 || m_ypos >= m_image->height())
           {
               walking = false;
               found = false;
               std::cout <<"hit edge\n";
               break;
           }


        rgba p;
        for (int y = -1; y <= 1; ++y)
        {
            for(int x=-1; x<= 1; ++x)
            {
                p=m_image->getPixel(m_xpos+x, m_ypos+y);
                if(p.a == 255)
                {
                    std::cout<<"found pixel" <<m_xpos<<' '<<m_ypos<<'\n';
                    m_image->setPixel(m_xpos, m_ypos, 0, 0, 0, 255);
                    found = true;
                    return true;
                }
            }
        }           
    }
    // sample image for seed
    return found;
}

void Walker::resetStart()
{
    m_xpos=m_xRand(g_rng);
    m_ypos=m_yRand(g_rng);
    std::cout<<"New Start "<<m_xpos<<' '<<m_ypos<<'\n';
}