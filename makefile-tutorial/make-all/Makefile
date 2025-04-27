all: one two three f1.o f2.o

one: 
	echo "File 1" > one.txt
two:
	echo "File 2" > two.txt
three:
	echo "File 3" > three.txt
f1.o f2.o:
	echo $@
# Equivalent to:
# f1.o:
# 	echo f1.o
# f2.o:
# 	echo f2.o
clean:
	rm -f one two three