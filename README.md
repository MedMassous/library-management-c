# 📚 Library Management System

## 🎯 Overview

This project is a comprehensive library management system developed in C. It allows you to manage a book collection with all necessary operations: adding, searching, borrowing, modifying, deleting, statistics, and report export.

---

## 📋 Features

### Basic Features
1. ✅ **Add a book** - Add new books to the library
2. ✅ **Search for a book** - Search by title or author
3. ✅ **Display all books** - Complete list with recursion
4. ✅ **Borrow a book** - Mark a book as borrowed
5. ✅ **Return a book** - Mark a book as available

### Advanced Features (NEW!)
6. ✅ **Delete a book** - Remove a book from the collection
7. ✅ **Modify a book** - Change book information
8. ✅ **Display statistics** - Overview with recursive counting
9. ✅ **Filter books** - Display only available or borrowed books (recursive)
10. ✅ **Sort books** - Sort by title, author, or year
11. ✅ **Export a report** - Generate a complete text report

### System Features
12. ✅ **Auto-save** - Save to a text file
13. ✅ **Auto-load** - Load on startup

---

## 🔧 Compilation and Execution

### Compile
```bash
gcc bibliotheque_enhanced.c -o bibliotheque
```

### Run
```bash
./bibliotheque
```

---

## 📁 Project Structure

```
.
├── bibliotheque_enhanced.c         # Main source code
├── bibliotheque.txt                # Save file (generated)
├── rapport_bibliotheque.txt        # Exported report (generated)
├── NOUVELLES_FONCTIONNALITES.md    # New features documentation
├── COMPARAISON.md                  # Before/After comparison
├── SCENARIO_DEMONSTRATION.md       # Presentation guide
└── README.md                       # This file
```

---

## 💻 C Concepts Used

### ✅ Structures (struct)
- `Livre` - Structure to store book information
- `Bibliotheque` - Structure containing an array of books

### ✅ Pointers
- Pass by reference in all modification functions
- Efficient structure manipulation
- Direct data access without copies

### ✅ Recursion (4 recursive functions!)
1. `afficherLivresRecursif()` - Recursive display
2. `compterDisponiblesRecursif()` - Recursive counting with return
3. `compterEmpruntesRecursif()` - Recursive counting with condition
4. `afficherLivresFiltresRecursif()` - Conditional recursive display

### ✅ Text Files
- Data saving
- Automatic loading
- Formatted report export

### ✅ Arrays
- Book storage
- Manipulation (sorting, deletion with shift)

### ✅ Strings
- Manipulation with `strcpy`, `strcmp`, `strstr`
- Validation and search
- Lowercase conversion

### ✅ Functions
- Modular organization (21 functions)
- Separation of concerns
- Reusable code

---

## 🎓 Educational Points

### Mastery Demonstration

#### Recursion - Advanced Level
The project doesn't settle for simple display recursion. It demonstrates several uses:
- **Display** - Simple traversal
- **Counting** - Result accumulation
- **Filtering** - Recursion with conditions

#### Array Manipulation
- Adding elements
- Deletion with shift
- Sorting (bubble sort algorithm)
- Traversal and search

#### File Management
- Formatted reading and writing
- Error handling
- Multiple files (data + reports)

---

## 📊 Code Statistics

- **Lines of code:** ~820
- **Functions:** 21
- **Recursive functions:** 4
- **Structures:** 2
- **Menu options:** 12

---

## 🔍 Usage Examples

### Add a book
```
Option: 1
Title: The Little Prince
Author: Antoine de Saint-Exupéry
Year: 1943
→ Book successfully added! (ID: 1)
```

### Search
```
Option: 2
Search: "prince"
→ Finds "The Little Prince"
```

### Statistics
```
Option: 8
→ Total number of books : 4
→ Available books       : 3 (75.0%)
→ Borrowed books        : 1 (25.0%)
```

### Filter
```
Option: 9
Choice: 1 (Available)
→ Displays only available books
```

### Sort
```
Option: 10
Choice: 3 (By year)
→ Books sorted from 1862 to 1997
```

---

## ✨ Project Strengths

1. **Complete** - Covers all aspects of library management
2. **Mastered Concepts** - Varied and appropriate usage
3. **Intelligent Recursion** - Not forced, but well integrated
4. **Clean Code** - Easy to read and understand
5. **Robust** - Error handling and validation
6. **Extensible** - Structure allows easy addition of functions
7. **Professional** - Report export, statistics

---

## 🆚 Comparison: Original vs Enhanced

| Aspect | Original | Enhanced |
|--------|----------|----------|
| Functions | 13 | 21 |
| Menu | 6 options | 12 options |
| Recursion | 1 function | 4 functions |
| Files | 1 | 2 |

---

## 📝 Requirements Validation

### Project Requirements
- ✅ Written in C
- ✅ Easy to understand
- ✅ Easy to present
- ✅ Uses ALL required concepts:
  - ✅ Arrays and strings
  - ✅ Functions
  - ✅ Recursive functions (4 functions!)
  - ✅ Custom types (struct)
  - ✅ Pointers
  - ✅ Text files

---

## 🏆 Conclusion

This project demonstrates complete mastery of required C concepts with:
- A functional and complete system
- Varied use of recursion
- Professional code organization
- Advanced features

---
