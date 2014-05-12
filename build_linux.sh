#!/bin/bash

if [ -e /usr/bin/ninja ]
then
	echo "Using ninja"
	export GENERATOR="Ninja"
	export MAKE=ninja
else
	export GENERATOR="Unix Makefiles"
	export MAKE=make
fi

if [ ! -d build_release ]; then
  mkdir build_release
fi

pushd build_release
cmake -G "$GENERATOR" -DCMAKE_BUILD_TYPE=Release ..
$MAKE -j 8
popd
