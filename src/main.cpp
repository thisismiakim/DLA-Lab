#include <iostream>
#include <cstdlib>
#include <random>
#include "Walker.h"

int main()
{

    std::cout<<"DLA Sim\n";
    Walker w(200,200);
    for(int i=0; i<100; ++i)
    {
        w.randomImageSeed();
    }

    for (int i=0; i<100; ++i)
    {
        if(w.walk()){
            std::cout << "saving \n";
        };
    }

    w.save("DLATest.jpg");
    return EXIT_SUCCESS;
}