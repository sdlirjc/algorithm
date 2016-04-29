md5=`md5sum $1`
echo "${md5:0:32}" | tr "[a-z]" "[A-Z]" # upper to lower
