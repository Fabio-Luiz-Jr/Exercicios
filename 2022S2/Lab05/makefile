lab05: lab05.o ultron.o
	gcc lab05.o ultron.o -lm -o lab05

lab05.o: lab05.c ultron.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c lab05.c

ultron.o: ultron.c ultron.h
	gcc -std=c99 -Wall -Werror -Werror=vla -g -c ultron.c

.PHONY: testar_tudo
testar_tudo: lab05
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
		./lab05 < "$$entrada" > "$$saida" ; \
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
