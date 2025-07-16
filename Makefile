CXX ?= g++
CXXFLAGS ?= -std=c++17 -O3 -Iinclude -fPIC \
			-fvisibility=hidden \
			-Wall \
			-Wextra \
			-Werror \
			-Wpedantic \
			-Wconversion
LDFLAGS := 
PREFIX ?= $(shell pwd)

all: libvariant.so

libvariant.so: variant.o
	$(CXX) $(LDFLAGS) -shared -o $@ $^ 

variant.o: variant.cc include/variant.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

install:
	install -d $(PREFIX)/lib
	install -m 755 $(TARGET) $(PREFIX)/lib/
	install -d $(PREFIX)/include
	install -m 644 include/variant.h $(PREFIX)/include/

clean:
	rm -r variant.o libvariant.so

.PHONY: all install uninstall test clean
