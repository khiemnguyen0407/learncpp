all: one two
	# Output "hey" since this is the target name
	echo $@

	# Output all prerequisites newer than the target
	echo $?

	# Output all prerequisites
	echo $^

	# Output the first prerequisites
	echo $<

	echo "all" > all.txt

one:
	echo "one" > one.txt

two:
	echo "two" > two.txt

clean:
	rm -f all.txt one.txt two.txt