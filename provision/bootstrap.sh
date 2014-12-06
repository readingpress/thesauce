#!/usr/bin/env bash

apt-get update
# We set DEBIAN_FRONTEND to noninteractive in order to bypass all prompts that
# require user input.
export DEBIAN_FRONTEND=noninteractive
apt-get install mysql-server nginx php5-fpm -y
# This protects against php execution of files with other extensions that could
# be uploaded by a user.
# @see https://nealpoole.com/blog/2011/04/setting-up-php-fastcgi-and-nginx-dont-trust-the-tutorials-check-your-configuration/
sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g' /etc/php5/fpm/php.ini
# Upload vhosts config to nginx and enable the site. In nginx this is 
# accomplished by creating a symlink from a sites-available config file to 
#	sites-enabled.
cp /vagrant/provision/config/nginx_vhost /etc/nginx/sites-available/nginx_vhost
ln -s /etc/nginx/sites-available/nginx_vhost /etc/nginx/sites-enabled/nginx_vhost
rm /etc/nginx/sites-enabled/default
service nginx start