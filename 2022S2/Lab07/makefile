lab07: lab07.o pilha.o fila.o
	gcc lab07.o pilha.o fila.o -lm -o lab07

lab07.o: lab07.c pilha.h fila.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c lab07.c

pilha.o: pilha.c pilha.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c pilha.c

fila.o: fila.c fila.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c fila.c

.PHONY: testar_tudo
testar_tudo: lab07
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
		./lab07 < "$$entrada" > "$$saida" ; \
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
