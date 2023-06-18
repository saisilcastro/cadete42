whole=$(who -b | awk '{printf $4}')
minute=$(echo $whole | awk '{print substr ($0, 4)}')
remain=$[minute % 10]
time=$[remain*60]
sleep 1
echo fucker is $time
