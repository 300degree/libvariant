AUTOMAKE_OPTIONS = foreign -Wall 
ACLOCAL_AMFLAGS = -I m4

AM_CXXFLAGS = -Iinclude -fvisibility=hidden
AM_LDFLAGS = -shared
lib_LTLIBRARIES = libvariant.la
libvariant_la_SOURCES = variant.cc include/variant.h
libvariant_la_LDFLAGS = -shared -fPIC
