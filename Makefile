INCDIR = include
SRCDIR = src
OBJDIR = obj

CC = g++
CFLAGS = -I$(INCDIR) -Wall -g
LDFLAGS = -L/usr/lib/x86_64-linux-gnu

ifneq ($(zmqdir),)
CFLAGS += -I $(zmqdir)/include
LDFLAGS += -L $(zmqdir)/lib
endif

LIBS = -lzmq -lpthread
SRCS = $(wildcard ./$(SRCDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

OUTPUT = zmq_proxy

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(OUTPUT) $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OUTPUT)
	rm -f $(OBJS)



REMOTE = harbor.tangramflex.tech
PROJECT = tools
TAG = $(shell git log --format=%h -1)

# builds the docker image
# * requires docker
build_image:
	docker build \
		-t $(REMOTE)/$(PROJECT)/zmqproxy:latest \
		-t $(REMOTE)/$(PROJECT)/zmqproxy:$(TAG) \
		.

# pushes the docker image to harbor
# * requires docker
# * requires docker login to exist for harbor
push_image:
	docker push $(REMOTE)/$(PROJECT)/zmqproxy:latest
	docker push $(REMOTE)/$(PROJECT)/zmqproxy:$(TAG)
