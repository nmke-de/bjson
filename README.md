# Bjson

**Bjson** is a tiny C program which reads JSON from stdin and prints more formatted JSON. It is intended to be used in conjunction with pipes.

## But why?

JSON is a file format intended to be easily understandable both by computer and humans. Unfortunately, a lot of generated JSON files nowadays are quenched into a single line, which admittedly makes usage on the computer side easier, but on the human side more difficult.

Bjson will make these one-line JSON files humanly readable.

## How do you pronounce Bjson?

There is no canonical pronounciation.

## Build Dependencies

- C compiler
- libc

## Build

Coming soon™.

## Usage

`cat input.json | bjson > output.json`
