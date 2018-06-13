SRC=stress_test_template.C image.C sink.C source.C PNMreader.C PNMwriter.C filter.C logging.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -g -o proj3T

.C.o: $<
	g++  -g -I. -c $<

clean:
	rm *.o proj3T
