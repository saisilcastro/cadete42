sudo ufw allow ssh #create firewall rule on /etc/services
sudo ufw allow 4242 #setup ufw to port 4242
sudo ufw enable #enable the service
sudo ufw status verbose #get the firewall status
sudo ufw status numbered #get the number of unlocked ports
number=1 #number of port to remove
sudo ufw delete $number
