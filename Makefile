CC = g++
INC = -I include

BIN = bin/snell
OBJS = bin/main.o bin/option.o bin/binmarket.o

$(BIN): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): bin/%.o: src/%.cpp
	$(CC) -o $@ $(INC) -c $<

clean:
	rm bin/*.o

wipe:
	rm bin/*