#!/bin/bash
DATA="$(date +%Y/%m/%d,%H:%M:%S)"
TARGET=".test"
echo "${DATA}" > "${TARGET}"
exec < "${TARGET}"
read TEST
if [ "${DATA}" == "${TEST}" ]; then
  echo "Status: 200 OK"
  echo "Content-Type: text/plain"
  echo
  echo "OK"
  exit 0
fi
echo "Status: 500 Error"
echo "Content-Type: text/plain"
echo
echo "FAIL: Test failed"
