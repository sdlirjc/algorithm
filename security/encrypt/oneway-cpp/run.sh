sudo apt-get install libssl-dev

In Mac:
check this webpage: 
http://superuser.com/questions/1089390/how-to-install-libssl-dev-libffi-dev-on-mac-os

make 
./oneway --genkey private.key
./oneway --publickey private.key public.key
ls -lha 
./oneway --encrypt public.key LICENSE LICENSE.ascr
ls -lha 
./oneway --decrypt private.key LICENSE.ascr LICENSE.txt 
ls -lha 

