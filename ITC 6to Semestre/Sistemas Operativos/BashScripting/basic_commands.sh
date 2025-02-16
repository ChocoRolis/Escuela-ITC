#!/bin/sh

#if-else
is_adult() {
	if [ $age -ge 21 ]; then
		echo "your age is: $age. You are an adult!"
	else
		echo "your age is: $age. You are a minor!"
	fi
}

# echo 
echo "hi! how are you doing?"
echo "lets learn bash scripting!"
echo there are multiple ways to display a message with echo
echo tell me your age:

#read
read age

#function with parameters
is_adult age

#read with flags
read -p "the read command also has flags, wait sorry what was your name? " name
echo "good to meet you $name! remember to use $ only when dereferencing a variable!"

#for loop
echo "lets count to $age!"

for i in $(seq 0 $age); do
	echo -n "$i "
done 

echo "\n"
 
#while 
