apt install lighttpd
apt install mariadb-server mariadb-client -y
apt install php php-cgi php-fpm

systemctl enable lighttpd
lighttpd-enable-mod cgi
lighttpd-enable-mod fpm

service lighttpd force-reload

ufw allow 80

# /var/www/html
#word press install

sudo wget -c http://wordpress.org/latest.tar.gz
sudo tar -xzvf latest.tar.gz

#access database

mysql -u root

name=wordpress

CREATE database $name;
user=lde-cast
host=host
pass=1234
CREATE user '$user'@'$host' IDENTIFIED by '$pass';
GRANT ALL PRIVILEGES ON *.* TO '$user'@'$host';

in file wp-config.php set db, user, pass and host

