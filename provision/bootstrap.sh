#!/usr/bin/env bash

apt-get update
# We set DEBIAN_FRONTEND to noninteractive in order to bypass all prompts that
# require user input.
export DEBIAN_FRONTEND=noninteractive
apt-get install mysql-server nginx php5-fpm -y
# Overwrite php conf files with the copies in this project. This will make 
# config edits easy to apply.
cp /vagrant/provision/config/php.ini /etc/php5/fpm/php.ini
cp /vagrant/provision/config/www.conf /etc/php5/fpm/pool.d/www.conf
# To set up our virtual host, we need to put our conf file in nginx's 
# sites-available directory, and then create a symlink for it in nginx's
# sites-enabled directory. Lastly, we need to remove default from sites-enabled.
cp /vagrant/provision/config/nginx_vhost /etc/nginx/sites-available/nginx_vhost
ln -s /etc/nginx/sites-available/nginx_vhost /etc/nginx/sites-enabled/nginx_vhost
rm /etc/nginx/sites-enabled/default
# We need to restart our services to activate the new configuration.
sudo service php5-fpm restart
service nginx restart