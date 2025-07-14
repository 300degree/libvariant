CXX ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Iinclude -fPIC \
			-Wall \
			-Wextra \
			-Wunused-macros
LDFLAGS ?= -shared
TARGET := libvariant.so

PREFIX ?= $(pwd)
LIBDIR ?= lib
INCLUDEDIR := include

all: variant.o

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc $(INCLUDEDIR)/variant.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

install:
	install -d $(PREFIX)/lib
	install -m 755 $(TARGET) $(PREFIX)/lib/
	install -d $(PREFIX)/include
	install -m 644 $(INCLUDEDIR)/variant.h $(PREFIX)/include/

uninstall:
	rm -f $(PREFIX)/include/variant.h
	rm -f $(PREFIX)/lib/$(TARGET)

# test:
	# @ python3

clean:
	rm -r variant.o

.PHONY: all install uninstall test clean
