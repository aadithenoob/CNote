# CNote

A command-line file builder written in C.

## Installation

```bash
git clone [https://github.com/aadithenoob/CNote](https://github.com/aadithenoob/CNote)
cd CNote
make
```

## Usage

```bash
./cnote <flag> <filepath>
```

## Flags

1. **`-c`**, **`--create`**: Creates a file at the specified path and populates it with interactive input.
2. **`-h`**, **`--help`**: Displays help text and exits.

### Example

```bash
$ ./cnote -c example.txt
Enter content (type 'END' to finish):
Hey! This is an example.
END

Note created.

$ cat example.txt
Hey! This is an example.
```

## License

MIT
