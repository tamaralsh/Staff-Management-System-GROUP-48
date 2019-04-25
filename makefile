kpi.o:kpi.cpp kpi.h
	g++ -c kpi.cpp
	
Function.o:Function.cpp Function.h
	g++ -c Function.cpp

Authority.o: Authority.cpp Authority.h
	g++ -c Authority.cpp

main:main.cpp kpi.o Function.o Authority.o
	g++ main.cpp kpi.o Function.o Authority.o -o main
