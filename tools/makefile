SRCS=$(wildcard *.c)

OUT=$(SRCS:%.c=%)
ARGS=-Wall -Wextra -g -std=gnu11 -m32 -lgcc

all: $(OUT)

%: %.c
	gcc $(ARGS) $< -o $@

clean:
	rm -rf $(OUT) *.o *.d

test_fs_create:
	rm -rf *.img
	make
	./fs_create doge_fs 1024 disk.img 4096

rebuild: clean clean_img all

.PHONY: clean rebuild