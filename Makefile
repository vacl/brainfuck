SRCDIR = src
OBJDIR = obj

OBJS = main.o interpreter.o tape.o cell.o

all: brainfuck

brainfuck: $(OBJDIR)/$(OBJS)
	g++ $(OBJDIR)/$(OBJS) -o brainfuck

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	g++ -c $< -o $@

clean:
	rm -f $(OBJDIR)/*
