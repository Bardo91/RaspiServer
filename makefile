#########################################################################################################################
# project:	DMC Server
# author:	Carmelo J. Fdez-Agüera Tortosa
# date:		23/Aug/2014
#########################################################################################################################
# Config
PRJ_NAME = dmcServer

# -- Global variables --
TOOLCHAIN := C:\SysGCC\Raspberry\bin

# -- GNU Tools --
AS := $(TOOLCHAIN)/arm-linux-gnueabihf-as # Assembler
AR := $(TOOLCHAIN)/arm-linux-gnueabihf-ar # Archiver
CC := $(TOOLCHAIN)/arm-linux-gnueabihf-gcc # C Compiler
CXX := $(TOOLCHAIN)/arm-linux-gnueabihf-g++ # C++ Compiler
OBJCOPY := $(TOOLCHAIN)/arm-linux-gnueabihf-objcopy # Obj copy
OBJDUMP := $(TOOLCHAIN)/arm-linux-gnueabihf-objdump # Obj dump
READELF := $(TOOLCHAIN)/arm-linux-gnueabihf-readelf # Read elf

SRC_DIR := ./src
CXX_SRC := $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/dmcServer.cpp \
	$(SRC_DIR)/service/lanService.cpp \
	$(SRC_DIR)/service/socket/serverMgr.cpp \
	$(SRC_DIR)/service/socket/serverSocket.cpp \

CXX_OBJ := $(patsubst %.cpp, %.cpp.o, $(CXX_SRC))
TEMP_FILES := $(CXX_OBJ)

# -- Build variables --
PREPROCESSOR_DEFINITIONS := $(PLATFROM_DEFINITIONS)
WARNING_FLAGS := -Wall -Werror
INCLUDE_FLAGS :=  -I$(BBDUINO_HOME) -I$(BBDUINO_HOME)/stl
CXX_COMPILE_FLAGS := -std=c++0x -fno-rtti -fno-exceptions
DEBUG_FLAGS := -ggdb
OPTIMIZATION_FLAGS := #-O4
COMMON_C_FLAGS := $(PLATFORM_FLAGS) $(PREPROCESSOR_DEFINITIONS) $(WARNING_FLAGS)\
			 $(INCLUDE_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS)
CC_FLAGS := $(COMMON_C_FLAGS)
CXX_FLAGS := $(COMMON_C_FLAGS) $(CXX_COMPILE_FLAGS)

OUT_NAME := $(PRJ_NAME)
OUTPUT := $(OUT_NAME)

LIBS := #-lm -lc

# -- Rules --
all: $(OUTPUT)

clean:
	rm -f $(OUTPUT) $(TEMP_FILES)

$(OUTPUT): $(CXX_OBJ)
	$(CXX) -o $@ $^ $(CXX_FLAGS) $(LIB_DIR) $(LIBS)

%.cpp.o: %.cpp
	$(CXX) -c -o $@ $^ $(CXX_FLAGS) $(LIBS)

.PHONY: clean