HEADERDIR = inc
SRCDIR = src
OBJDIR = obj

OBJS = $(OBJDIR)/main.o $(OBJDIR)/interpreter.o $(OBJDIR)/tape.o $(OBJDIR)/cell.o

CFLAGS = -Wall

all: brainfuck

brainfuck: $(OBJS)
	g++ $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	g++ -c $(CFLAGS) -I$(HEADERDIR) $< -o $@

clean:
	rm -f $(OBJDIR)/*
