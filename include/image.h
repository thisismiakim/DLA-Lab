#ifndef IMAGE_H_
#define IMAGE_H_
#include "rgba.h"
#include <memory>
#include <string_view>

class Image
{
    public :
        Image() = default;
        Image(int _w, int _h);
        Image(int _w, int _h, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255);
        
        int width() const;
        int height() const;
        rgba getPixel(int _x, int _y) const;
        void setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255);
        void clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a = 255);
        bool save(std::string_view _fname) const;
    
    private :
        int m_width = 0;
        int m_height =  0;
        std::unique_ptr<rgba []> m_pixels;

};

#endif