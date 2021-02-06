# A Demo For The Single-line Text Scrolling with LCD1602

***

## Table of Contents
1. [General Info](#general-info)
2. [Solution](#solution)
4. [Known Issues](#known-issues)

## General Info

This demo project shows you how to make a single-line marquee on a double lined LCD1602 LCD screen. The LCD1602 module driver has no such API that scrolls a single line text independently. When you put two lines of string on the screen, how can you make only one single line moving standalone?

## Solution

Actually, the solution may be much simpler than what you've ever expected. 

Let's have a look at the screen first. There are two lines on the screen. Each line has 16 cells. Each cell shows only one character. If we show one character at the leftmost cell on the first line first, and then suddenly earase it and show the character at the cell next to the previous cell, you may think that the character is moved from left to right for a cell. If you repeat the operation above periodically in a very fast speed, you will see the character moving smoothly. 

Now, if we render a character on a cell in turns and sequentially, and render other characters on their original cells, what shall we see?

## Known Issues

The LCD1602 module flashing rate is not fast enough to render characters smoothly. If you do rendering operation in a high frequency, you may not get a clear display on the screen.

Also, do the position calculation carefully. The memory space overflow will cause the display looks so weird, and you may get some cells interfered by garbage characters.