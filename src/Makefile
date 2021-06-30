files = main.o \
	merge.o

target = run.out

to_clean = ${files} ${target}

all:	$(target)
	echo "Done compiling source files"
main.o: main.c
merge.o: merge.c
$(target) : $(files)
	${CC} -g -o run.out $(files)

%.o : %.c
	${CC} -g -o $@ -c $<

default:
	@+$(call build)

clean:
	rm -rf *.o *.out

build = ${CC} -g -o run.out $(files)