#!/usr/bin/python
import sys

#THIS TOOL IS MADE FOR THE GAME WORLD OF HEANA - TEXT BASE RPG - "MindwareLab Game Studios".
#MIT Copyright www.mindwarelab.com

def init():
    argv = sys.argv
    try:
        with open(argv[1], 'r') as readFile:
            text = readFile.read().replace(" "," <s> ").replace("\n"," <newline> ")
            print("Replacing the spaces, hold on ...")
            readFile.close()
        with open("{}_ready.txt".format(argv[1]), 'w') as writeFile:
            writeFile.write(text)
            print("{}_ready.txt is ready".format(argv))
            writeFile.close()
    except ValueError as e:
            print(e)

init()
