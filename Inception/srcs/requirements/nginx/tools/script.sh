#!/bin/sh

openssl req -x509 -nodes -out $SSL_CRL -keyout $SSL_KEY -subj "/CN=$DOMAIN_NAME"

sed -i "s|domain|$DOMAIN_NAME|" /etc/nginx/conf.d/default.conf
sed -i "s|ssl_crl|$SSL_CRL|" /etc/nginx/conf.d/default.conf
sed -i "s|ssl_key|$SSL_KEY|" /etc/nginx/conf.d/default.conf

nginx -g "daemon off;"