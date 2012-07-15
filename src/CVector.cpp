#include "../include/CVector.h"

CVector::CVector()
{

}

CVector::~CVector()
{

}

void CVector::setX(int16_t iX)
{
    m_VectorMutex.lock();
    
    m_iX = iX;
    
    m_VectorMutex.unlock();    
}

void CVector::setY(int16_t iY)
{
    m_VectorMutex.lock();
    
    m_iY = iY;
    
    m_VectorMutex.unlock();   
}

void CVector::setZ(int16_t iZ)
{
    m_VectorMutex.lock();
    
    m_iZ = iZ;
    
    m_VectorMutex.unlock();    
}

int16_t CVector::getX()
{
    uint16_t iX = 0;
    
    m_VectorMutex.lock();
    
    iX = m_iX;
    
    m_VectorMutex.unlock();
    
    return iX;
}

int16_t CVector::getY()
{
    uint16_t iY = 0;
    
    m_VectorMutex.lock();
    
    iY = m_iY;
    
    m_VectorMutex.unlock();
    
    return iY;
}

int16_t CVector::getZ()
{
    uint16_t iZ = 0;
    
    m_VectorMutex.lock();
    
    iZ = m_iZ;
    
    m_VectorMutex.unlock();
    
    return iZ;
}

double CVector::getLengt()
{
    double iLength = 0;
    
    m_VectorMutex.lock();
    
    iLength = sqrt(m_iX^2 + m_iY^2 + m_iZ^2);
    
    m_VectorMutex.unlock();
    
    return iLength;
}

double CVector::getAlpha()
{
    double iAlpha = 0;
    
    m_VectorMutex.lock();
    
    iAlpha = m_iX / sqrt(m_iX^2 + m_iY^2 + m_iZ^2);
    
    m_VectorMutex.unlock();
    
    return iAlpha;
}

double CVector::getBeta()
{
    double iBeta = 0;
    
    m_VectorMutex.lock();
    
    iBeta = m_iY / sqrt(m_iX^2 + m_iY^2 + m_iZ^2);
    
    m_VectorMutex.unlock();
    
    return iBeta;
}

double CVector::getGamma()
{
    double iGamma = 0;
    
    m_VectorMutex.lock();
    
    iGamma = m_iZ / sqrt(m_iX^2 + m_iY^2 + m_iZ^2);
    
    m_VectorMutex.unlock();
    
    return iGamma;
}
