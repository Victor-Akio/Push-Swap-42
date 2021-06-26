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
# ----------------------------------------------------------------------
# Adrian's test
# ARG=10

# perl adrian.pl $ARG
# perl adrian.pl $ARG --count
#------------------------------------------------------------------------
# Nayran's tests.
make re

ko ()
{
	if [ $1 == "KO" ]; then
		echo "OK"
	else
		echo "Error"
	fi
}

error ()
{
	if [ $1 == "Error" ]; then
		echo "OK"
	else
		echo "Error"
	fi
}

arg ()
{
	Y=$(./push_swap $1 | wc -l)
	X=$(./push_swap $1 | ./checker_linux $1)
	echo "$X - $Y"
}


echo "Errors"
error $(./push_swap sad)
error $(./push_swap 1 1 2)
error $(./push_swap 1 2 2)
error $(./push_swap 2147483648)
error $(./push_swap -2147483648)

echo "\nNothing"
./push_swap 2147483647
./push_swap -2147483647
./push_swap
./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
echo "OK"

echo "\n3 args (max 3)"
ARG="2 1 0"
arg "$ARG"
ARG="1 0 2"
arg "$ARG"
ARG="0 2 1"
arg "$ARG"

echo "\n5 args (max 12)"
ARG="1 5 2 4 3"
arg "$ARG"
ARG="`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`"
arg "$ARG"

echo "\n100 args (max 1500)"
ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
arg "$ARG"

echo "\n500 args (max 11500)"
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
arg "$ARG"
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`"
arg "$ARG"
