files := file1 file2
some_file: $(files)
	echo "Look at this variable: " $(files)
	touch some_file
file1:
	touch file1
file2:
	touch file2

a := one two
b := 'one two'
x := dude
all:
	printf '$a'
	printf $b
	# Reference variables using either ${} or $()
	echo $(x)
	echo ${x}

	# Bad practice, but works
	echo $x
clean:
	rm -f file1 file2 some_file