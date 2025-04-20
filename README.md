| Command | Description |
|---------|-------------|
| `10` | Increment the current cell value by 1 |
| `01` | Decrement the current cell value by 1 |
| `011` | Move the memory pointer to the right (next cell) |
| `101` | Move the memory pointer to the left (previous cell) |
| `1101` | Output the current cell value as an ASCII character |
| `1111` | Input a character and store its ASCII value in the current cell |
| `10111` | Jump past the matching `01000` if the current cell value is 0 |
| `01000` | Jump back to the matching `10111` if the current cell value is not 0 |
| `0101` | Output the current cell value as an integer |
| `0111001` | Copy the current cell value (the next use overwrites the current cell with the copied value) |
| `1010101011010101110101010` | Read an integer from input and store it in the current cell |
| `1111100` | Print the values of neighboring cells (two cells on each side) |
| `11001010` | Convert the current cell's value between integer and character representation |
| `*` | Add the value of a cell to the current cell's value. The number of consecutive `*` characters determines which cell to add (starting from cell 0) |
| `-` | Generate a pseudo-random number (0-255) and store it in the current cell |
