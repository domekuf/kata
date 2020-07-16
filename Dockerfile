FROM centos:7

MAINTAINER "Domenico Di Iorio" <dome.diiorio@gmail.com>

WORKDIR /root/kata

ENV PKG_CONFIG_PATH=/usr/local/lib/pkgconfig

USER root