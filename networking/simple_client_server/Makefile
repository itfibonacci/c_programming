CC=clang
CFLAGS=-I.
DEPS = common.h server.h
OBJDIR = bin
OBJS = $(addprefix $(OBJDIR)/, common.o server.o)

$(OBJDIR)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/server: $(OBJS)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(OBJDIR)
