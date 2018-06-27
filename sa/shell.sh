#!/bin/bash -e

mkdir -p solutions

steps=100000

for seed in $(seq 0 9); do
    ./gap-sa instances/gapa-1.ext $seed 0.85 0.75 $steps > solutions/gapa-1-$seed.sol
    ./gap-sa instances/gapa-2.ext $seed 0.85 0.75 $steps > solutions/gapa-2-$seed.sol
    ./gap-sa instances/gapa-3.ext $seed 0.85 0.75 $steps > solutions/gapa-3-$seed.sol
    ./gap-sa instances/gapa-4.ext $seed 0.85 0.75 $steps > solutions/gapa-4-$seed.sol
    ./gap-sa instances/gapa-5.ext $seed 0.85 0.75 $steps > solutions/gapa-5-$seed.sol
    ./gap-sa instances/gapa-6.ext $seed 0.85 0.75 $steps > solutions/gapa-6-$seed.sol
    ./gap-sa instances/gapd-1.ext $seed 0.85 0.75 $steps > solutions/gapd-1-$seed.sol
    ./gap-sa instances/gapd-2.ext $seed 0.85 0.75 $steps > solutions/gapd-2-$seed.sol
    ./gap-sa instances/gapd-6.ext $seed 0.85 0.75 $steps > solutions/gapd-6-$seed.sol
done
