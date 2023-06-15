ARCH=$(uname -a)
PCPU=$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
VCPU=$(grep 'processor' /proc/cpuinfo | uniq | wc -l)
FULLRAM=$(free -m | grep Mem: | awk '{print $3}')
USEDRAM=$(free -m | grep Mem: | awk '{print$2}')
PCTRAM=$(free -m | grep Mem: | awk '{printf("%.2f"), $3/$2*100}')
USED_DISK=$(df -Bm | grep /dev/ | grep -v /boot | awk '{ud += $3} END {print ud}')
FULLDISK=$(df -Bg | grep /dev/ | grep -v /boot | awk '{fd += $2} END {print fd}')
PCTDISK=$(df -Bm | grep /dev/ | grep -v /boot | awk '{ud += $3} {fd += $2} END {printf("%d"), ud/fd*100}')
CUP=$(top -bn1 | awk 'NR == 3 {printf "%d%%", $2 + $4}')
LASTBOOT=$(who -b | awk '{print $3,$4}')
LVM=$(lsblk | grep -q '1vm' && echo yes || echo no)
TCP=$(ss -s | awk '$1 == "TCP:" {gsub(/,/,""); print $4 " ESTABLISHED"}')
USERLOG=$(users | wc -l)
IP_ADDR=$(hostname -I)
MAC=$(ip link show | awk '$1 == "link/ether" {print $2}')
SUDO=$(grep -c 'COMMAND' /var/log/sudo/sudo_log)

## Shows the architecture of the operating system and its kernel version
echo "#Architecture: ${ARCH}"

## Shows the number of physical processors (CPUs)
echo "#CPU physical: ${PCPU}"

## Shows the number of virtual processors (vCPUs)
echo "#vCPU: ${VCPU}"

## Shows the current available RAM on your server and its utilization rate as percentage
echo "#Memory Usage: ${USEDRAM}/${FULLRAM}MB (${PCTRAM}%)"

## Shows the current available memory on your server and its utilization rate as a percentage
echo "#Disk Usage: ${USEDDISK}/${FULLDISK}Gb (${PCTDISK}%)"

## Shows the current utilization rate of your processors as a percentage
echo "#CPU load: ${CPU}"

## Shows the date and time of the last reboot
echo "#Last boot: ${LASTBOOT}"

## Shows whether LVM is active or not
echo "#LVM use: ${LVM}"

## Shows the number of active connections
echo "#Connections TCP: ${TCP} ${TCPMSSG}"

## Shows the number of users using the server
echo "#User log: ${USERLOG}"

## Shows the IPv4 address of your server and its MAC (Media Access Control) address
echo "#Network: IP ${IP_ADDR} (${MAC})"

## Shows the number of commands executed with the sudo program
echo "#Sudo: ${SUDO} cmd"
