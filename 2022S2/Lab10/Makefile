lab10: lab10.o hash.o
	gcc lab10.o hash.o -lm -o lab10

lab10.o: lab10.c hash.h
	gcc -std=c99 -Wall -Werror -g -c lab10.c

hash.o: hash.c hash.h
	gcc -std=c99 -Wall -Werror -g -c hash.c

.PHONY: testar_tudo
testar_tudo: lab10
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
		./lab10 < "$$entrada" > "$$saida" ; \
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
