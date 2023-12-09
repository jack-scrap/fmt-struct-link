CC=gcc

EXEC=link

BUILDDIR=build

PREFIX=/usr/local
BINDIR=$(PREFIX)/bin

.PHONY: all
all: mk_build $(EXEC)

$(BUILDDIR)/main.o: main.c
	$(CC) -c $< -o $@

$(EXEC): $(BUILDDIR)/main.o
	$(CC) $^ -o $@

.PHONY: mk_build
mk_build:
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm $(BUILDDIR)/*.o $(EXEC)

.PHONY: install
install:
	cp $(EXEC) $(BINDIR)

.PHONY: uninstall
uninstall:
	rm $(BINDIR)/$(EXEC)
