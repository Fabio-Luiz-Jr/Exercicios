lab08: lab08.o mapa.o
	gcc lab08.o mapa.o -lm -o lab08

lab08.o: lab08.c mapa.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c lab08.c

mapa.o: mapa.c mapa.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c mapa.c

.PHONY: testar_tudo
testar_tudo: lab08
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
		./lab08 < "$$entrada" > "$$saida" ; \
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
