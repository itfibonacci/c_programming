CC=clang
CFLAGS=-I.
DEPS = get_mac.h
OBJDIR = bin
OBJS = $(addprefix $(OBJDIR)/, ethernet_frame.o get_mac.o)

$(OBJDIR)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/main: $(OBJS)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -r $(OBJDIR)
