CXX = g++
AR = ar
GCOV = gcov
CFLAGS += -MMD
LDFLAGS =

ifeq ($(OS), Windows_NT)
    EXT = .exe
    RM = rm.exe
    CFLAGS += -std=c++11
	#CFLAGS += -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include
	LDFLAGS += -lfreeglut -lglu32 -lopengl32 -Wl,--subsystem,windows
	CXX = "C:/Program FIles (x86)/Dev-Cpp/MinGW64/bin/g++.exe"
    PREFIX = 
else
    EXT =
    PREFIX = ./
    RM = rm -f
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S), Linux)
        CFLAGS += -Iincludes
		LDFLAGS += -lGL -lGLU -lglut
    endif
    ifeq ($(UNAME_S), Darwin)
        CFLAGS += -Wno-deprecated-declarations
		LDFLAGS += -framework OpenGL -framework GLUT
    endif
endif

