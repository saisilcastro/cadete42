myhost=lde-cast

hostnamectl set-hostname $myhost

#we must change the username in this fucking folder too
#otherwise the linux won't allow us to do anything
sudo nano /etc/hosts
