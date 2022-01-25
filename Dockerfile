#
# Simple Docker image that can run the ZeroMQProxy binary
#

FROM debian:buster-slim as builder

# install build-time dependencies
RUN apt update && \
    apt install -y gcc g++ make libzmq3-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# build the proxy
RUN mkdir -p /zmqproxy

COPY . /zmqproxy

WORKDIR /zmqproxy
RUN make all

# Build final image to run the proxy
FROM debian:buster-slim as runner

# install run-time dependencies
RUN apt update && \
    apt install -y libc-bin libzmq5 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /zmqproxy/zmq_proxy /usr/bin/zmq_proxy

ENTRYPOINT zmq_proxy tcp://*:6668 tcp://*:6667
