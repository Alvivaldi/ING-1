#!/bin/bash


FICHIER="$1"


head -n 2 "$FICHIER"
tail -n +3 "$FICHIER" | sort -t':' -k2,2nr