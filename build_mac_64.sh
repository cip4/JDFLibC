#!/bin/sh

if [ -e /usr/local/bin/ninja ]
then
	echo "Using ninja"
	export GENERATOR="Ninja"
	export MAKE=ninja
else
	export GENERATOR="Unix Makefiles"
	export MAKE=make
fi

export INSTALL_PREFIX=$(pwd)/install

mkdir build_debug
pushd build_debug
cmake -G "$GENERATOR" -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DCMAKE_BUILD_TYPE=Debug -DCMAKE_OSX_ARCHITECTURES="x86_64" ..
$MAKE -j2
popd

mkdir build_release
pushd build_release
cmake -G "$GENERATOR" -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES="x86_64" ..
$MAKE -j2
popd
