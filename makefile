MAKE = make
GCC = g++
OUT = a.out
SRC = main.c
SRC += initialization.c
SRC += board.c
SRC += input.c
SRC += reversi.c
SRC += updown.c
SRC += diagonal.c
SRC += result.c

OBJ += $(SRC:.c = .o)

default:
	$(MAKE) $(OUT)

$(OBJ):
	$(GCC) -c $(SRC)

$(OUT): $(OBJ)
	$(GCC) -o $(OUT) $(OBJ)

clean:
	rm -f $(OUT) $(OBJ)