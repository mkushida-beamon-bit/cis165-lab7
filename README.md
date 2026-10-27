# CIS 165 Lab 7: Selection Statements

## Plans

### Program 1: Body Mass Index (`bmi.cpp`)

1. Ask the user to enter their weight in pounds and height in inches.
2. Store both inputs as double variables.
3. Check if either value is zero or negative. If so, display an error message and end the program.
4. Calculate BMI using the formula weight times 703.0 / (height * height) and store the answer in a variable.
5. Use `if`, `else if`, and `else` statements to determine whether the BMI is underweight, optimal weight, or overweight.
6. Display the BMI rounded to two decimal places and print the correct category.

### Program 2: Color Mixer (`color_mixer.cpp`)

1. Ask the user to enter two primary colors: red, blue, or yellow.
2. Store the inputs in character arrays using a named constant for the array size.
3. Use `setw` to limit the number of characters read and `strcmp` to compare the color names.
4. Check whether both inputs are valid. If either color is invalid, display an error message.
5. If both colors are the same, display that color. Otherwise, use selection statements to determine the correct mixed color.
6. Display the resulting color.

## 2. Test Records

### Program 1: Body Mass Index

| Program/test | Inputs | Expected result | Actual result | Match or correction |
|---|---|---|---|---|
| BMI 1 | 100, 70 | 14.35 — Underweight | 14.35 — Underweight | Match |
| BMI 2 | 150, 70 | 21.52 — Optimal weight | 21.52 — Optimal weight | Match |
| BMI 3 | 200, 70 | 28.69 — Overweight | 28.69 — Overweight | Match |
| BMI 4 | 150, 0 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI 5 | -150, 70 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI 6 (extra) | 0, 70 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI 7 (extra) | 130, 70 | 18.64 — Optimal weight | 18.64 — Optimal weight | Match |

### Program 2: Color Mixer

| Program/test | Inputs | Expected result | Actual result | Match or correction |
|---|---|---|---|---|
| Color 1 | red, blue | purple | Result: purple | Match |
| Color 2 | red, yellow | orange | Result: orange | Match |
| Color 3 | blue, yellow | green | Result: green | Match |
| Color 4 | blue, red | purple | Result: purple | Match |
| Color 5 | red, red | red | Result: red | Match |
| Color 6 | orange, blue | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color 7 | red, orange | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color 8 (extra) | blue, blue | blue | Result: blue | Match |
| Color 9 (extra) | yellow, red | orange | Result: orange | Match |
| Color 10 (extra) | yellow, yellow | yellow | Result: yellow | Match |
| Color 11 (extra) | blue, green | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |

---

## 3. Code Explanations

### Program 1: Body Mass Index

1. How does the BMI formula use pounds and inches? Why is `height * height` needed?

The formula multiplies weight in pounds by 703 and divides it by height in inches squared. The expression `height * height` squares the height.

2. How do your conditions handle exactly 18.5 and exactly 25.0? Does the order matter?

The first condition checks whether BMI is less than 18.5. The second condition checks whether BMI is less than or equal to 25.0 after the first condition fails. This means exactly 18.5 and exactly 25.0 are classified as optimal. The order matters because the `else if` condition is evaluated only if the first condition is false.

3. Why check weight and height before calculating BMI?

Weight and height must both be greater than zero. Checking them first prevents an invalid calculation and allows the program to display an error message instead.

4. Why classify the unrounded BMI and round only its displayed value?

Rounding before classification could change the category of a BMI near a boundary. The program uses the original `double` value for its conditions and uses `fixed` and `setprecision(2)` only to format the displayed result.

### Program 2: Color Mixer

5. What does `strcmp` return for equal text? Why is `==` not the correct comparison for character-array contents?

`strcmp` returns zero when two null-terminated character strings contain the same text. Using `==` does not compare character-array contents as required by this assignment. I use `strcmp(first_color, "red") == 0` to check whether the input matches `red`.

6. How do you make each mixture work in either input order and handle identical colors?

Each mixture condition checks both possible orders of the two colors. Before checking mixtures, the program checks whether both valid inputs are identical. If they match, the program displays that color.

7. How do you check for an invalid color in either input position?

The program checks each input separately and stores the results in `first_valid` and `second_valid`. The condition `!first_valid || !second_valid` detects whether either input is invalid. The program displays an error instead of a mixed color.

8. How do named constants and result variables make the programs easier to read and check?

The named constant `COLOR_SIZE` gives the array size a clear meaning and avoids an unexplained number. The `bmi` variable stores the calculation so it can be displayed and classified. The validity variables make the color checks easier to understand.

---

## 4. Compilation and Execution


### Compile and run `bmi.cpp`

```bash
g++ -std=c++17 -Wall -Wextra bmi.cpp -o bmi
./bmi
```

### Compile and run `color_mixer.cpp`

```bash
g++ -std=c++17 -Wall -Wextra color_mixer.cpp -o color_mixer
./color_mixer
```

After testing, I recorded the actual results in the tables above, corrected any problems, and compiled and ran both final versions again.

---

Before submitting, I checked that all four files are visible in the repository and that the latest commit contains the final tested versions.
