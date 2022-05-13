import pandas as pd
from collections import Counter

reads = pd.read_csv("C:\\Users\\gigim\Documents\BLI DATA\\reads.csv", header='infer', sep=",")
loci = pd.read_csv("C:\\Users\\gigim\Documents\BLI DATA\\loci.csv", header='infer', sep=",")

reads_starts = reads.loc[:, "start"]
reads_length = reads.loc[:, "length"]

loci_positions = loci.loc[:, "position"]


# function to calculate genomic sequence per given starting position and length
def calc(reads, length):
    sequence = []
    i = 0
    for i in range(length):
        sequence.append(reads+(i))
        i += 1
    
    return sequence

# dictionary to hold original start and full sequence
startsDict = {}
i = 0

# loop to generate keys
for i in range(len(reads_starts)):
    startsDict[reads_starts[i]] = None

    i += 1

# function to generate values for dictionary
def fullSequence():

    for i in range(len(reads_starts)):
        startsDict[reads_starts[i]] = calc(reads_starts[i], reads_length[i])

        i += 1



def overlaps(loci):
    fullSequence()
    
    x = loci
    d = Counter(startsDict)

    print('{}: ()'.format(x, d[x]))





#print(calc(reads_starts[0], reads_length[0]))

#print(fullSequence(reads_starts))

#print(overlaps(loci_positions))


overlaps(loci_positions[0])