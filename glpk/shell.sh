#!/bin/bash -ex

mkdir -p solutions

for instance in instances/*.dat; do
    glpsol -m gap.mod -d $instance --tmlim 3600 > solutions/$(basename $instance .dat).sol
done
