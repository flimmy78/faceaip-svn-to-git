ARM_GCC_PATH = /usr/local/arm/4.3.2/bin
CC = ${ARM_GCC_PATH}/arm-linux-g++
AR = ${ARM_GCC_PATH}/arm-linux-ar
ARM_LIB = /usr/local/arm/4.3.2/lib
ARM_INC = /usr/local/arm/4.3.2/include

COMMON_PATH     = /opt/tshome-host

INC_PATH	= ${COMMON_PATH}/include

WIFI_PATH	= libs/include/ppSockets
WIFI_LIB_PATH	= libs/lib
WIFI_LIB_NAME	= ppSockets-linux-arm

DB_LIB_PATH	= ${COMMON_PATH}/lib
DB_LIB_NAME	= ts_db_tools

INCLUDE		= -I${WIFI_PATH} -I${INC_PATH} -I../ComProtocolManager -I${ARM_INC}

# uncomment by target machine
CPP_PREFIX	= ${ARM_GCC_PATH}/arm-linux-

CFLAGS		= -Wall -g3 $(INCLUDE)
CPPFLAGS	= $(CFLAGS)
LIBS		= -l$(DB_LIB_NAME) -l$(WIFI_LIB_NAME) -lpthread -L$(ARM_LIB) -lsqlite3

SRC		= ./GeneralAgent

MY_O		=  \
./Conversion.o \
./DPTManager.o \
./GatewayManager.o \
./ICIface.o \
./ICLogical.o \
./KNXException.o \
./KNXKernel.o \
./KNXUdpIface.o \
./NetworkIface.o \
./NodeList.o \
./UDPManager.o \
./UDPMulticast.o \
./UDPUnicast.o \
./WifiKernel.o \
./knxdef.o \
./thread.o \
./ezserial.o \
$(SRC)/GeneralAgentHandler.o \
$(SRC)/GeneralAgentTcpSocket.o \
$(SRC)/GeneralAgentTcpSocketConnector.o \
$(SRC)/GeneralAgentTcpSocketServer.o \

PROGS		= libGatewayManager.so
PROGS_A		= libGatewayManager.a

all:		$(PROGS)
so:		$(PROGS)
a:		$(PROGS_A)

.c.o:
	$(CPP_PREFIX)gcc $(CFLAGS) -o $@ -c $<

.cpp.o:
	$(CPP_PREFIX)g++ $(CPPFLAGS) -o $@ -c $<

libGatewayManager.so: $(MY_O)
		${CPP_PREFIX}g++  -L${DB_LIB_PATH} -L${WIFI_LIB_PATH} -shared -o $@ $^ $(LIBS)

libGatewayManager.a: $(MY_O)
		ar -cru $@ $^

clean:
		rm -rf *.o *.so *.a $(SRC)/*.o
