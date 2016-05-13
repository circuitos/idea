#!/bin/bash
for f in common/*; do
  echo $f
done

files() {

  for f in $1/*; do
    if [[ -d $f ]]; then
      files $f
    elif [[ -f $f ]]; then
      echo $f
    fi
  done
    
}

files "categories"

