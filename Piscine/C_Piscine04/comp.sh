n=$1
file=$2
cc ./ex$n/$file.c ./ex$n/main.c -o ./ex$n/main -Wall -Wextra -Werror -lbsd