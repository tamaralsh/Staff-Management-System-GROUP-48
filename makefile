kpi.o:kpi.cpp kpi.h
	g++ -c kpi.cpp

loadData.o:loadData.cpp loadData.h
	g++ -c loadData.cpp

Authority.o: Authority.cpp Authority.h
	g++ -c Authority.cpp

Functions.o: Functions.cpp Functions.h
	g++ -c Functions.cpp

main:main.cpp kpi.o loadData.o Authority.o Functions.o
	g++ main.cpp kpi.o loadData.o Authority.o Functions.o -o main
