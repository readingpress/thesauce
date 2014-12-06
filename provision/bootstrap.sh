#!/usr/bin/env bash

apt-get update
# We set DEBIAN_FRONTEND to noninteractive in order to bypass all prompts that
# require user input.
export DEBIAN_FRONTEND=noninteractive
apt-get -y install mysql-server nginx php5-fpm -y
# Upload vhosts config to nginx and enable the site. In nginx this is 
# accomplished by creating a symlink from a sites-available config file to 
#	sites-enabled.
cp /vagrant/provision/config/nginx_vhost /etc/nginx/sites-available/nginx_vhost
ln -s /etc/nginx/sites-available/nginx_vhost /etc/nginx/sites-enabled/nginx_vhost
rm /etc/nginx/sites-enabled/default
service nginx start