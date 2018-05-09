prog: main3B.o functions.o image.o
	g++ -o proj3B main3B.o functions.o image.o

main3B.o: main3B.C functions.h image.h
	g++ -c -I. -g main3B.C

functions.o: functions.C functions.h image.h
	g++ -c -I. -g functions.C

image.o: image.C image.h
	g++ -c -I. -g image.C
