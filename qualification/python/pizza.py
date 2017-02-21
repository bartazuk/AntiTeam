import sys
from collections import namedtuple

#struct
statement = namedtuple("nb_row", "nb_column", "min_ingredient", "max_cell")


#Progress Arguments
def Extract_Data():
	if len(sys.argv) < 3:
		sys.stdout.write("Erreur. Syntaxe = <input_filename> <output_filename>\n")
		sys.stdout.flush()
		sys.exit(1)
	inFile_str = "../inputs/"+sys.argv[1]
	with open(inFile_str, 'r') as inFile_fd:
		nb_line = 0
		statement = inFile_fd.readline().split()
		print(statement)
		for line in inFile_fd:
			nb_line +=1
			#extract data
		sys.stdout.flush()

#Main function
if __name__ == "__main__":
	sys.stdout.write("Hello World\n")
	sys.stdout.flush()
	Extract_Data()
	sys.exit(0)