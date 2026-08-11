# Algorithm Lab

A personal study project implementing classic **data structures and algorithms in pure C** (C99/C11), with no third-party dependencies. Each module is kept small and self-contained so the implementations are easy to read and trace step by step.

> **Status: active development** — core modules are done, others are in progress or planned. See [Roadmap](#roadmap).

## Modules

| Module | File | Status | Highlights |
|---|---|---|---|
| Arrays | `src/array.c` | ✅ Done | traverse / insert / delete / search |
| Searching | `src/search.c` | ✅ Done | linear search, binary search |
| Sorting | `src/sort.c` | ✅ Done | bubble / selection / insertion / merge / quick sort, random array generator |
| Classic algorithms | `src/others.c` | ✅ Done | Euclidean algorithm, Tower of Hanoi, fast exponentiation, closest pair of points |
| Linked lists | `src/linked_list.c` | ✅ Done | singly (SLL), doubly (DLL), circular (CLL), circular doubly (CDLL) linked lists — create / insert / delete / traverse / destroy |
| Stack | `src/stack.c` | ✅ Done | sequential stack + linked stack |
| Queue | `src/queue.c` | 🔶 In progress | sequence queue partially done; circular & priority queue planned |
| Tree | `src/tree.c` | ⏳ Not started | — |

## Repository Structure

```
algorithm_lab/
├── include/       # Public headers (one per module)
├── src/           # Implementations
├── test/          # Test entry point (test.c)
├── build.bat      # One-click build & run (Windows)
├── commands.txt   # Build/run command cheatsheet
└── README.md
```

## Build & Run

### Windows (MinGW)

One-click build and run:

```bat
build.bat
```

Or manually:

```bat
gcc -Wall -g -I include test\test.c src\*.c -o test.exe
test.exe
```

### Linux / macOS

```bash
gcc -Wall -g -I include test/test.c src/*.c -lm -o test
./test
```

> `-lm` links the math library, required because `others.c` uses `sqrt()`.

### Per-module builds

Build only what you are working on to keep compile output focused:

```bash
gcc -Wall -g -I include test/test.c src/linked_list.c -o test.exe
gcc -Wall -g -I include test/test.c src/stack.c -o test.exe
```

## Module Notes

- **Arrays** — fixed-capacity operations on an `int` array; insert/delete report failure via return codes.
- **Searching** — `normal_search` returns the 0-based index or `-1`; `binary_search` requires a sorted array.
- **Sorting** — all in-place, ascending. `merge_sort` / `quick_sort` operate on index ranges (`left`, `right`).
- **Classic algorithms** — `Euclid` (GCD), `Hanoi` (recursive, prints moves), `power` (fast exponentiation by squaring), `MinDistance` (divide-and-conquer closest pair of points).
- **Linked lists** — four flavors, each with create / insert (head, tail, after) / delete (head, tail, by value) / traverse / destroy.
- **Stack** — sequential stack (array-backed, fixed capacity) and linked stack (dynamic); both offer push / pop / top / traverse / destroy.
- **Queue** — sequence queue entry (`seq_queue_create` / `is_empty` / `is_full`) implemented so far.

## Roadmap

- [x] Arrays
- [x] Searching
- [x] Sorting
- [x] Classic algorithms (Euclid, Hanoi, fast power, closest pair)
- [x] Linked lists (SLL / DLL / CLL / CDLL)
- [x] Stack (sequential + linked)
- [ ] Queue — circular queue, priority queue (types already declared in `queue.h`)
- [ ] Tree — BST, AVL, heap (`tree.c` is an empty placeholder)
- [ ] Unit tests for each module (currently `test/test.c` is a minimal entry point)
- [ ] More classic algorithms (graph traversal, dynamic programming, etc.)

## Coding Conventions

- C99/C11, no non-standard extensions
- 4-space indentation, Allman braces
- `snake_case` for functions and variables
- Public APIs documented in headers; `malloc` results always checked

## License

Not specified yet — this is a personal learning project. If you intend to reuse any part of it, please reach out to the author first.
