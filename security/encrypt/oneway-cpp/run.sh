sudo apt-get install libssl-dev
make 
./oneway --genkey private.key
./oneway --publickey private.key public.key
ls -lha 
./oneway --encrypt public.key LICENSE LICENSE.ascr
ls -lha 
./oneway --decrypt private.key LICENSE.ascr LICENSE.txt 
ls -lha 

