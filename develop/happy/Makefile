EXEC = happy
OBJS = happy.o
CFLAGS += -I
all: $(EXEC)
$(EXEC): $(OBJS)
$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)
 clean:
   rm -f $(EXEC) *.o
