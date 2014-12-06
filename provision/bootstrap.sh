#!/usr/bin/env bash

apt-get update
# We set DEBIAN_FRONTEND to noninteractive in order to bypass all prompts that
# require user input.
export DEBIAN_FRONTEND=noninteractive
apt-get install mysql-server nginx php5-fpm -y
cp /vagrant/provision/config/php.ini /etc/php5/fpm/php.ini
cp /vagrant/provision/config/www.conf /etc/php5/fpm/pool.d/www.conf
cp /vagrant/provision/config/nginx_vhost /etc/nginx/sites-available/nginx_vhost
ln -s /etc/nginx/sites-available/nginx_vhost /etc/nginx/sites-enabled/nginx_vhost
rm /etc/nginx/sites-enabled/default
sudo service php5-fpm restart
service nginx restart