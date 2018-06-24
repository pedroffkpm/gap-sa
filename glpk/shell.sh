#!/bin/bash -ex

mkdir -p solutions

for instance in instances/*.dat; do
    glpsol -m salbp2.mod -d $instance --tmlim 3600 > solutions/$(basename $instance .dat).sol
done
