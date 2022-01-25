#!/bin/bash
echo "Starting Proxy..."
./zmq_proxy tcp://*:6668 tcp://*:6667 &
echo "Running.\n"


