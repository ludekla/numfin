CC = g++
INC = -I include

BIN = bin/crr
OBJS = bin/main.o bin/binmarket.o bin/option.o

$(BIN): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): bin/%.o: src/%.cpp
	$(CC) -o $@ $(INC) -c $<

clean:
	rm bin/*.o

wipe:
	rm bin/*