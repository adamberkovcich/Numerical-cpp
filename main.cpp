#include <iostream>
#include "LinearCongruential.h"
#include "HeadTail.h"
#include "EcuyerCombined.h"
#include "Bernoulli.h"
#include "NormalBoxMuller.h"

//TEST

int main()
{

    LinearCongruential* Uniform_lc = new LinearCongruential(27, 17, 43, 100); //create ptr to LC generator
    EcuyerCombined* Uniform_ec = new EcuyerCombined();

    HeadTail* ht = new HeadTail(Uniform_ec);
    Bernoulli* ber = new Bernoulli(Uniform_ec, 0.5);

    NormalBoxMuller* Normal_bm = new NormalBoxMuller(3, 10, Uniform_ec); //N(mu = 3, sigma^2 = 100)

    std::cout << "LC gen" << std::endl;

    for (int i=0; i<4; ++i)
    {
        std::cout << Uniform_lc->Generate() << std::endl;
    }

    std::cout << "\n Mean LC = " << Uniform_lc->Mean(10000000) << std::endl; //0.395: not accurate (seed, m, c, a very important)
    std::cout << "Variance LC = " << Uniform_lc->Variance(10000000) << std::endl;


    std::cout << "\n EC gen" << std::endl;

    for (int i=0; i<4; ++i)
    {
        std::cout << Uniform_ec->Generate() << std::endl;
    }

    std::cout << "\n Mean EC = " << Uniform_ec->Mean(10000000) << std::endl;
    std::cout << "Variance EC = " << Uniform_ec->Variance(10000000) << std::endl;

    std::cout << "\n Normal BM gen" << std::endl;

    for (int i=0; i<4; ++i)
    {
        std::cout << Normal_bm->Generate() << std::endl;
    }

    std::cout << "\n Mean BM = " << Normal_bm->Mean(10000000) << std::endl;
    std::cout << "Variance BM = " << Normal_bm->Variance(10000000) << std::endl;



//    std::cout << "\n Head tail gen EC" << std::endl;
//
//    for (int i=0; i<4; ++i)
//    {
//        std::cout << ht->Generate() << std::endl; //with the ptr we are able to call the Generate version of HeadTail
//    }
//
//    std::cout << "\n Bernoulli(1/2) gen EC" << std::endl;
//
//    for (int i=0; i<4; ++i)
//    {
//        std::cout << ber->Generate() << std::endl; //with the ptr we are able to call the Generate version of HeadTail
//    }

    return 0;



}
