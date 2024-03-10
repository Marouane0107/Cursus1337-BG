#!/bin/sh

chown -R mysql:mysql /var/lib/mysql

sed -i "s#bind-address            = 127.0.0.1#bind-address=*#g" /etc/mysql/mariadb.conf.d/50-server.cnf

service mariadb start
sleep 2

mariadb -hlocalhost -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DB}\`;"
mariadb -hlocalhost -e "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';"
mariadb -hlocalhost -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DB}\`.* TO \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';"
mariadb -hlocalhost -e "FLUSH PRIVILEGES;"

service mariadb stop

exec    mysqld_safe