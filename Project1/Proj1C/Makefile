library: ./trig/cos330.o ./trig/sin330.o ./trig/tan330.o ./trig/arccos330.o ./trig/arcsin330.o ./trig/arctan330.o ./exp/exp330.o ./exp/log330.o
		mkdir lib/
		cd lib/
		ar r libmath330.a sin330.o tan330.o arccos330.o arcsin330.o arctan330.o exp330.o log330.o
		cd ..


./bin:
		mkdir ./bin

./include:
		mkdir ./include

./include/math330.h: ./math330.h ./include
		cp ./math330.h ./include/math330.h


./trig/cos330.o: ./trig/cos330.c ./lib ./include/math330.h
		gcc -c ./trig/cos330.c -I ./include/math330.h

./trig/sin330.o: ./trig/sin330.c ./lib ./include/math330.h
		gcc -c ./trig/sin330.c -I ./math330.h

./trig/tan330.o: ./trig/tan330.c ./lib ./include/math330.h
		gcc -c ./trig/tan330.c -I ./math330.h

./trig/arccos330.o: ./trig/arccos330.c ./lib ./include/math330.h
		gcc -c ./trig/arccos330.c -I ./math330.h

./trig/arcsin330.o: ./trig/arcsin330.c ./lib ./include/math330.h
		gcc -c ./trig/arcsin330.c -I ./math330.h

./trig/arctan330.o: ./trig/arctan330.c ./lib ./include/math330.h
		gcc -c ./trig/arctan330.c -I ./math330.h

./exp/exp330.o: ./exp/exp330.c ./lib ./include/math330.h
		gcc -c ./exp/exp330.c -I ./math330.h

./exp/log330.o: ./exp/log330.c ./lib ./include/math330.h
		gcc -c ./exp/log330.c -I ./math330.h