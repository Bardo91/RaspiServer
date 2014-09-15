#########################################################################################################################
# project:	DMC Server
# author:	Carmelo J. Fdez-Agüera Tortosa
# date:		23/Aug/2014
#########################################################################################################################
# Config
PRJ_NAME = dmcServer

SRC_DIR := ./src
CXX_SRC := $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/dmcServer.cpp \
	$(SRC_DIR)/service/lanService.cpp \
	$(SRC_DIR)/service/message.cpp \
	$(SRC_DIR)/service/command.cpp \
	$(SRC_DIR)/service/client/client.cpp \
	$(SRC_DIR)/service/client/commands/scanCommand.cpp \
	$(SRC_DIR)/service/scan/deviceScanner.cpp \
	$(SRC_DIR)/service/socket/socketMgr.cpp \
	$(SRC_DIR)/service/socket/serverSocket.cpp \
	$(SRC_DIR)/peripherals/plc/plcDriver.cpp \
	$(SRC_DIR)/peripherals/plc/SerialLinux.cpp \
	$(SRC_DIR)/peripherals/GPIO/PinRaspi.cpp \
	$(SRC_DIR)/peripherals/GPIO/Led.cpp \
	$(SRC_DIR)/peripherals/GPIO/BackButton.cpp \
	$(SRC_DIR)/core/time.cpp \
	$(SRC_DIR)/device/plc/dmcCommand.cpp \
	$(SRC_DIR)/device/plc/dmcDevice.cpp \
	$(SRC_DIR)/device/deviceMgr.cpp \
	
CXX_OBJ := $(patsubst %.cpp, %.cpp.o, $(CXX_SRC))
TEMP_FILES := $(CXX_OBJ)

# -- Build variables --
PLATFORM_DEFINITIONS := -D__Raspi__
PREPROCESSOR_DEFINITIONS := $(PLATFORM_DEFINITIONS)
WARNING_FLAGS := -Wall -Werror
INCLUDE_FLAGS :=  -I$(SRC_DIR)
CXX_COMPILE_FLAGS := -std=c++11 -fno-rtti -fno-exceptions -pthread
DEBUG_FLAGS := -ggdb
OPTIMIZATION_FLAGS := #-O4
COMMON_C_FLAGS := $(PLATFORM_FLAGS) $(PREPROCESSOR_DEFINITIONS) $(WARNING_FLAGS)\
			 $(INCLUDE_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS)
CC_FLAGS := $(COMMON_C_FLAGS)
CXX_FLAGS := $(COMMON_C_FLAGS) $(CXX_COMPILE_FLAGS)

OUT_NAME := $(PRJ_NAME)
OUTPUT := ./$(OUT_NAME)

LIBS := #-lm -lc

# -- Rules --
all: $(OUTPUT)

run: $(OUTPUT)
	$(OUTPUT)

clean:
	rm -f $(OUTPUT) $(TEMP_FILES)

rebuild: clean all

$(OUTPUT): $(CXX_OBJ)
	g++-4.7 -o $@ $^ $(CXX_FLAGS) $(LIB_DIR) $(LIBS)

%.cpp.o: %.cpp
	g++-4.7 -c -o $@ $^ $(CXX_FLAGS) $(LIBS)

.PHONY: clean run rebuild
