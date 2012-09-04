#include "../include/CVector.h"

CVector::CVector()
{

}

CVector::~CVector()
{

}

void CVector::setX(float iX)
{
    m_VectorMutex.lock();
    
    m_iX = iX;
    
    m_VectorMutex.unlock();    
}

void CVector::setY(float iY)
{
    m_VectorMutex.lock();
    
    m_iY = iY;
    
    m_VectorMutex.unlock();   
}

void CVector::setZ(float iZ)
{
    m_VectorMutex.lock();
    
    m_iZ = iZ;
    
    m_VectorMutex.unlock();    
}

float CVector::getX()
{
    float iX = 0;
    
    m_VectorMutex.lock();
    
    iX = m_iX;
    
    m_VectorMutex.unlock();
    
    return iX;
}

float CVector::getY()
{
    float iY = 0;
    
    m_VectorMutex.lock();
    
    iY = m_iY;
    
    m_VectorMutex.unlock();
    
    return iY;
}

float CVector::getZ()
{
    float iZ = 0;
    
    m_VectorMutex.lock();
    
    iZ = m_iZ;
    
    m_VectorMutex.unlock();
    
    return iZ;
}

float CVector::getLengt()
{
    float iLength = 0;
    
    m_VectorMutex.lock();
    
    iLength = sqrt(pow(m_iX, 2) + pow(m_iY, 2) + pow(m_iZ, 2));
    
    m_VectorMutex.unlock();
    
    return iLength;
}

float CVector::getAlpha()
{
    float iAlpha = 0;
    
    m_VectorMutex.lock();
    
    iAlpha = m_iX / sqrt(pow(m_iX, 2) + pow(m_iY, 2) + pow(m_iZ, 2));
    
    m_VectorMutex.unlock();
    
    return iAlpha;
}

float CVector::getBeta()
{
    float iBeta = 0;
    
    m_VectorMutex.lock();
    
    iBeta = m_iY / sqrt(pow(m_iX, 2) + pow(m_iY, 2) + pow(m_iZ ,2));
    
    m_VectorMutex.unlock();
    
    return iBeta;
}

float CVector::getGamma()
{
    float iGamma = 0;
    
    m_VectorMutex.lock();
    
    iGamma = m_iZ / sqrt(pow(m_iX, 2) + pow(m_iY, 2) + pow(m_iZ, 2));
    
    m_VectorMutex.unlock();
    
    return iGamma;
}
