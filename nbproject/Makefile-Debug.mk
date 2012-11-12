#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/CSensor.o \
	${OBJECTDIR}/src/CMotor.o \
	${OBJECTDIR}/src/CPWMDriver.o \
	${OBJECTDIR}/src/CActor.o \
	${OBJECTDIR}/src/CPIDRegler.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/CBMA180.o \
	${OBJECTDIR}/src/CVector.o \
	${OBJECTDIR}/src/CLSM303DLH.o \
	${OBJECTDIR}/src/CKalmanFilter.o \
	${OBJECTDIR}/src/CITG3200.o \
	${OBJECTDIR}/src/CI2C.o \
	${OBJECTDIR}/src/CRPMeter.o \
	${OBJECTDIR}/src/CPWM.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib -L/usr/local/lib -lboost_iostreams -lboost_regex -lboost_signals -lboost_system -lboost_thread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/loco-crocowheele

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/loco-crocowheele: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/loco-crocowheele ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/CSensor.o: src/CSensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CSensor.o src/CSensor.cpp

${OBJECTDIR}/src/CMotor.o: src/CMotor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CMotor.o src/CMotor.cpp

${OBJECTDIR}/src/CPWMDriver.o: src/CPWMDriver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CPWMDriver.o src/CPWMDriver.cpp

${OBJECTDIR}/src/CActor.o: src/CActor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CActor.o src/CActor.cpp

${OBJECTDIR}/src/CPIDRegler.o: src/CPIDRegler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CPIDRegler.o src/CPIDRegler.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/CBMA180.o: src/CBMA180.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CBMA180.o src/CBMA180.cpp

${OBJECTDIR}/src/CVector.o: src/CVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CVector.o src/CVector.cpp

${OBJECTDIR}/src/CLSM303DLH.o: src/CLSM303DLH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CLSM303DLH.o src/CLSM303DLH.cpp

${OBJECTDIR}/src/CKalmanFilter.o: src/CKalmanFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CKalmanFilter.o src/CKalmanFilter.cpp

${OBJECTDIR}/src/CITG3200.o: src/CITG3200.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CITG3200.o src/CITG3200.cpp

${OBJECTDIR}/src/CI2C.o: src/CI2C.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CI2C.o src/CI2C.cpp

${OBJECTDIR}/src/CRPMeter.o: src/CRPMeter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CRPMeter.o src/CRPMeter.cpp

${OBJECTDIR}/src/CPWM.o: src/CPWM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include -I/usr/local/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CPWM.o src/CPWM.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/loco-crocowheele

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
