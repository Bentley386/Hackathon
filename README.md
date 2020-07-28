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

My main goal was to write the program in Dirst, which was more difficult. In case it turned out speed mattered, I've also programmed the solution in c++.

### C++

The C++ program simply finds the solution by trial and error, using binary search to speed up the process. To run it move to the "c++" folder and type `./hackathon.exe` in the console.

### Dirst

Dirst is an esoteric language, in which the program is represented by a tree of various folders and files (All information regarding Dirst is on: https://esolangs.org/wiki/Dirst).

To run the program, move to the "Dirst" folder and type the following in the console:
`Dirst.exe Code`

The "Code.txt" file contains the structure of the folders/files tree of the program (this makes it much more readable than reading the code by traversing through folders and has an added advantage of allowing comments).
The corresponding folders/files tree was then cretaed by calling Dirst.exe with an -e flag:
`Dirst.exe -e Code.txt Code`.
