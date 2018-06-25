#!/bin/bash -ex

mkdir -p solutions10800

for instance in instances/*.dat; do
    glpsol -m gap.mod -d $instance --tmlim 10800 > solutions10800/$(basename $instance .dat).sol
done
