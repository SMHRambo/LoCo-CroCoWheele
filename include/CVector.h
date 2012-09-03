#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdint.h>
#include <boost/thread.hpp>

class CVector
{
    public:
        CVector();
        virtual ~CVector();

        void setX(float iX);
        void setY(float iY);
        void setZ(float iZ);
        
        float getX();
        float getY();
        float getZ();

        float getLengt();

        float getAlpha();
        float getBeta();
        float getGamma();

    protected:
    private:
        boost::mutex m_VectorMutex;
        float m_iX;
        float m_iY;
        float m_iZ;
};

#endif // VECTOR_H
