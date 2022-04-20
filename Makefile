CFLAGS = -Wall -Wextra -I src -I thirdparty -MMD
DIRGUARD = @mkdir -p $(@D)

all: bin/pawg
-include src/main.d

bin/pawg: obj/main.o
	$(DIRGUARD)
	gcc $(CFLAGS) -o $@ $^

obj/main.o: src/main.c
	$(DIRGUARD)
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj/ bin/