#include "image.h"
#include <OpenImageIO/imageio.h>

bool Image::save(std::string_view _fname) const
{
    bool success = false;
    using namespace OIIO;
    auto out = ImageOutput::create(_fname.data());
    if(!out)
    {
        return false;
    }
    ImageSpec spec(m_width, m_height, 4, TypeDesc::UINT8);
    success = out->open(_fname.data(), spec);
    success = out->write_image(TypeDesc::UINT8, m_pixels.get());
    success = out->close();
        
    return success;
}

Image::Image(int _w, int _h): m_width{_w}, m_height{_h}
{
    m_pixels = std::make_unique<rgba []>(_w * _h);
}

Image::Image(int _w, int _h, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a): m_width{_w}, m_height{_h}
{
    m_pixels = std::make_unique<rgba []>(_w * _h);
    clear(_r, _g, _b, _a);
}

int Image::width() const
{
    return m_width;
}

int Image::height() const
{
    return m_height;
}

rgba Image::getPixel(int _x, int _y) const
{
    if ( (_x<0 || _x>m_width) || (_y<0 || _y>m_height))
        return rgba();

    int index = (m_width*_y) + _x;
    return m_pixels[index];
}

void Image::setPixel(int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    if ( (_x<0 || _x>m_width) || (_y<0 || _y>m_height))
        return;
        
    int index = (m_width*_y) + _x;
    
    m_pixels[index].r = _r;
    m_pixels[index].g = _g;
    m_pixels[index].b = _b;
    m_pixels[index].a = _a;
}

void Image::clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
    for(size_t i=0; i<m_width*m_height; ++i)
    {
        m_pixels[i].r = _r;
        m_pixels[i].g = _g;
        m_pixels[i].b = _b;
        m_pixels[i].a = _a;
    }
}
