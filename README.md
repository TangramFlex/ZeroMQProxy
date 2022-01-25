# ZeroMQProxy

The ZeroMQ proxy allows the ZeroMQ pub sub model to have nodes both publish and subscribe by creating common endpoints to push messages to and to receive messages from.


## Current Features

Currently allows the publishing and subscribing addresses and ports to be configure from the command line as args


## Building

You can build the proxy by simply running `make`. 

If you have the ZeroMQ library built from source and installed to an alternate location (for example, you ran `./configure --prefix="some_path"` before building ZeroMQ), you can build the proxy against the library at that location with `make zmqdir=some_path`


## Docker

This program is available as a Docker image. Build the image with `make build_image`, and push it to the Tangram Harbor registry with `make push_image`. The image can be access via `harbor.tangramflex.tech/tools/zmqproxy:latest` (or using the latest git commit tag, instead of `latest`).

You can use the program via `docker-compose` as opposed to building it yourself locally. Just run `docker-compose up -d` from this directory to start the program with a default PUB port of 6667 and a SUB port of 6668. You can then stop the program by running `docker-compose down` from this directory.
