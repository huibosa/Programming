#!/usr/bin/env bash

foo=
echo ${foo:-"substitue value if unset"}
echo foo

foo=bar
echo ${foo:-"substitue value if unset"}
echo foo



foo=
echo ${foo:="default value if unset"}

foo=bar
echo ${foo:="default value if unset"}
echo $foo



foo=
echo ${foo:?"parameter is empty"}
echo $?

foo=bar
echo ${foo:?"parameter is empty"}
echo $foo
echo $?



foo=
echo ${foo:+"substitute value if set"}

foo=bar
echo ${foo:+"substitute value if set"}
echo $foo
