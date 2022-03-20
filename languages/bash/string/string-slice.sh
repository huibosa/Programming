#!/usr/bin/env bash

foo="This string is long."

echo ${foo:5}
echo ${foo:5:6}
echo ${foo: -5}
echo ${foo: -5:2}
