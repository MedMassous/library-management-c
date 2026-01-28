# 📚 Library Management System

A comprehensive library management system developed in C, demonstrating advanced programming concepts including recursion, pointers, file handling, and data structures.

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

## 🎯 Overview

This project implements a full-featured library management system that allows you to manage a book collection with operations including adding, searching, borrowing, modifying, deleting, generating statistics, and exporting reports. Built as an educational project to demonstrate mastery of fundamental C programming concepts.

## ✨ Features

### Core Functionality
- **📖 Add Books** - Add new books to the library collection
- **🔍 Search** - Search by title or author with partial matching
- **📋 Display All** - View complete library with recursive traversal
- **📤 Borrow Books** - Mark books as borrowed with tracking
- **📥 Return Books** - Mark borrowed books as available

### Advanced Operations
- **🗑️ Delete Books** - Remove books from the collection
- **✏️ Modify Books** - Update book information
- **📊 Statistics** - Comprehensive overview with recursive counting
- **🔎 Filter Books** - Display only available or borrowed books
- **🔄 Sort Books** - Sort by title, author, or publication year
- **📄 Export Reports** - Generate formatted text reports

### System Features
- **💾 Auto-save** - Automatic data persistence to file
- **🔄 Auto-load** - Load existing data on startup
- **⚡ Error Handling** - Robust input validation and error management

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Unix-like environment (Linux, macOS) or Windows with MinGW

### Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/library-management-system.git
cd library-management-system
```

2. Compile the program:
```bash
gcc bibliotheque_enhanced.c -o bibliotheque
```

3. Run the application:
```bash
./bibliotheque
```

## 📖 Usage

### Adding a Book
```
Select option: 1
Enter title: The Little Prince
Enter author: Antoine de Saint-Exupéry
Enter year: 1943
✓ Book successfully added! (ID: 1)
```

### Searching for Books
```
Select option: 2
Enter search term: "prince"
→ Found: The Little Prince by Antoine de Saint-Exupéry (1943)
```

### Viewing Statistics
```
Select option: 8
→ Total books: 4
→ Available: 3 (75.0%)
→ Borrowed: 1 (25.0%)
```

### Filtering Books
```
Select option: 9
Choose filter: 1 (Available only)
→ Displays all available books
```

## 🏗️ Project Structure

```
library-management-system/
├── bibliotheque_enhanced.c         # Main source code
├── bibliotheque.txt                # Data file (auto-generated)
├── rapport_bibliotheque.txt        # Export reports (auto-generated)
├── docs/
│   ├── NOUVELLES_FONCTIONNALITES.md
│   ├── COMPARAISON.md
│   └── SCENARIO_DEMONSTRATION.md
└── README.md
```

## 💻 Technical Implementation

### Data Structures
```c
typedef struct {
    int id;
    char titre[100];
    char auteur[100];
    int annee;
    int estEmprunte;
} Livre;

typedef struct {
    Livre livres[MAX_LIVRES];
    int nombre;
} Bibliotheque;
```

### Key Concepts Demonstrated

#### ✅ Recursion (4 Functions)
- `afficherLivresRecursif()` - Recursive display traversal
- `compterDisponiblesRecursif()` - Recursive counting with return value
- `compterEmpruntesRecursif()` - Conditional recursive counting
- `afficherLivresFiltresRecursif()` - Filtered recursive display

#### ✅ Pointers
- Pass-by-reference for efficient structure manipulation
- Direct data access without copying

#### ✅ File I/O
- Persistent data storage
- Formatted report generation
- Error handling

#### ✅ String Manipulation
- Using `strcpy`, `strcmp`, `strstr`
- Case-insensitive search
- Input validation

#### ✅ Arrays
- Dynamic book storage
- Sorting algorithms (bubble sort)
- Element deletion with shifting

## 📊 Code Statistics

- **Lines of Code:** ~820
- **Total Functions:** 21
- **Recursive Functions:** 4
- **Data Structures:** 2
- **Menu Options:** 12

## 🎓 Educational Value

This project demonstrates:
- **Advanced Recursion** - Multiple practical applications beyond simple examples
- **Memory Management** - Efficient use of pointers and structures
- **File Handling** - Complete data persistence implementation
- **Algorithm Implementation** - Sorting and searching algorithms
- **Code Organization** - Modular design with separated concerns
- **Error Handling** - Robust input validation and edge case management

## 🔄 Evolution

| Aspect | Original | Enhanced |
|--------|----------|----------|
| Functions | 13 | 21 (+62%) |
| Menu Options | 6 | 12 (+100%) |
| Recursive Functions | 1 | 4 (+300%) |
| File Operations | 1 | 2 (+100%) |

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👤 Author

**Mohamed Massous**
- GitHub: [@MedMassous](https://github.com/MedMassous)

## 🙏 Acknowledgments

- Developed as a coursework project to demonstrate C programming proficiency
- Implements best practices in data structure design and algorithm implementation
- Special focus on recursive problem-solving techniques

## 📞 Support

If you have any questions or run into issues, please open an issue on GitHub.

---

**⭐ Star this repository if you find it helpful!**
