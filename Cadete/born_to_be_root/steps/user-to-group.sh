user=$1
group=$2
gpasswd -a $name $group

#show all groups

getent group

#add group
group=root
flag=-a #add
flag=-d #delete

groupadd $flag $group

#add user -m = no-home

adduser $user

#delete user

userdel $user

