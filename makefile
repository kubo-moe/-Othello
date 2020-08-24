MAKE = make
GCC = g++
OUT = a.out
SRC = main.c
SRC += syokika.c
SRC += masume.c
SRC += nyuryoku.c
SRC += reversi.c
SRC += uesita.c
SRC += yoko.c
SRC += naname1.c
SRC += naname2.c
SRC += kekka.c

OBJ += $(SRC:.c = .o)

default:
	$(MAKE) $(OUT)

$(OBJ):
	$(GCC) -c $(SRC)

$(OUT): $(OBJ)
	$(GCC) -o $(OUT) $(OBJ)

clean:
	rm -f $(OUT) $(OBJ)