LEX = p4ltl_lexer.ll
C = lex.yy.c
OUT = a.out

all:
	flex $(LEX)
	cc $(C) -lfl

run:
	@echo "Running flex lexer. Type in <CTRL + D> to stop."
	./$(OUT)

clean:
	rm -f *.out *.yy.c