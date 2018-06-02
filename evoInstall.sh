#!/bin/bash
if [ "$1" = "get-fltk" ] || [ "$2" = "get-fltk" ] || [ "$3" = "get-fltk" ]; then
	sudo apt-get install libfltk1.3-dev
fi
if [ "$1" = "get-boost-test" ] || [ "$2" = "get-boost-test" ] || [ "$3" = "get-boost-test" ]; then
	sudo apt-get install libboost-test-dev
fi
if [ "$1" = "get-scons" ] || [ "$2" = "get-scons" ] || [ "$3" = "get-scons" ]; then
	sudo apt-get install scons
fi
if [ "$1" = "compile" ]; then
	scons
	rm src/*.o
fi
if [ "$1" = "clean" ]; then
	scons -c
fi
