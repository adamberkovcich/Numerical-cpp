#ifndef BINOMIAL_H
#define BINOMIAL_H

#include "DiscreteGenerator.h"


class Binomial: public DiscreteGenerator
{
    public:
        Binomial();
        Binomial(UniformGenerator* _gen, double _p, int _n);

        virtual double Generate();

        virtual ~Binomial();

    protected:

    private:
        double p;
        int n;
};

#endif // BINOMIAL_H
