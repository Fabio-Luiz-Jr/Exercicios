all: lab03

lab03: lab03.o represa.o
	gcc lab03.o represa.o -lm -o lab03

lab03.o: lab03.c represa.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c lab03.c

represa.o: represa.c represa.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c represa.c

clean:
	rm *.o lab03

.PHONY: testar_tudo
testar_tudo: lab03
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
		./lab03 < "$$entrada" > "$$saida" ; \
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
