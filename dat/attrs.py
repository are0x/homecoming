# coding: utf-8

import csv
import sys

if __name__ == '__main__':

    with open(sys.argv[1]) as infile:
        reader = csv.reader(infile)
        with open(sys.argv[2], 'w') as outfile:
            for row in reader:
                outfile.write(('\t'.join([cell.decode('sjis') if cell else "NONE" for cell in row]) + '\n').encode('utf8'))
