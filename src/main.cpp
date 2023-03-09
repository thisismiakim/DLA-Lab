#include <iostream>
#include <cstdlib>
#include <random>
#include "Walker.h"
#include <fmt/format.h>

int main()
{

    std::cout<<"DLA Sim\n";
    Walker w(200,200);
    for(int i=0; i<3; ++i)
    {
        w.randomImageSeed();
    }

    
    int frame = 0;
    for (int i=0; i<20000; ++i)
    {
        if(w.walk())
        
        {
            std::cout << "saving \n";
            //w.save("DLATest.jpg");
            //w.save(fmt::format("DLA.{:04d}.jpg", i));
            w.save(fmt::format("DLA.{:04d}.jpg", frame++)); 
        };
    }

    return EXIT_SUCCESS;
}