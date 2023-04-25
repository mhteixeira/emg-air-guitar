import matplotlib.pyplot as plt
import glob
import re

file_list = glob.glob('./Data/*.txt')
for filename in file_list:
    # open the file
    with open(filename, "r") as f:
        lines = f.readlines()

    # extract the values after "->" and convert them to integers
    values = [int(line.split("->")[1].strip()) for line in lines]
    
    # Creates a new figure
    plt.figure()
    
    # plot the values
    plt.plot(values)

    # set the title and axis labels
    plt.title("Plot Title")
    plt.xlabel("X Label")
    plt.ylabel("Y Label")

    # save the plot as a PDF file
    plt.savefig(filename.split('.txt')[0] + '.pdf')
