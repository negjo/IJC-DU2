# IJC-DU2
# Soubor: makefile
# Datum: 26.4.2021
# Autor: Roman Vintoňak, xvinto00
# Fakulta: FIT


CFLAGS = -std=c99 -Wall -Wextra -g -pedantic

all: tail wordcount wordcount-dynamic 

tail: tail.c
	gcc $(CFLAGS) tail.c -o tail

wordcount: wordcount.o libhtab.a io.o
	gcc $(CFLAGS) wordcount.o -L. libhtab.a io.o -o wordcount

wordcount-dynamic: wordcount.o libhtab.so io.o
	gcc $(CFLAGS) wordcount.o libhtab.so io.o -o wordcount-dynamic

libhtab.a: htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_move.o htab_size.o htab_lookup_add.o htab_init.o
	ar -rcs libhtab.a $^

libhtab.so: htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_move.o htab_size.o htab_lookup_add.o htab_init.o
	gcc $(CFLAGS) -shared -o libhtab.so $^

wordcount.o: wordcount.c htab_private.h htab.h
	gcc $(CFLAGS) -c wordcount.c -fpic

htab_bucket_count.o: htab_bucket_count.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_bucket_count.c -fpic

htab_erase.o: htab_erase.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_erase.c -fpic

htab_clear.o: htab_clear.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_clear.c -fpic

htab_find.o: htab_find.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_find.c -fpic

htab_for_each.o: htab_for_each.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_for_each.c -fpic

htab_free.o: htab_free.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_free.c -fpic

htab_hash_function.o: htab_hash_function.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_hash_function.c -fpic

htab_init.o: htab_init.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_init.c -fpic

htab_lookup_add.o: htab_lookup_add.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_lookup_add.c -fpic

htab_move.o: htab_move.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_move.c -fpic

htab_size.o: htab_size.c htab_private.h htab.h
	gcc $(CFLAGS) -c htab_size.c -fpic

io.o: io.c io.h
	gcc $(CFLAGS) -c io.c -fpic

clean:
	rm *.o libhtab.so libhtab.a wordcount wordcount-dynamic

zip:
	zip xvinto00.zip *.c *.h makefile