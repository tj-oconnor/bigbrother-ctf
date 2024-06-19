FROM tjoconnor/cyber-ops

add bigbrother /bigbrother
RUN chmod +x /bigbrother/re-1/re-1.bin
RUN chmod +x /bigbrother/re-2/re-2.bin
RUN chmod +x /bigbrother/re-3/re-3.bin

WORKDIR /bigbrother
RUN cd /bigbrother


ENTRYPOINT ["/bin/tmux"]
