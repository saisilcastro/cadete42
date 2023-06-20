port=$1
user=$2
ip=$3
to_get=$4
destiny=$5

scp -P $port $user@$ip:$to_get $destiny
