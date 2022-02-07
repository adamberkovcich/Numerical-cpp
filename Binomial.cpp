#include "Binomial.h"
#include "Bernoulli.h"

Binomial::Binomial()
{
    //ctor
}

Binomial::Binomial(UniformGenerator* _gen, double _p, int _n): DiscreteGenerator(_gen), p(_p), n(_n)
{

}

double Binomial::Generate()
{
    double res = 0.;
    for (int i=0; i<n; ++i )
    {
        Bernoulli ber(DiscreteGenerator, p);
        res += ber.Generate();
    }

    return res
}

Binomial::~Binomial()
{
    //dtor
}
