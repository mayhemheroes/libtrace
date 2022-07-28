FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential automake pkg-config libtool libpcap-dev bison flex libz-dev libbz2-dev liblzma-dev liblzo2-dev liblz4-dev libzstd-dev

RUN DEBIAN_FRONTEND=noninteractive apt-get install -y git
RUN git clone https://github.com/wanduow/wandio
WORKDIR /wandio
RUN ./bootstrap.sh
RUN ./configure --prefix=/install
RUN make -j8
RUN make install

RUN ./configure 
RUN make -j8
RUN make install

COPY . /repo
WORKDIR /repo
RUN ./bootstrap.sh
RUN ./configure --prefix=/install
RUN make -j8
RUN make install
ENV LD_LIBRARY_PATH=/usr/local/lib:/repo/lib/.libs:/repo/libpacketdump/.libs

FROM ubuntu:22.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libpcap-dev liblzo2-dev
COPY --from=builder /install /install
ENV LD_LIBRARY_PATH=/install/lib
