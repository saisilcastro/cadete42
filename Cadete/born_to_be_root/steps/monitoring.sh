arch=$(uname -a)
physical_cpu=$(cat /proc/cpuinfo | grep processor | wc -l)
virtual_cpu=$(grep "processor" /proc/cpuinfo | uniq | wc -l)
m_used=$(free -m | grep Mem: | awk '{print $3}')
m_total=$(fcpuree -m | grep Mem: | awk '{print $2}')
ram_percentage=$(free -m | grep Mem: | awk '{printf("%.2f"), $3/$2*100}')
d_used=$(df -Bm | grep /dev/ | grep -v /boot | awk '{ud += $3} END {print ud}')
f_used=$(df -Bg | grep /dev/ | grep -v /boot | awk '{fd += $2} END {print fd}')
disk_percent=$(df -Bm | grep /dev/ | grep -v /boot | awk '{ud += $3} {fd += $2} END {printf("%d"), ud/fd*100}')
cpu_load=$(mpstat | grep all | awk '{printf "%.1f", 100 - $13}')
last_boot=$(who -b | awk '{print $3,$4}')
lvm_use=$(lsblk | grep -q '1vm' && echo yes || echo no)
tcp_con=$(ss -s | awk '$1 == "TCP:" {gsub(/,/,""); print $4 " ESTABLISHED"}')
user_log=$(users | wc -l)
ip_addr=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

echo "#Architecture: "$arch
echo "CPU physical: "$physical_cpu
echo "vCPU: "$virtual_cpu
echo "Memory Usage: "$m_used/$m_total"Mb ("$ram_percentage"%)"
echo "Disk Usage: "$d_used"/"$f_used"Mb ("$disk_percent"%)"
echo "CPU load: "$cpu_load
echo "Last boot: "$last_boot
echo "LVM use: "$lvm_use
echo "Connections TCP: "$tcp_con
echo "User log: "$user_log 
echo "Network: IP "$ip_addr "("$mac")"
echo "Sudo: "$sudo" cmd"
