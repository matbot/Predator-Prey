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
TAR = cs162_lab5_mathewmcdade.tar.bz2

# #####################################################
# #BUILD and TAR
# #####################################################

predprey: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o predprey

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOCS} makefile

##################
#CLEAN
##################

clean:
	rm -f ${PROGS} *.o *~
