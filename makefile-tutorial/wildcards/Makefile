thing_wrong := *.one	# don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

all: one two three four five
# Fails, because $(thing_wrong) is simply the string "*.o"
# one: $(thing_wrong)		--> uncomment to see the error
one: 
	echo "Uncomment the above rule command to see the error!"
# Stays as *.o if there are no files that match this pattern: :(
two: *.o

# Works as you would expect! In this case, it does nothing.
three: $(thing_right)

# Same as the rule three
four: $(wildcard *.o)

five :
# Print out file information about every .c file
	print $(wildcard *c)
		ls -la $?