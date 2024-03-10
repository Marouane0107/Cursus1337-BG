FROM debian:11

RUN apt-get update -y && apt-get install mariadb-server -y

COPY conf/50-server.cnf		/etc/mysql/mariadb.conf.d/

COPY tools/database.sh /

RUN chmod 755 /database.sh

EXPOSE 3306

CMD [ "./database.sh" ]
