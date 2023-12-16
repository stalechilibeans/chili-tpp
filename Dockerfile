FROM ubuntu:22.04 as build

RUN apt-get update && \
    apt-get install -y \
        binutils-mips-linux-gnu \
        bsdextrautils \
        build-essential \
        libaudiofile-dev \
        libcapstone-dev \
        python3

RUN mkdir /tpp
WORKDIR /tpp
ENV PATH="/tpp/tools:${PATH}"

CMD echo 'Usage: docker run --rm -v${PWD}:/tpp tpp make VERSION= jp -j4\n' \
         'See https://github.com/Fluvian/tpp/blob/master/README.md for more information'
