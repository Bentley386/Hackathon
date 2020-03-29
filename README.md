# MojeDelo Hackathon Intro Problem

My solution to the intro project for the hackathon hosted by Mojedelo.com

## Problem Statement

### LedDisplay

You have an order from a certain store. They want to display certain information on the LED screen to the buyer, scanning the bar code of some item. They  want the name, price and description of the scanned item displayed. Different stores around Slovenia have screens of diffrent sizes, but they are all rectangular.
The width and the height of the screen are given, along with the text to be displayed. As we want to make use of the whole screen, we need to calculate how big (how many pixels) an individual character of the text can be, 
without dividing any word with line breaks in the proccess. All characters have the same height and width (eg. 'l' and 'm' take up the same of space, as does ' '). 
There is no extra space between neighbouring characters or rows.

### Input

Every line of the input file includes one test case in the form of 'S V B'.
S is the width and V is the height in pixels, while B is the text to be displayed.

### Output

Output includes one line for each case. If we cannot display the text, the answer is 0.

### Example

```
Input:
20 6 led display
100 20 led display 2020
10 20 MUST BE ABLE TO DISPLAY
55 25 Can you hack
100 20 display  product text

Output:
2
9
1
8
8
```

## Solution

First version of the program and the basic algorithm was written in c++. It's available in c++ folder and takes input from a text file.
The main program is written in Dirst ( All information regarding Dirst is on: https://esolangs.org/wiki/Dirst).
Dirst is an esoteric language, in which the program structure is represented by a tree of folders and files.
So for example, different folders represent loops/if statements (depending on their names),
while the existence of "dsl_Hello world.txt" file writes "Hello world" to stdout.

The Dirst program uses the same algorithm as the c++ one, with some obvious differences (Dirst has a built in method to split a string into array, but has no working method to get the length of a string or an array).

To run the program, type the following in the console, while located in the "Dirst" folder:
`Dirst.exe CodeImproved`

The difference between the two different versions of the program "Code" and "CodeImproved" are that the second one uses bisection to find the solution, while the first one does not.

Files "Code.txt" and "CodeImproved.txt" contain the folder/file structure of the program (much more readable than manually creating the files + can put comments in it), from which the main program was created, by calling Dirst.exe with -e flag eg.
`Dirst.exe -e Code.txt Code` 
