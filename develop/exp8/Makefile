#
#
#

EXEC = exp8
OBJS = exp8.o

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
