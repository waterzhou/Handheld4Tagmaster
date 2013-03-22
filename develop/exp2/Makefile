#
#
#

EXEC = exp2
OBJS = exp2.o

INSTALLPATH = ../../ramdisk/target/bin/
CFLAGS += -I.

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)
	cp -f $(EXEC) /
install:
	cp $(EXEC) $(INSTALLPATH)
clean:
	-rm -f $(EXEC) *.o
