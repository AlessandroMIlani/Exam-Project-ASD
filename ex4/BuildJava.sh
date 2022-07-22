# !/bin/bash



case "$1" in

compile)
	if [ ! -d "./classes" ] 
		then
		mkdir classes
	fi
  cd ./src
	javac -d ../classes lib/*.java

	javac -d ../classes minheap/*.java

	javac -d ../classes main/*.java

	javac -d ../classes -cp .:../junit-4.12.jar:../hamcrest-core-1.3.jar test/*.java
	;;
remove)
	rm -rf ./classes
	;;
exec)
 cd classes
 java main/Main "../italian_dist_graph.csv"
	;;
test)
	cd classes
	java -cp '.:../junit-4.12.jar:../hamcrest-core-1.3.jar' test/TestRun
	;;
*)
	echo "Usage: ./BuildJava.sh [option]"
	echo "Options:"
	echo "	compile		Compile the project"
	echo "	remove		Remove the compiled files"
	echo "	exec		Execute the project with default input (in the same folder as this script)"
	echo "	test		Execute the test"
	echo "	help		Show this help"
	;;
esac

