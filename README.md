# ⚙️ CPP Modules — Object-Oriented Programming in C++

> A series of 10 modules covering C++ fundamentals through advanced OOP and STL.

![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen?style=flat-square)
![CPP](https://img.shields.io/badge/Circle_2-In_Progress-orange?style=flat-square)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![School](https://img.shields.io/badge/School-42-000000?style=flat-square)

---

## 📌 Overview

The C++ modules at 42 are a progressive series of exercises designed to teach C++ from the ground up — from basic syntax to advanced concepts like templates, STL, and design patterns. All code is written in **C++98** standard.

---

## 📚 Modules Overview

| Module | Topics | Score |
|--------|--------|-------|
| **CPP00** | Namespaces, classes, member functions, stdio streams, initialization lists | 80% |
| **CPP01** | Memory allocation, references, pointers to members, file streams | 90% |
| **CPP02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | 100% |
| **CPP03** | Inheritance, base/derived classes | 100% |
| **CPP04** | Subtype polymorphism, abstract classes, interfaces, virtual functions | 100% |
| **CPP05** | Repetition and exceptions — try/catch, custom exception classes | In Progress |
| **CPP06** | C++ casts — `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast` | In Progress |
| **CPP07** | Templates — function templates, class templates | In Progress |
| **CPP08** | Templated containers, iterators, algorithms — STL | In Progress |
| **CPP09** | STL containers in practice — `std::map`, `std::stack`, `std::vector` | In Progress |

---

## 🚀 Usage

Each module is a separate directory with individual exercises:

```bash
git clone https://github.com/Fazejli/cpp-modules.git
cd cpp-modules/cpp00/ex00
make
./megaphone "hello world"
```

---

## 📁 Project Structure

```
cpp-modules/
├── Module_00/
│   ├── ex00/   # Megaphone
│   ├── ex01/   # My Awesome PhoneBook
│   └── ex02/   # The Job Of Your Dreams
├── Module_01/
│   ├── ex00/   # BraiiiiiiinnnzzzZ
│   └── ...
├── Module_02/
...
└── Module_09/
```

---

## 🧠 Key Concepts

**Object-Oriented Programming:**
- Encapsulation, inheritance, polymorphism, abstraction
- Orthodox Canonical Form (default constructor, copy constructor, copy assignment, destructor)
- Abstract classes and pure virtual functions
- Operator overloading

**Advanced C++:**
- Templates and generic programming
- STL containers (`vector`, `map`, `stack`, `list`)
- Iterators and algorithms
- Exception handling
- C++ type casting system

**Relevance to Security:**
- Understanding `reinterpret_cast` and unsafe casts
- Memory model differences between C and C++
- Foundation for reading and auditing C++ codebases
