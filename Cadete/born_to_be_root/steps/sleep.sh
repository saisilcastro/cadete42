string=$(who -b | awk '{printf $4}')
substr=$(echo $string | awk '{print substr ($0, 4)}')
second=$[(substr % 10) * 60]
sleep $second
