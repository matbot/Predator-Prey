 #CXX and FLAGS
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS +=

 #SOURCES
SRCS = *.cpp

 #HEADERS
HEADERS = *.hpp

 #OBJECTS
OBJS = *.o

 #DOCUMENTATION
DOCS = *.pdf

 #PROGRAMS
PROGS = predprey

 #COMPRESSED FILE
TAR = ${PROGS}.tar.bz2

# #####################################################
# #BUILD and TAR
# #####################################################

${PROGS}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROGS}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOCS} makefile

##################
#CLEAN
##################

clean:
	rm -f ${PROGS} *.o *~
