# Numele executabilului
EXECUTABLE = program

# Testele
TESTS = test0 test1 test2 test3 test4 test5

# Comanda implicită
all: $(TESTS)

# Regula pentru fiecare test
$(TESTS):
	@echo "Rulare $(EXECUTABLE) pentru $@..."

	# Compilare
	@echo "Compilare..."; \
	g++ -o $(EXECUTABLE) *.cpp || exit 1; \

	# Rulare program
	@echo "Rulare program..."; \
	./$(EXECUTABLE) teste/input/$@/produse.txt teste/input/$@/clienti.txt || exit 1; \

	# Verificare output și setare exit_status
	@echo "Verificare output pentru $@..."; \
	if ! diff -w --strip-trailing-cr -q output_comenzi.txt teste/output/$@/output_comenzi.txt; then \
		echo "$@: output_comenzi.txt Test Failed!"; \
		exit 1; \
	else \
		echo "$@: output_comenzi.txt Test Passed!"; \
	fi; \
	if ! diff -w --strip-trailing-cr -q output_stoc_ramas.txt teste/output/$@/output_stoc_ramas.txt; then \
		echo "$@: output_stoc_ramas.txt Test Failed!"; \
		exit 1; \
	else \
		echo "$@: output_stoc_ramas.txt Test Passed!"; \
	fi

# Curățarea fișierelor generate
clean:
	@echo "Curățare fișiere..."
	@rm -f $(EXECUTABLE) clienti.txt produse.txt output_comenzi.txt output_stoc_ramas.txt
