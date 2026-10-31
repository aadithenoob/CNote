# CNote

A command-line file builder, made in C

## Install

```bash
git clone https://github.com/aadithenoob/CNote
cd CNote
make
```
## Usage

### `./cnote <flag> <filepath>`

### Flags

1. `-c` or `--create`: Creates a file at the provided file path with the entered content.

**Example:**

```bash
$ ./cnote -c example.txt
Enter content (type 'END' to finish):

Hey! This is an example.
END

Note created.

$ cat example.txt                                                    
Hey! This is an example.

$ 
```

2. `-h` or `--help`: Displayes help text and exits.

# License

MIT
