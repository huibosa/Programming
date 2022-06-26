#!/usr/bin/env bash

foo=JPG.JPG

echo ${foo/JPG/jpg}
echo ${foo//JPG/jpg}
echo ${foo/#JPG/jpg}
echo ${foo/%JPG/jpg}
