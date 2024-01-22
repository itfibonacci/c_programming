CC=clang
CFLAGS=-I.
DEPS = common.h server.h client.h
OBJDIR = bin
SERVER_OBJS = $(addprefix $(OBJDIR)/, common.o server.o)
CLIENT_OBJS = $(addprefix $(OBJDIR)/, common.o client.o)

$(OBJDIR)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/server: $(SERVER_OBJS)
	$(CC) -o $@ $^

$(OBJDIR)/client: $(CLIENT_OBJS)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -r $(OBJDIR)
