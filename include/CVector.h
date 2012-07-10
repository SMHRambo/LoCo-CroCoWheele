#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdint.h>
#include <boost/thread.hpp>

class CVector
{
    public:
        CVector();
        virtual ~CVector();

        int16_t getX();
        int16_t getY();
        int16_t getZ();

        double getLengt();

        double getAlpha();
        double getBeta();
        double getGamma();

    protected:
    private:
        boost::mutex m_VectorMutex;
        int16_t m_iX;
        int16_t m_iY;
        int16_t m_iZ;
};

#endif // VECTOR_H
