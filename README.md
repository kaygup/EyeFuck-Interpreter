| Command | Description |
|---------|-------------|
| `10` | raise the value of the current memory cell by 1 |
| `01` | make the value of the current cell smaller by 1 |
| `011` | Move pointer one cell forward |
| `101` | Move pointer one cell backwards |
| `1101` | Print current cell's value as an ascii character |
| `1111` | input a character and store it in the current cell |
| `10111` | Jump past the matching 01000 if the cell value is 0 |
| `01000` | Jump back to the matching 10111 if the cell value is not 0 |
| `0101` | put the current cell's value out as an integer |
| `0111001` | copy current cell's value , if used again replaces the value with the copied one |
| `1010101011010101110101010` | read an integer as input and store in current cell |
| `1111100` | print the values of the neighbouring cell's (help function to help your brain a little)  |
| `11001010` | convert current cell's value to integer if its ascii or vice versa |
| `*` | add the value to the cell depending on the count of start starting with 0 `*`, cell 1 `**`, cell 2 `***` etc.) |
| `-` | generate a random number from 0 to 255 and store it in current cell |

Simple hello world program with correct spacing and punctuation:
```
10 10 10 10 10 10 10 10 10 10 
10111
01
011 10 10 10 10 10 10 10
101
01000
011 10 10 1101
011 10 10 10 10 10 10 10 10 10
10111
01
011 10 10 10 10 10 10 10 10 10 10
101
01000
011 10 10 10 10 10 10 10 10 10 10 10 1101
011
10 10 10 10 10 10 10 10 10 10
10111
01 011 10 10 10 10 10 10 10 10 10 10 10 101 01000
011 01 01 1101
011
10 10 10 10 10 10 10 10 10 10
10111
01 011 10 10 10 10 10 10 10 10 10 10 10 101 01000
011 01 01 1101
011 10 10 10 10 10 10 10 10 10 10 10111 01 011 10 10 10 10 10 10 10 10 10 10 10 101 01000 011 10 1101
011 10 10 10 10 10 10 10 10 10 10 10111 01 011 10 10 10 10 101 01000 011 10 10 10 10 1101
011 10 10 10 10 10 10 10 10 10 10
10111 01 011 10 10 10 101 01000 011 10 10 1101 011 10 10 10 10 10 10 10 10 10 10
10111 01 011 10 10 10 10 10 10 10 10 10 101 01000 011 01 01 01 1101
011 10 10 10 10 10 10 10 10 10 10 10111 01 011 10 10 10 10 10 10 10 10 10 10 10 101 01000 011 10 1101
011 10 10 10 10 10 10 10 10 10 10 10111 01 011 10 10 10 10 10 10 10 10 10 10 10 101 01000
011 10 10 10 10 1101 011 10 10 10 10 10 10 10 10 10 10 10111 01 011 10 10 10 10 10 10 10 10 10 10 10 101 01000 011 01 01 1101
011 10 10 10 10 10 10 10 10 10 10 10111 01 011 10 10 10 10 10 10 10 10 10 10 101 01000 011 1101 011
10 10 10 10 10 10 10 10 10 10 10111 01 011 10 10 10 101 01000 011 10 10 10 1101 011 10 10 10 10 10 10 10 10 10 10 1101
```
