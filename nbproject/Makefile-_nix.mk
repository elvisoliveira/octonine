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
CND_PLATFORM=MinGW_TDM-Windows
CND_DLIB_EXT=dll
CND_CONF=_nix
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/908980938/downloadimage.o \
	${OBJECTDIR}/downloadfeed.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/parsefeed.o


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
LDLIBSOPTIONS=-L/usr/include -L/usr/include/curl

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/octonine.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/octonine.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/octonine ${OBJECTFILES} ${LDLIBSOPTIONS} -lcurl

${OBJECTDIR}/_ext/908980938/downloadimage.o: /C/Development/projects/octonine/downloadimage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/908980938
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/curl -I/usr/include/rapidxml -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/908980938/downloadimage.o /C/Development/projects/octonine/downloadimage.cpp

${OBJECTDIR}/downloadfeed.o: downloadfeed.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/curl -I/usr/include/rapidxml -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/downloadfeed.o downloadfeed.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/curl -I/usr/include/rapidxml -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/parsefeed.o: parsefeed.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/curl -I/usr/include/rapidxml -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parsefeed.o parsefeed.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/octonine.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
