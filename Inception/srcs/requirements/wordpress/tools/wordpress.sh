#!/bin/sh

if [ -f ./wp-config.php ]
then
    echo "WordPress is already exists"
else
    cd /var/www/
    wget http://wordpress.org/wordpress-6.4.3.tar.gz
	tar xfz wordpress-6.4.3.tar.gz
	rm -rf wordpress-6.4.3.tar.gz
    cd wordpress

	cp wp-config-sample.php wp-config.php
	sed -i "s/username_here/$MYSQL_USER/g" wp-config.php
	sed -i "s/password_here/$MYSQL_USER_PASSWORD/g" wp-config.php
	sed -i "s/localhost/$MYSQL_HOST/g" wp-config.php
	sed -i "s/database_name_here/$MYSQL_DB/g" wp-config.php

	wp core install --url=$DOMAIN_NAME --title=INCEPTION --admin_user=$MYSQL_USER --admin_password=$MYSQL_USER_PASSWORD --admin_email=$MYSQL_ADMIN_EMAIL --allow-root --path=/var/www/wordpress
	wp user create $USER $USER_EMAIL --role=author --user_pass=$USER_PASSWORD --allow-root --path=/var/www/wordpress
fi

exec php-fpm7.4 -F