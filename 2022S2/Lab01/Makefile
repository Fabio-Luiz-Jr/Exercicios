MAIN = lab01

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
CC = gcc
GFLAGS = -std=c99 -Wall -Werror -g -lm

$(MAIN): $(OBJ)
	$(CC) $(GFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN) *.o

.PHONY: testar_tudo
testar_tudo: $(MAIN)
	@set -e ; \
	if [ ! -d testes ] ; then \
		echo "*****************************************************************" ; \
		echo "Crie ou copie o diretório 'testes' para a mesma pasta do Makefile" ; \
		echo "*****************************************************************" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes/*_in.txt ; do \
		saida=$$(echo "$$entrada" | sed -re 's/\_in.txt$$/_ans.txt/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\_in.txt$$/_out.txt/' ) ; \
		./$(MAIN) < "$$entrada" > "$$saida" ; \
		echo ; \
		echo "Testando $$entrada: " ; \
		if diff "$$resposta" "$$saida" ;  then \
			echo "OK" ; \
		else \
			echo "***********************************"; \
			echo "Falhou para $$entrada" ; \
			echo "***********************************"; \
			exit 1; \
		fi ; \
	done
