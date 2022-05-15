CFLAGS = -Wall -Wextra -I  src -MMD
DIRGUARD = @mkdir -p $(@D)

all: bin/pawg
-include obj/*.d

bin/pawg: obj/main.o obj/libpawg.a
	$(DIRGUARD)
	gcc $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(DIRGUARD)
	gcc $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf obj/ bin/

.PHONY: test
test: bin/pawg-test

bin/pawg-test: obj/test/main.o obj/test/test.o obj/libpawg.a
	$(DIRGUARD)
	gcc $(CFLAGS) -o $@ $^

obj/test/%.o: test/%.c 
	$(DIRGUARD)
	gcc $(CFLAGS) -I thirdparty -c -o $@ $<

obj/libpawg.a: obj/alphabetic.o obj/random.o obj/hash.o obj/sha1.o obj/input.o obj/password.o
	ar rcs $@ $^