#
#
#

EXEC = com2show
OBJS = com2show.o

INSTALLPATH = ../../ramdisk/target/bin/
CFLAGS += -I.

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)
	cp -f $(EXEC) /
install:
	$(STRIP) $(EXEC)
	cp $(EXEC) $(INSTALLPATH)
clean:
	-rm -f $(EXEC) *.o
