CFLAGS = -Wall -Wextra -I src -I thirdparty -MMD
DIRGUARD = @mkdir -p $(@D)

all: bin/pawg
-include obj/*.d

bin/pawg: obj/main.o obj/input.o obj/random.o obj/alphabetic.o
	$(DIRGUARD)
	gcc $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(DIRGUARD)
	gcc $(CFLAGS) -c -o $@ $<

obj/sha1.o: thirdparty/sha1.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj/ bin/