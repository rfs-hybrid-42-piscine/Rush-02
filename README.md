*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-rush02.png" alt="Rush 02 Cover" width="100%" />
</div>

<div align="center">
  <h1>🚀 Rush 02: The Number Dictionary</h1>
  <p><i>File I/O, string parsing, and algorithmic number-to-text conversion.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-125%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**Rush 02** is the final collaborative weekend project of the 42 C Piscine. Teams must create a C program that takes a number as an argument and converts it to its written letters value. 

Instead of hardcoding the English language into the program, the translation is powered by a reference dictionary file. This means the program dynamically reads, parses, and maps numeric keys to their string values using low-level file descriptors. By simply swapping the dictionary file, the program could theoretically translate numbers into any language!

---

## 🧠 Core Logic Breakdown

Building this project requires splitting the architecture into two distinct engines: the **Parser** and the **Translator**.

### 🔹 The Dictionary Parser
The program must parse the dictionary given as a resource, allowing its values to be used to print the result. 
1. **File Reading:** We use system calls to open and read the `.dict` file into a dynamically allocated linked list.
2. **Strict Formatting:** The parser processes the file line by line, looking for a numeric key, a colon, and the corresponding string value. 
3. **Trimming:** The parser must trim all excess spaces before and after the values to ensure clean output.
4. **Error Handling:** If there is an invalid line format, a missing initial key, or a memory failure, the program gracefully catches it, frees all memory, and outputs a standard dictionary error.

### 🔹 The Number Translator
Once the dictionary is safely stored in memory, the recursive translation algorithm begins.
1. **Input Validation:** The program verifies that the user's argument is a valid positive number, trimming leading zeros and validating digits.
2. **Chunking (Modulo 1000):** Numbers are read in chunks of three (e.g., millions, thousands, hundreds). The algorithm recursively divides the input by 1000, isolating chunks like `123` or `456`.
3. **Hundreds, Tens, and Ones:** Inside each chunk, the algorithm breaks the number down further (e.g., `456` becomes `4` + `hundred` + `50` + `6`).
4. **Dictionary Lookup:** Every isolated piece is searched for inside the parsed dictionary map and printed to the standard output. 

### ⭐ Bonus Features Implemented
* **Standard Input Parsing:** If no arguments are provided to the executable, the program dynamically reads the requested number from standard input (`stdin`) using a custom `get_next_line` implementation.
* **Syntax Injection:** The recursive algorithm is designed to inject grammatically correct hyphens (e.g., `forty-two`), commas for large magnitudes (e.g., `one million, two hundred thousand`), and the "and" conjunction (e.g., `one hundred and forty-two`) as requested in the bonus section.
* **Custom Language Dictionaries:** The program fully supports passing a custom `.dict` file as the first argument, allowing it to parse and translate numbers into entirely different languages.

---

## 🛠️ Instructions

### 🧪 Compilation & Testing
This project utilizes a professional directory structure (**[`srcs/`](ex00/srcs/)**, **[`includes/`](ex00/includes/)**, `objs/`) and requires a **[`Makefile`](ex00/Makefile)** to compile.

1. **Clone the repository:**
   ```bash
   git clone git@github.com:rfs-hybrid-42-piscine/Rush-02.git Rush-02
   cd Rush-02/ex00
   ```

2. **Compile the executable:**
   ```bash
   make
   ```

3. **Execute with standard dictionary:**
   Pass a single numeric argument to translate it using the default dictionary.
   ```bash
   ./rush-02 42
   # Expected Output: forty-two
   ```

4. **Execute with a custom dictionary:**
   Pass the custom dictionary path as the first argument, and the number as the second.
   ```bash
   ./rush-02 custom.dict 100000
   # Expected Output: one hundred thousand
   ```

5. **Execute via Standard Input (Bonus):**
   Run the executable with no arguments, type a number, and press `Enter`.
   ```bash
   ./rush-02
   1000000
   # Expected Output: one million
   ```

6. **Clean up:**
   ```bash
   make fclean
   ```

### 🚨 The Norm & Constraints
* **Allowed Functions:** You are strictly limited to basic memory allocation, file descriptors, and writing to the standard output.
* **Memory Management:** Any memory allocated on the heap must be freed correctly. Memory leaks are strictly tested during evaluation.
* **The Norm:** Every single `.c` and `.h` file must pass the 42 Norm.
* **The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:20:51 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/17 00:15:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command before pushing to evaluate the source and include directories:
```bash
norminette -R CheckForbiddenSourceHeader srcs/ includes/
```

---

## 📚 Resources & References

* `man 2 open` / `man 2 read` / `man 2 close` - Manuals for system calls required to read the dictionary.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.
* [Official 42 Norminette Repository](https://github.com/42School/norminette) - The open-source linter enforcing the strict 42 coding standard.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions were built manually to strictly comply with the 42 Norm and deeply understand manual memory manipulation and parsing algorithms.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
