#!/bin/bash

verify()
{
    command=$"grep 'my_putchar(char ' $1 || grep 'main(void)' $1"
    resultat=$(eval $command)
    if [ -n "$resultat" ]; then
        echo "Le fichier n'est pas valide"
    else
        echo "Tout est bon !"
    fi
}

verify "$1"
