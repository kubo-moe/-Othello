MAKE = make
GCC = g++
OUT = a.out
SRC = main.c
SRC += initialize.c
SRC += input.c
SRC += reversi.c
SRC += decision.c
SRC += diagonal.c

OBJ += $(SRC:.c = .o)

default:
	$(MAKE) $(OUT)

$(OBJ):
	$(GCC) -c $(SRC)

$(OUT): $(OBJ)
	$(GCC) -o $(OUT) $(OBJ)

clean:
	rm -f $(OUT) $(OBJ)