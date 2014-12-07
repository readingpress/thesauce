#!/usr/bin/env bash

echo 'Begin provisioning script'

echo 'Install LEMP stack'
apt-get update
# We set DEBIAN_FRONTEND to noninteractive in order to bypass all prompts that
# require user input.
export DEBIAN_FRONTEND=noninteractive
apt-get install mysql-server nginx php5-fpm -y
# Install PHP extensions.
apt-get install php5-mysql -y
echo 'LEMP stack installed'

echo 'Configure LEMP settings'
# We need to make a directory for the php5-fpm socket. Otherwise it cannot
# create the directory itself which leads to a server crash.
mkdir /var/run/php5-fpm
# Overwrite php conf files with the copies in this project. This will make 
# php config easy to edit.
cp /vagrant/provision/config/php.ini /etc/php5/fpm/php.ini
cp /vagrant/provision/config/www.conf /etc/php5/fpm/pool.d/www.conf
echo 'LEMP settings configured'

echo 'Create virtual host for thesauce'
# To set up our virtual host, we need to put our conf file in nginx's 
# sites-available directory, and then create a symlink for it in nginx's
# sites-enabled directory. Lastly, we need to remove default from sites-enabled.
cp /vagrant/provision/config/nginx_vhost /etc/nginx/sites-available/nginx_vhost
ln -s /etc/nginx/sites-available/nginx_vhost /etc/nginx/sites-enabled/nginx_vhost
rm /etc/nginx/sites-enabled/default
echo 'Virtual host created for thesauce'

echo 'Restart services'
# We need to restart our services to activate the new configuration.
service php5-fpm restart
service nginx restart
echo 'Services restarted'

echo 'Provisioning script complete'
