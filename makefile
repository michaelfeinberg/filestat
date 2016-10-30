stattest: stat.c
	gcc stat.c -o stattest

run: stattest
	./stattest

clean:
	rm stattest
	rm *.exe
	rm *~
