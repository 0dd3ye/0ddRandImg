# 0ddRandImg
C++ script that generates random images from prnt.sc.

Usage: ./genRandImg

Options:

Main Interface:
  0: Exit Program: Kills the program
  1: Gen single random image: Pulls a random image from the internet and lets you name it
  2: Gen x random images: Pulls specified number of random images from the internet

Multiple Image Interface:
  0: Exit Program
  1: Go back to main interface: Goes back to main interface described above
  2: Name images manually: Basically the 2nd option in main interface looped a specified number of times
  3: Number method: Prompts user for base name and names images in format base + num + .png


Other things to note:

The imgGenObj object can be used in other programs if you wish. I don't know why you'd do that though, there is probably better stuff out there on github that does the same thing. I don't know I haven't checked.
