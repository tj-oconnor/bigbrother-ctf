FROM ubuntu:22.04

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=America/New_York
ENV LANG en_US.UTF-8 

RUN apt-get update -qq -y && apt-get install -qq -y python3-pip tmux gdb \
    git nano ltrace python2 netcat exiftool wget unzip mtd-utils gzip bzip2 \
    tar arj lhasa p7zip p7zip-full unzip xxd hexcurse dhex hexedit binwalk \
    caca-utils --no-install-recommends && rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install pwntools pycryptodome pillow
RUN git clone https://github.com/pwndbg/pwndbg && cd pwndbg/ && ./setup.sh 
RUN cd /opt/ && \
    wget http://downloads.volatilityfoundation.org/releases/2.6/volatility_2.6_lin64_standalone.zip && \
    unzip volatility_2.6_lin64_standalone.zip && \
    ln -sf /opt/volatility_2.6_lin64_standalone/volatility_2.6_lin64_standalone /usr/local/bin/volatility

RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.4/zsh-in-docker.sh)" -- \
    -t crunch

###########################
# copy challenges
###########################

ADD /chals/ /chals/
WORKDIR /chals

ENTRYPOINT ["/bin/zsh"]
