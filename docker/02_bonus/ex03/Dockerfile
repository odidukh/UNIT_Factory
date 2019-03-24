#GoLang
FROM debian

MAINTAINER odidukh

RUN apt-get update && apt-get install -y \
      golang \
      git

ENV GOPATH /usr/lib/go/bin

RUN mkdir -p "$GOPATH"

ENV PATH $GOPATH:$PATH

# docker build -t bonus_ex03_app .

# docker run --rm -ti bonus_ex03_app