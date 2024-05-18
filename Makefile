CFLAGS = -Wall -Wextra -I  src -MMD
DIRGUARD = @mkdir -p $(@D)

all: bin/pwgen
-include obj/*.d

bin/pwgen: obj/main.o obj/libpwgen.a
	$(DIRGUARD)
	gcc $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(DIRGUARD)
	gcc $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf obj/ bin/

.PHONY: test
test: bin/pwgen-test

bin/pwgen-test: obj/test/main.o obj/test/test.o obj/libpwgen.a
	$(DIRGUARD)
	gcc $(CFLAGS) -o $@ $^

obj/test/%.o: test/%.c 
	$(DIRGUARD)
	gcc $(CFLAGS) -I thirdparty -c -o $@ $<

obj/libpwgen.a: obj/alphabetic.o obj/random.o obj/hash.o obj/sha1.o obj/input.o obj/password.o
	ar rcs $@ $^
