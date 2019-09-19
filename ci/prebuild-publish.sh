#!/bin/bash

if [[ $GITHUB_TOKEN ]]; then
  npm run prebuild-node -- -u "$GITHUB_TOKEN"
  npm run prebuild-electron -- -u "$GITHUB_TOKEN"
fi
