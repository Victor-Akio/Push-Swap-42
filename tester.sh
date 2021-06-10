# make re
# chmod 766 checker
# chmod 766 push_swap

#indentify the file here;
# ARG=$(cat tests/valid_500)
# time -f "%e" -o Output.log ./push_swap $ARG
# echo "-------------------------------------------"
# first=`./push_swap $ARG | wc -l`
# second=1
# echo "The number of operations is ...."
# count=$((first - second))
# echo $count

# ./checker $ARG

# Adrian's test
ARG=10

perl adrian.pl $ARG
perl adrian.pl $ARG --count
