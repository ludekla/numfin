CC = g++
INC = -I include

BIN = bin/euroc
OBJS = bin/main.o bin/eurocall.o bin/nonlin.o

$(BIN): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): bin/%.o: src/%.cpp
	$(CC) -o $@ $(INC) -c $<

clean:
	rm bin/*.o

wipe:
	rm bin/*