# twho
(education purposes, use at your own risk!)

Simple C program which is not using the standard way to get data for logged users from /var/log/wtmp

It lists logged users connected not only thu ssh, getting the uid of the pts

Tested on ubuntu 16.04 LTS

Compile:

gcc -Wall twho.c -o twho

TODO:

 - remote host of the user
