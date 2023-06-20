port=$1
src=$2
user=$3
ip=$4
dest=$5

scp -P $port $src $user@$ip:$dest
