cli: ./cli/cli.c libmath330.a ./include/math330.h ./bin ./include ./lib
	gcc ./cli/cli.c -I./include/ -L./lib/ -lmath330 -lm -o ./bin/cli

libmath330.a: ./lib ./trig/cos330.o ./trig/sin330.o ./trig/tan330.o ./trig/arccos.o ./trig/arcsin.o ./trig/arctan.o ./exp/exp330.o ./exp/log330.o
	ar r libmath330.a sin330.o cos330.o tan330.o arccos.o arcsin.o arctan.o exp330.o log330.o
	mv libmath330.a ./lib
	rm cos330.o sin330.o tan330.o arccos.o arcsin.o arctan.o exp330.o log330.o

./lib:
	mkdir -p ./lib

./bin:
	mkdir -p ./bin

./include:
	mkdir -p ./include

./include/math330.h: ./math330.h ./include
	cp ./math330.h ./include/math330.h


./trig/cos330.o: ./trig/cos330.c ./include/math330.h
	gcc -c ./trig/cos330.c -I ./include

./trig/sin330.o: ./trig/sin330.c ./include/math330.h
	gcc -c ./trig/sin330.c -I ./include

./trig/tan330.o: ./trig/tan330.c ./include/math330.h
	gcc -c ./trig/tan330.c -I ./include

./trig/arccos.o: ./trig/arccos.c ./include/math330.h
	gcc -c ./trig/arccos.c -I ./include

./trig/arcsin.o: ./trig/arcsin.c ./include/math330.h
	gcc -c ./trig/arcsin.c -I ./include

./trig/arctan.o: ./trig/arctan.c ./include/math330.h
	gcc -c ./trig/arctan.c -I ./include

./exp/exp330.o: ./exp/exp330.c ./include/math330.h
	gcc -c ./exp/exp330.c -I ./include

./exp/log330.o: ./exp/log330.c ./include/math330.h
	gcc -c ./exp/log330.c -I ./include