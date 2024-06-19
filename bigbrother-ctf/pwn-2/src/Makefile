CFLAGS = -fno-stack-protector -fno-builtin -Wno-all -Wno-extra -no-pie
CHAL   = chal
SRC    = $(CHAL).c
BIN    = $(CHAL).bin

example:
	gcc -o $(BIN) $(SRC) $(CFLAGS)

clean:
	rm -rf $(BIN)
