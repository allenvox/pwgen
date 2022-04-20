CFLAGS = -Wall -Wextra -I src -I thirdparty -MMD
DIRGUARD = @mkdir -p $(@D)

all: bin/pawg
-include src/main.d obj/sha1.d

bin/pawg: obj/main.o obj/sha1.o
	$(DIRGUARD)
	gcc $(CFLAGS) -o $@ $^

obj/main.o: src/main.c
	$(DIRGUARD)
	gcc $(CFLAGS) -c -o $@ $<

obj/sha1.o: thirdparty/sha1.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj/ bin/