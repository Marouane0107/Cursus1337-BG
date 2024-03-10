FROM debian:11

RUN mkdir -p etc/nginx/ssl

RUN apt-get update && apt-get upgrade && apt install -y nginx && apt install openssl -y 

COPY ./conf/nginx.conf /etc/nginx/conf.d/default.conf

EXPOSE 443

COPY tools/script.sh /

RUN chmod 755 /script.sh

CMD ["./script.sh"]
