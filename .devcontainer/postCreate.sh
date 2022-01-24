#!/bin/bash

# Aktionen, die nach der Estellung des Containers ausgeführt werden.
# Brauchen wir aktuell nicht

# ls bitte mit Farbe ...
cat << EOF >> ~/.bashrc
export LS_OPTIONS='--color=auto'
alias ls='ls \$LS_OPTIONS'
alias ll='ls \$LS_OPTIONS -l'
alias l='ls \$LS_OPTIONS -lA'
EOF
